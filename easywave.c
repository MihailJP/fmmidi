#include "easywave.h"
#include <windows.h>

#include <string.h>

static HWAVEOUT hWaveOut;
static CRITICAL_SECTION cs;

struct MYWAVEHDR{
    WAVEHDR wavehdr;
    struct MYWAVEHDR* next;
};

static struct MYWAVEHDR* doneWaveHdrs;
static CRITICAL_SECTION cs;
static int waitingBytes;

static void CALLBACK easywave_callback(HWAVEOUT hWaveOut, UINT msg, DWORD instance, DWORD param1, DWORD param2)
{
    if(msg == WOM_DONE){
        struct MYWAVEHDR* p = (struct MYWAVEHDR*)param1;
        EnterCriticalSection(&cs);
        p->next = doneWaveHdrs;
        doneWaveHdrs = p;
        LeaveCriticalSection(&cs);
    }
}

static void clean_unprepares(void)
{
    EnterCriticalSection(&cs);
    while(doneWaveHdrs){
        struct MYWAVEHDR* p = doneWaveHdrs;
        doneWaveHdrs = p->next;
        waitingBytes -= p->wavehdr.dwBufferLength;
        waveOutUnprepareHeader(hWaveOut, &p->wavehdr, sizeof(WAVEHDR));
        free(p->wavehdr.lpData);
        free(p);
    }
    LeaveCriticalSection(&cs);
}

void easywave_initialize(int frequency, int device)
{
    WAVEFORMATEX wfx;

    easywave_finalize();

    memset(&wfx, 0, sizeof(wfx));
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 2;
    wfx.nSamplesPerSec = frequency;
    wfx.wBitsPerSample = 16;
    wfx.nBlockAlign = wfx.nChannels * wfx.wBitsPerSample / 8;
    wfx.nAvgBytesPerSec =  wfx.nBlockAlign * wfx.nSamplesPerSec;
    wfx.cbSize = 0;
    if(waveOutOpen(&hWaveOut, device, &wfx, (DWORD)easywave_callback, 0, CALLBACK_FUNCTION) != MMSYSERR_NOERROR){
        hWaveOut = NULL;
    }else{
        waveOutRestart(hWaveOut);
        InitializeCriticalSection(&cs);
    }
}

void easywave_finalize(void)
{
    if(hWaveOut){
        waveOutPause(hWaveOut);
        waveOutReset(hWaveOut);
        clean_unprepares();
        waveOutClose(hWaveOut);
        hWaveOut = NULL;
        DeleteCriticalSection(&cs);
    }
}

void easywave_output(const short* data, size_t n)
{
    if(hWaveOut){
        WAVEHDR* p = malloc(sizeof(struct MYWAVEHDR));
        memset(p, 0, sizeof(WAVEHDR));
        p->lpData = malloc(sizeof(short) * 2 * n);
        if(!p->lpData){
            free(p);
        }else{
            memcpy(p->lpData, data, sizeof(short) * 2 * n);
            p->dwBufferLength = p->dwBytesRecorded = sizeof(short) * 2 * n;
            waveOutPrepareHeader(hWaveOut, p, sizeof(WAVEHDR));
            if(waveOutWrite(hWaveOut, p, sizeof(WAVEHDR)) == MMSYSERR_NOERROR){
                waitingBytes += p->dwBufferLength;
            }else{
                waveOutUnprepareHeader(hWaveOut, p, sizeof(WAVEHDR));
                free(p->lpData);
                free(p);
            }
        }
        clean_unprepares();
    }
}

void easywave_flush(void)
{
    waveOutReset(hWaveOut);
    clean_unprepares();
}

int easywave_pending_samples(void)
{
    clean_unprepares();
    return waitingBytes / sizeof(short) / 2;
}

