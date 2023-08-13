//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#include "midisynth.hpp"
#include "sequencer.hpp"
#include "easywave.h"
#include "wavwrite.hpp"
#include "filter.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <deque>
#include <map>
//---------------------------------------------------------------------------
#undef feof
#undef getc
namespace std{
    using ::__strcmp__;
}
//---------------------------------------------------------------------------
const char* program_names[] = {
    "グランドピアノ",
    "ブライトピアノ",
    "エレクトリックグランドピアノ",
    "ホンキートンク",
    "エレクトリックピアノ1",
    "エレクトリックピアノ2",
    "ハープシコード",
    "クラビ",
    "チェレスタ",
    "鉄琴",
    "オルゴール",
    "ビブラフォン",
    "マリンバ",
    "木琴",
    "チューブラーベル",
    "ダルシマー",
    "ドローバーオルガン",
    "パーカッシブオルガン",
    "ロックオルガン",
    "パイプオルガン",
    "リードオルガン",
    "アコーディオン",
    "ハーモニカ",
    "バンドネオン",
    "ナイロン弦ギター",
    "スチール弦ギター",
    "エレキギター/ジャズ",
    "エレキギター/クリーン",
    "エレキギター/ミュート",
    "エレキギター/オーバードライブ",
    "エレキギター/ディストーション",
    "ギターハーモニクス",
    "ベース",
    "エレキベース/フィンガー",
    "エレキベース/ピック",
    "フレットレスベース",
    "スラップベース1",
    "スラップベース2",
    "シンセベース1",
    "シンセベース2",
    "バイオリン",
    "ビオラ",
    "チェロ",
    "コントラバス",
    "トレモロストリングス",
    "ピチカート",
    "ハープ",
    "ティンパニ",
    "ストリングス",
    "スローストリングス",
    "シンセストリングス1",
    "シンセストリングス2",
    "クワイア",
    "ボイス",
    "シンセボイス",
    "オーケストラヒット",
    "トランペット",
    "トロンボーン",
    "チューバ",
    "トランペット/ミュート",
    "ホルン",
    "ブラス",
    "シンセブラス1",
    "シンセブラス2",
    "ソプラノサックス",
    "アルトサックス",
    "テナーサックス",
    "バリトンサックス",
    "オーボエ",
    "イングリッシュホルン",
    "バスーン",
    "クラリネット",
    "ピッコロ",
    "フルート",
    "リコーダー",
    "パンフルート",
    "ボトルブロー",
    "尺八",
    "ホイッスル",
    "オカリナ",
    "矩形波",
    "三角波",
    "カリオペ",
    "チファー",
    "チャラング",
    "ソロボックス",
    "フィフスリード",
    "ベース＆リード",
    "ファンタジア",
    "ウォームパッド",
    "ポリシンセ",
    "スペースクワイア",
    "グラスハーモニカ",
    "メタリックパッド",
    "ヘイローパッド",
    "スイープパッド",
    "アイスレイン",
    "サウンドトラック",
    "クリスタル",
    "アトモスフィア",
    "ブライトネス",
    "ゴブリン",
    "エコードロップ",
    "サイエンスフィクション",
    "シタール",
    "バンジョー",
    "三味線",
    "琴",
    "カリンバ",
    "バグパイプ",
    "フィードル",
    "シャナイ",
    "ティンクルベル",
    "アゴゴ",
    "スチールドラム",
    "ウッドブロック",
    "太鼓",
    "メロディックタム",
    "シンセドラム",
    "リバースシンバル",
    "ギターフレッドノイズ",
    "ブレスノイズ",
    "波",
    "鳥のさえずり",
    "電話のベル",
    "ヘリコプター",
    "拍手",
    "銃声",
};
//---------------------------------------------------------------------------
namespace{
    #define NUM_PORTS 4
    midisynth::fm_note_factory note_factory;
    midisynth::synthesizer synthesizer0(&note_factory);
    midisynth::synthesizer synthesizer1(&note_factory);
    midisynth::synthesizer synthesizer2(&note_factory);
    midisynth::synthesizer synthesizer3(&note_factory);
    midisynth::synthesizer* synthesizers[NUM_PORTS] = {
        &synthesizer0, &synthesizer1, &synthesizer2, &synthesizer3
    };
    midisequencer::sequencer sequencer;

    struct MIDIIN_MAPPER{
        HMIDIIN hMidiIn;
        int channel_map[16];
        int sysex_port;
    };
    std::vector<MIDIIN_MAPPER> midiin_mapper;

    std::auto_ptr<wav_file_writer> wav_writer;

    HWND hwnd;
    CRITICAL_SECTION cs;
    UINT waveout_device = WAVE_MAPPER;
    bool waveout_mute;
    int sampling_rate = 44100;
    DWORD tempo = 500000;
    std::string songtext;
    std::size_t songptr;
    std::size_t songprev;
    int note_count;

    bool paint_note[16 * NUM_PORTS][128];
}
//---------------------------------------------------------------------------
namespace{
    int solo_channel = -1;
    bool mute_channels[16 * NUM_PORTS];

    void update_mute()
    {
        if(solo_channel != -1){
            for(int i = 0; i < 16 * NUM_PORTS; ++i){
                int port = i / 16;
                int ch = i % 16;
                synthesizers[port]->get_channel(ch)->set_mute(i != solo_channel);
            }
        }else{
            for(int i = 0; i < 16 * NUM_PORTS; ++i){
                int port = i / 16;
                int ch = i % 16;
                synthesizers[port]->get_channel(ch)->set_mute(mute_channels[i]);
            }
        }
    }
}
//---------------------------------------------------------------------------
void update_skin();
void update_skin(const char* format, int param1 = 0, int param2 = 0);
//---------------------------------------------------------------------------
static void midi_message(int port, DWORD msg)
{
    if(port >= 0 && port < NUM_PORTS){
        EnterCriticalSection(&cs);
        synthesizers[port]->midi_event(msg & 0xFF, (msg >> 8) & 0xFF, (msg >> 16) & 0xFF);
        LeaveCriticalSection(&cs);

        int channel = msg & 0x0F;
        int chport = channel + port * 16;
        if((msg & 0xF0) == 0x80){
            int note = (msg >> 8) & 0x7F;
            if(paint_note[chport][note]){
                paint_note[chport][note] = false;
                update_skin("ch%d-key%d", chport + 1, note);
            }
        }else if((msg & 0xF0) == 0x90){
            int note = (msg >> 8) & 0x7F;
            int velocity = (msg >> 16) & 0x7F;
            if(velocity){
                EnterCriticalSection(&cs);
                bool mono = synthesizers[port]->get_channel(channel)->get_mono_mode();
                LeaveCriticalSection(&cs);
                if(mono){
                    for(int i = 0; i < 128; ++i){
                        if(paint_note[chport]){
                            paint_note[chport][note] = false;
                            update_skin("ch%d-key%d", chport + 1, note);
                        }
                    }
                }
            }
            bool x = velocity > 0;
            if(paint_note[chport][note] != x){
                paint_note[chport][note] = x;
                update_skin("ch%d-key%d", chport + 1, note);
            }
        }else if((msg & 0xF0) == 0xC0){
            update_skin("ch%d-program", chport + 1);
        }else if((msg & 0xF0) == 0xD0){
            update_skin("ch%d-channelpressure", chport + 1);
        }else if((msg & 0xF0) == 0xE0){
            update_skin("ch%d-pitchbend", chport + 1);
        }else{
            switch(msg & 0xFFF0){
            case 0x01B0:
            case 0x21B0:
                update_skin("ch%d-modulationdepth", chport + 1);
                break;
            case 0x07B0:
            case 0x27B0:
                update_skin("ch%d-volume", chport + 1);
                break;
            case 0x0AB0:
            case 0x2AB0:
                update_skin("ch%d-pan", chport + 1);
                break;
            case 0x0BB0:
            case 0x2BB0:
                update_skin("ch%d-expression", chport + 1);
                break;
            case 0x40B0:
                update_skin("ch%d-damper", chport + 1);
                break;
            case 0x42B0:
                update_skin("ch%d-sostenute", chport + 1);
                break;
            case 0x45B0:
                update_skin("ch%d-freeze", chport + 1);
                break;
            case 0x06B0:
            case 0x26B0:
            case 0x60B0:
            case 0x61B0:
                switch(synthesizers[port]->get_channel(channel)->get_RPN()){
                case 0x0000:
                    update_skin("ch%d-pitchbendsensitivity", chport + 1);
                    break;
                case 0x0001:
                    update_skin("ch%d-finetuning", chport + 1);
                    break;
                case 0x0002:
                    update_skin("ch%d-coarsetuning", chport + 1);
                    break;
                case 0x0005:
                    update_skin("ch%d-modulationdepthrange", chport + 1);
                    break;
                }
                break;
            case 0x7EB0:
            case 0x7FB0:
                update_skin("ch%d-mono", chport + 1);
                /* FALL THROUGH */
            case 0x78B0:
            case 0x79B0:
            case 0x7BB0:
            case 0x7CB0:
            case 0x7DB0:
                memset(paint_note[chport], 0, sizeof(paint_note[chport]));
                for(int i = 0; i < 128; ++i){
                    update_skin("ch%d-key%d", chport + 1, i);
                }
                break;
            }
        }
    }
}
static void midi_sysex(int port, const void* data, std::size_t size)
{
    if(port >= 0 && port < NUM_PORTS){
        EnterCriticalSection(&cs);
        synthesizers[port]->sysex_message(data, size);
        LeaveCriticalSection(&cs);

        const unsigned char* p = reinterpret_cast<const unsigned char*>(data);
        if(size == 6 && std::memcmp(p, "\xF0\x7E\x7F\x09\x01\xF7", 6) == 0){
            /* GM system on */
            update_skin();
        }else if(size == 6 && std::memcmp(p, "\xF0\x7E\x7F\x09\x02\xF7", 6) == 0){
            /* GM system off */
            update_skin();
        }else if(size == 6 && std::memcmp(p, "\xF0\x7E\x7F\x09\x03\xF7", 6) == 0){
            /* GM2 system on */
            update_skin();
        }else if(size == 11 && std::memcmp(p, "\xF0\x41", 2) == 0 && std::memcmp(p + 3, "\x42\x12\x40\x00\x7F\x00\x41\xF7", 8) == 0){
            /* GS reset */
            update_skin();
        }else if(size == 9 && std::memcmp(p, "\xF0\x43", 2) == 0 && (p[2] & 0xF0) == 0x10 && std::memcmp(p + 3, "\x4C\x00\x00\x7E\x00\xF7", 6) == 0){
            /* XG system on */
            update_skin();
        }else if(size == 8 && std::memcmp(p, "\xF0\x7F\x7F\x04\x01", 5) == 0 && p[7] == 0xF7){
            /* master volume */
            update_skin("port%d-mastervolume", port + 1);
        }else if(size == 8 && std::memcmp(p, "\xF0\x7F\x7F\x04\x02", 5) == 0 && p[7] == 0xF7){
            /* master balance */
            update_skin("port%d-masterbalance", port + 1);
        }else if(size == 8 && std::memcmp(p, "\xF0\x7F\x7F\x04\x03", 5) == 0 && p[7] == 0xF7){
            /* master fine tuning */
            update_skin("port%d-masterfinetuning", port + 1);
        }else if(size == 8 && std::memcmp(p, "\xF0\x7F\x7F\x04\x04", 5) == 0 && p[7] == 0xF7){
            /* master coarse tuning */
            update_skin("port%d-mastercoarsetuning", port + 1);
        }else if(size == 11 && std::memcmp(p, "\xF0\x41", 2) == 0 && (p[2] & 0xF0) == 0x10 && std::memcmp(p + 3, "\x42\x12\x40", 3) == 0 && (p[6] & 0xF0) == 0x10 && p[7] == 0x15 && p[10] == 0xF7){
            /* use for rhythm part */
            int channel = p[6] & 0x0F;
            update_skin("ch%d-program", port * 16 + channel + 1);
        }
    }
}
static void midi_meta_event(int type, const void* data, size_t size)
{
    const unsigned char* p = (const unsigned char*)data;
    switch(type){
    case 0x05:
        EnterCriticalSection(&cs);
        songprev = songptr;
        songptr += size;
        LeaveCriticalSection(&cs);
        update_skin("song");
        break;
    case 0x51:
        EnterCriticalSection(&cs);
        tempo = (p[0] << 16) | (p[1] << 8) | p[2];
        LeaveCriticalSection(&cs);
        update_skin("bpm");
        break;
    default:
        break;
    }
}
static void midi_reset()
{
    EnterCriticalSection(&cs);
    for(int i = 0; i < NUM_PORTS; ++i){
        synthesizers[i]->reset();
    }
    memset(paint_note, 0, sizeof(paint_note));
    note_count = 0;
    tempo = 500000;
    solo_channel = -1;
    memset(mute_channels, 0, sizeof(mute_channels));
    LeaveCriticalSection(&cs);
    update_skin();
}
//---------------------------------------------------------------------------
class sequencer_output: public midisequencer::output{
public:
    void midi_message(int port, DWORD message)
    {
        ::midi_message(port, message);
    }
    void sysex_message(int port, const void* data, std::size_t size)
    {
        ::midi_sysex(port, data, size);
    }
    void meta_event(int type, const void* data, std::size_t size)
    {
        ::midi_meta_event(type, data, size);
    }
    void reset()
    {
        ::midi_reset();
    }
}sequencer_output;
class sequencer_output_mute: public sequencer_output{
public:
    void midi_message(int port, DWORD message);
}sequencer_output_mute;
void sequencer_output_mute::midi_message(int port, DWORD message)
{
    if((message & 0xF0) == 0x90){
    }else{
        ::midi_message(port, message);
    }
}
//---------------------------------------------------------------------------
namespace{
    DWORD last_timer_callback;
    DWORD sequencer_start_time;
    DWORD last_heavy_time;
    std::vector<long> mixing_buffer(20000);
    std::vector<short> output_buffer(20000);
    long last_512samples[1024];
    bool last_512samples_updated;
    bool no_spectrum;
    bool output_silence;
    bool equalizer_enabled;
    filter::finite_impulse_response equalizer_left;
    filter::finite_impulse_response equalizer_right;


    void timer_callback()
    {
        EnterCriticalSection(&cs);
        DWORD t = timeGetTime();
        if(t != last_timer_callback){
            if(t - last_timer_callback > 50){
                SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
                last_heavy_time = t = timeGetTime();
                if(sequencer_start_time){
                    sequencer_start_time += t - last_timer_callback;
                    if(sequencer_start_time == 0){
                        sequencer_start_time = 1;
                    }
                    if(static_cast<long>(t - sequencer_start_time) < 0){
                        sequencer_start_time = t;
                    }
                }
            }else if(t > last_timer_callback){
                if(sequencer_start_time){
                    sequencer.play((t - sequencer_start_time) / 1000.0, &sequencer_output);
                }
                std::size_t samples = static_cast<std::size_t>(
                                        static_cast<unsigned __int64>(t) * sampling_rate / 1000 -
                                        static_cast<unsigned __int64>(last_timer_callback) * sampling_rate / 1000
                                      );
                std::size_t n = samples * 2;
                if(mixing_buffer.size() < n){
                    mixing_buffer.resize(n);
                }
                std::memset(&mixing_buffer[0], 0, sizeof(long) * n);
                int num_notes = 0;
                for(int i = 0; i < NUM_PORTS; ++i){
                    num_notes += synthesizers[i]->synthesize_mixing(&mixing_buffer[0], samples, sampling_rate);
                }
                if(num_notes || (wav_writer.get() && wav_writer->get_written_bytes() > 0) || (equalizer_enabled && !no_spectrum) || output_silence){
                    if(equalizer_enabled){
                        equalizer_left.apply(&mixing_buffer[0], &mixing_buffer[0], samples, sizeof(long[2]));
                        equalizer_right.apply(&mixing_buffer[1], &mixing_buffer[1], samples, sizeof(long[2]));
                    }
                    if(output_buffer.size() < n){
                        output_buffer.resize(n);
                    }
                    int maxamp = 32767;
                    for(std::size_t i = 0; i < n; ++i){
                        int x = mixing_buffer[i];
                        if(x < -32767){
                            output_buffer[i] = -32767;
                            maxamp = std::max(maxamp, -x);
                        }else if(x > 32767){
                            output_buffer[i] = 32767;
                            maxamp = std::max(maxamp, x);
                        }else{
                            output_buffer[i] = static_cast<short>(x);
                        }
                    }
                    if(!waveout_mute){
                        easywave_output(&output_buffer[0], samples);
                    }
                    if(maxamp > 32767){
                        for(int i = 0; i < NUM_PORTS; ++i){
                            synthesizers[i]->set_main_volume(synthesizers[i]->get_main_volume() * 32767 / maxamp);
                        }
                    }
                    if(wav_writer.get()){
                        try{
                            wav_writer->write(&output_buffer[0], samples);
                        }catch(std::runtime_error& e){
                            try{
                                wav_writer->close();
                            }catch(...){
                            }
                            wav_writer.reset();
                            PostMessage(hwnd, WM_WAVWRITEERROR, 0, 0);
                        }
                    }
                    if(num_notes){
                        no_spectrum = false;
                    }
                }
                if(note_count != num_notes){
                    note_count = num_notes;
                    update_skin("notecount");
                }
                int m = samples * 2;
                if(m >= 1024){
                    std::memcpy(&last_512samples[0], &mixing_buffer[m - 1024], sizeof(long) * 1024);
                }else{
                    std::memmove(&last_512samples[0], &last_512samples[m], sizeof(long) * (1024 - m));
                    std::memcpy(&last_512samples[1024 - m], &mixing_buffer[0], sizeof(long) * m);
                }
                last_512samples_updated = true;
            }
            if(t - last_heavy_time > 5000){
                last_heavy_time = t - 5000;
                SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
            }
        }
        last_timer_callback = t;
        LeaveCriticalSection(&cs);
    }

    HANDLE hThread;
    bool thread_termination_flag;
    DWORD CALLBACK thread_entry_point(void*)
    {
        SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
        while(!thread_termination_flag){
            timer_callback();
            Sleep(1);
        }
        return 0;
    }
}
//---------------------------------------------------------------------------
namespace{
    std::map<double, double> equalizer_gains;
    double equalizer_rate;
    std::size_t equalizer_length;
}
void update_equalizer()
{
    EnterCriticalSection(&cs);
    if(!Form5->CheckEnabled->Checked){
        equalizer_enabled = false;
    }else{
        equalizer_enabled = true;
        std::size_t length = 1 << Form5->FilterLength->Position;
        std::map<double, double> gains;
        gains[ 62.5] = std::pow(10, Form5->G62Hz ->Position / -10.0 / 20);
        gains[  125] = std::pow(10, Form5->G125Hz->Position / -10.0 / 20);
        gains[  250] = std::pow(10, Form5->G250Hz->Position / -10.0 / 20);
        gains[  500] = std::pow(10, Form5->G500Hz->Position / -10.0 / 20);
        gains[ 1000] = std::pow(10, Form5->G1kHz ->Position / -10.0 / 20);
        gains[ 2000] = std::pow(10, Form5->G2kHz ->Position / -10.0 / 20);
        gains[ 4000] = std::pow(10, Form5->G4kHz ->Position / -10.0 / 20);
        gains[ 8000] = std::pow(10, Form5->G8kHz ->Position / -10.0 / 20);
        gains[16000] = std::pow(10, Form5->G16kHz->Position / -10.0 / 20);
        bool updated = false;
        if(equalizer_rate != sampling_rate || equalizer_length != length){
            updated = true;
        }else{
            for(std::map<double, double>::iterator i = gains.begin(); i != gains.end(); ++i){
                if(equalizer_gains[i->first] != i->second){
                    updated = true;
                    break;
                }
            }
        }
        if(updated){
            equalizer_length = length;
            equalizer_gains = gains;
            equalizer_rate = sampling_rate;
            std::vector<double> h(length);
            filter::compute_equalizer_fir(&h[0], length, sampling_rate, gains);
            equalizer_left.set_impulse_response(h);
            equalizer_right.set_impulse_response(h);
        }
    }
    LeaveCriticalSection(&cs);
}
//---------------------------------------------------------------------------
namespace{
    double spectrum_levels[16];
    void update_spectrum_levels()
    {
        if(!last_512samples_updated || no_spectrum){
            return;
        }
        
        std::complex<double> time[512];
        std::complex<double> freq[512];
        
        EnterCriticalSection(&cs);
        no_spectrum = true;
        last_512samples_updated = false;
        for(int i = 0; i < 512; ++i){
            time[i] = (last_512samples[i * 2] + last_512samples[i * 2 + 1]) / 32768.0;
        }
        int rate = sampling_rate;
        LeaveCriticalSection(&cs);

        filter::fft(freq, time, 9);

        static const int freqmap[16] = {
            50, 100, 200, 300, 400, 600, 800, 1000,
            1200, 1600, 2400, 3200, 4800, 6400, 9600, INT_MAX
        };
        for(int i = 0; i < 16; ++i){
            spectrum_levels[i] = 0;
        }
        for(int i = 0; i < 256; ++i){
            int f = rate * i / 512;
            for(int j = 0; j < 16; ++j){
                if(f < freqmap[j]){
                    spectrum_levels[j] = std::max(spectrum_levels[j], abs(freq[i]));
                    break;
                }
            }
        }
        for(int i = 0; i < 16; ++i){
            spectrum_levels[i] = std::min(1.0, std::log10(spectrum_levels[i] + 1) / 2);
            if(spectrum_levels[i] > 0){
                no_spectrum = false;
            }
        }
    }
}
//---------------------------------------------------------------------------
namespace{
    std::auto_ptr<Graphics::TBitmap> bmp_skin_a;
    std::auto_ptr<Graphics::TBitmap> bmp_skin_b;
    
    typedef void (__fastcall *skindef_paint_handler)(TCanvas* canvas, const TRect& rect, int param1, int param2);
    typedef void (__fastcall *skindef_mouse_handler)(float value, TMouseButton button, int param1, int param2);
    
    struct SKINDEF{
        TRect rect;
        int param1;
        int param2;
        skindef_paint_handler paint;
        skindef_mouse_handler mousedown, mousemove, mouseup;
        bool repaint;
        
        SKINDEF(){
            rect = Bounds(0, 0, 0, 0);
            paint = NULL;
            mousedown = mousemove = mouseup = NULL;
        }
    };
    std::map<int, SKINDEF> skindefs;
    bool repaint_skin;

    int compute_skindef_hash(const char* s)
    {
        int hash = 0;
        while(*s){
            hash = hash ^ (hash << 6) ^ static_cast<unsigned char>(*s++);
        }
        return hash;
    }
    inline int compute_skindef_hash(const std::string& s)
    {
        return compute_skindef_hash(s.c_str());
    }

    void define_skin(const char* format, int param1, int param2, skindef_paint_handler paint, skindef_mouse_handler mousedown, skindef_mouse_handler mousemove, skindef_mouse_handler mouseup)
    {
        char name[256];
        std::sprintf(name, format, param1, param2);
        int hash = compute_skindef_hash(name);
        if(hash == 0 || skindefs.find(hash) != skindefs.end()){
            ShowMessage("conflict skindef hash.");
        }
        SKINDEF& def = skindefs[hash];
        def.rect = Bounds(0, 0, 0, 0);
        def.param1 = param1;
        def.param2 = param2;
        def.paint = paint;
        def.mousedown = mousedown;
        def.mousemove = mousemove;
        def.mouseup = mouseup;
    }
    
    void draw_skin(TCanvas* canvas, TRect rect, float value)
    {
        value = std::min(1.0f, std::max(0.0f, value));
        int t = (rect.right + 1 - rect.left) * value + rect.left;
        TRect rect2 = rect;
        rect.right = t;
        rect2.left = t;
        canvas->CopyRect(rect, bmp_skin_b->Canvas, rect);
        canvas->CopyRect(rect2, bmp_skin_a->Canvas, rect2);
    }
    void draw_skin_cz(TCanvas* canvas, TRect rect, float value)
    {
        value = std::min(1.0f, std::max(0.0f, value));
        TRect rect2 = rect;
        TRect rect3 = rect;
        int left = rect.left;
        int right = rect.right + 1;
        if(value < 0.5){
            rect.left = (right - left) * value + left;
            rect.right = (left + right) / 2;
            canvas->CopyRect(rect, bmp_skin_b->Canvas, rect);
            rect2.right = rect.left;
            canvas->CopyRect(rect2, bmp_skin_a->Canvas, rect2);
            rect3.left = rect.right;
            canvas->CopyRect(rect3, bmp_skin_a->Canvas, rect3);
        }else{
            rect.left = (left + right) / 2;
            rect.right = (right - left) * value + left;
            canvas->CopyRect(rect, bmp_skin_b->Canvas, rect);
            rect2.right = rect.left;
            canvas->CopyRect(rect2, bmp_skin_a->Canvas, rect2);
            rect3.left = rect.right;
            canvas->CopyRect(rect3, bmp_skin_a->Canvas, rect3);
        }
    }
    
    void __fastcall skindef_paint_title(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        const std::string& s = sequencer.get_title();
        canvas->CopyRect(rect, bmp_skin_a->Canvas, rect);
        canvas->TextRect(rect, rect.left, rect.top, s.c_str());
    }
    void __fastcall skindef_paint_copyright(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        const std::string& s = sequencer.get_copyright();
        canvas->CopyRect(rect, bmp_skin_a->Canvas, rect);
        canvas->TextRect(rect, rect.left, rect.top, s.c_str());
    }
    void __fastcall skindef_paint_song(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        std::size_t songprev = ::songprev;
        canvas->CopyRect(rect, bmp_skin_a->Canvas, rect);
        canvas->TextRect(rect, rect.left, rect.top, songtext.c_str() + songprev);
    }
    void __fastcall skindef_paint_position(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        float total_time = sequencer.get_total_time();
        float value;
        if(total_time > 0){
            if(!sequencer_start_time){
                value = 1;
            }else{
                value = (timeGetTime() - sequencer_start_time) / 1000.0 / total_time;
            }
        }else{
            value = 0;
        }
        draw_skin(canvas, rect, value);
    }
    void __fastcall skindef_mouse_position(float value, TMouseButton button, int param1, int param2)
    {
        if(sequencer.get_total_time() > 0){
            DWORD t = timeGetTime();
            sequencer_start_time = t - value * sequencer.get_total_time() * 1000.0;
            sequencer.play((t - sequencer_start_time) / 1000.0, &sequencer_output_mute);
        }
    }
    void __fastcall skindef_paint_bpm(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        int bpm = MulDiv(1000000, 60, tempo);
        canvas->CopyRect(rect, bmp_skin_a->Canvas, rect);
        canvas->TextRect(rect, rect.left, rect.top, IntToStr(bpm));
    }
    void __fastcall skindef_paint_notecount(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        int note_count = ::note_count;
        canvas->CopyRect(rect, bmp_skin_a->Canvas, rect);
        canvas->TextRect(rect, rect.left, rect.top, IntToStr(note_count));
    }
    void __fastcall skindef_paint_spectrum(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        update_spectrum_levels();
        float value = spectrum_levels[param1 - 1];
        TRect rect1 = rect;
        TRect rect2 = rect;
        rect1.top = rect1.bottom - (rect1.bottom - rect1.top) * value;
        rect2.bottom = rect1.top;
        canvas->CopyRect(rect1, bmp_skin_b->Canvas, rect1);
        canvas->CopyRect(rect2, bmp_skin_a->Canvas, rect2);
    }
    void __fastcall skindef_paint_systemmode_gm(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool b = synthesizers[param1 - 1]->get_system_mode() == midisynth::system_mode_gm;
        canvas->CopyRect(rect, (b ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_systemmode_gm(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_system_mode(midisynth::system_mode_gm);
        update_skin();
    }
    void __fastcall skindef_paint_systemmode_gm2(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool b = synthesizers[param1 - 1]->get_system_mode() == midisynth::system_mode_gm2;
        canvas->CopyRect(rect, (b ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_systemmode_gm2(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_system_mode(midisynth::system_mode_gm2);
        update_skin();
    }
    void __fastcall skindef_paint_systemmode_gs(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool b = synthesizers[param1 - 1]->get_system_mode() == midisynth::system_mode_gs;
        canvas->CopyRect(rect, (b ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_systemmode_gs(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_system_mode(midisynth::system_mode_gs);
        update_skin();
    }
    void __fastcall skindef_paint_systemmode_xg(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool b = synthesizers[param1 - 1]->get_system_mode() == midisynth::system_mode_xg;
        canvas->CopyRect(rect, (b ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_systemmode_xg(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_system_mode(midisynth::system_mode_xg);
        update_skin();
    }
    void __fastcall skindef_paint_mastervolume(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        int value = synthesizers[param1 - 1]->get_master_volume();
        draw_skin(canvas, rect, value / 16384.0);
    }
    void __fastcall skindef_mouse_mastervolume(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_master_volume(value * 16383);
    }
    void __fastcall skindef_paint_masterbalance(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        int value = synthesizers[param1 - 1]->get_master_balance();
        draw_skin_cz(canvas, rect, value / 16384.0);
    }
    void __fastcall skindef_mouse_masterbalance(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_master_balance(value * 16383);
    }
    void __fastcall skindef_paint_masterfinetuning(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        int value = synthesizers[param1 - 1]->get_master_fine_tuning();
        draw_skin_cz(canvas, rect, value / 16384.0);
    }
    void __fastcall skindef_mouse_masterfinetuning(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_master_fine_tuning(value * 16383);
    }
    void __fastcall skindef_paint_mastercoarsetuning(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        int value = synthesizers[param1 - 1]->get_master_coarse_tuning();
        draw_skin_cz(canvas, rect, value / 16384.0);
    }
    void __fastcall skindef_mouse_mastercoarsetuning(float value, TMouseButton button, int param1, int param2)
    {
        synthesizers[param1 - 1]->set_master_coarse_tuning(value * 16383);
    }
    void __fastcall skindef_paint_mute(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool mute = mute_channels[param1 - 1];
        canvas->CopyRect(rect, (mute ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_mute(float value, TMouseButton button, int param1, int param2)
    {
        mute_channels[param1 - 1] = !mute_channels[param1 - 1];
        update_mute();
    }
    void __fastcall skindef_paint_solo(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool solo = solo_channel == param1 - 1;
        canvas->CopyRect(rect, (solo ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_solo(float value, TMouseButton button, int param1, int param2)
    {
        if(solo_channel != -1){
            update_skin("ch%d-solo", param1 - 1);
        }
        solo_channel = solo_channel == param1 - 1 ? -1 : param1 - 1;
        update_mute();
    }
    void __fastcall skindef_paint_mono(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        bool mute = channel->get_mono_mode();
        canvas->CopyRect(rect, (mute ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_mono(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        if(channel->get_mono_mode()){
            channel->poly_mode_on();
        }else{
            channel->mono_mode_on();
        }
    }
    void __fastcall skindef_paint_damper(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        canvas->CopyRect(rect, (channel->get_damper() >= 64 ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_damper_on(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_damper(127);
    }
    void __fastcall skindef_mouse_damper_off(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_damper(0);
    }
    void __fastcall skindef_paint_sostenute(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        canvas->CopyRect(rect, (channel->get_sostenute() >= 64 ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_sostenute_on(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_sostenute(127);
    }
    void __fastcall skindef_mouse_sostenute_off(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_sostenute(0);
    }
    void __fastcall skindef_paint_freeze(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        canvas->CopyRect(rect, (channel->get_freeze() >= 64 ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_freeze_on(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_freeze(127);
    }
    void __fastcall skindef_mouse_freeze_off(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_freeze(0);
    }
    void __fastcall skindef_paint_pan(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin_cz(canvas, rect, channel->get_panpot() / 16384.0);
    }
    void __fastcall skindef_mouse_pan(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_panpot(value * 16383);
    }
    void __fastcall skindef_paint_volume(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin(canvas, rect, channel->get_volume() / 16384.0);
    }
    void __fastcall skindef_mouse_volume(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_volume(value * 16383);
    }
    void __fastcall skindef_paint_expression(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin(canvas, rect, channel->get_expression() / 16384.0);
    }
    void __fastcall skindef_mouse_expression(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_expression(value * 16383);
    }
    void __fastcall skindef_paint_pitchbend(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin_cz(canvas, rect, channel->get_pitch_bend() / 16384.0);
    }
    void __fastcall skindef_mouse_pitchbend(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->pitch_bend_change(value * 16383);
    }
    void __fastcall skindef_paint_pitchbendsensitivity(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin(canvas, rect, channel->get_pitch_bend_sensitivity() / 16384.0);
    }
    void __fastcall skindef_mouse_pitchbendsensitivity(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_pitch_bend_sensitivity(value * 16383);
    }
    void __fastcall skindef_paint_channelpressure(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin(canvas, rect, channel->get_channel_pressure() / 128.0);
    }
    void __fastcall skindef_mouse_channelpressure(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->channel_pressure(value * 127);
    }
    void __fastcall skindef_paint_modulationdepth(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin(canvas, rect, channel->get_modulation_depth() / 16384.0);
    }
    void __fastcall skindef_mouse_modulationdepth(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_modulation_depth(value * 16383);
    }
    void __fastcall skindef_paint_modulationdepthrange(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin(canvas, rect, channel->get_modulation_depth_range() / 16384.0);
    }
    void __fastcall skindef_mouse_modulationdepthrange(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_modulation_depth_range(value * 16383);
    }
    void __fastcall skindef_paint_finetuning(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin_cz(canvas, rect, channel->get_fine_tuning() / 16384.0);
    }
    void __fastcall skindef_mouse_finetuning(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_fine_tuning(value * 16383);
    }
    void __fastcall skindef_paint_coarsetuning(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        draw_skin_cz(canvas, rect, channel->get_coarse_tuning() / 16384.0);
    }
    void __fastcall skindef_mouse_coarsetuning(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->set_coarse_tuning(value * 16383);
    }
    void __fastcall skindef_paint_program(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        int program = channel->get_program();
        bool drum = (program >> 14) == 120;
        char s[128];
        if(drum){
            if(program == 0x1E0000){
                std::sprintf(s, "%d スタンダードドラムセット", program & 127);
            }else if((program >> 7) == 0x3C00){
                std::sprintf(s, "%d (drum)", program & 127);
            }else{
                std::sprintf(s, "%d (drum/L=%d/P=%d)", program, (program >> 7) & 127, program & 127);
            }
        }else if((program >> 7) == 0x3C80 || (program >> 7) == 0){
            std::sprintf(s, "%d %s", program & 127, program_names[program & 127]);
        }else{
            std::sprintf(s, "%d (M=%d/L=%d/P=%d)", program, (program >> 14) & 127, (program >> 7) & 127, program & 127);
        }
        canvas->CopyRect(rect, bmp_skin_a->Canvas, rect);
        canvas->TextRect(rect, rect.left, rect.top, s);
    }
    void __fastcall skindef_mouse_program(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        int program = channel->get_program();
        if(button == mbLeft){
            ++program;
        }else if(button == mbRight){
            program += 127;
        }
        channel->program_change(program & 127);
    }
    void __fastcall skindef_paint_key(TCanvas* canvas, const TRect& rect, int param1, int param2)
    {
        bool on = paint_note[param1 - 1][param2];
        canvas->CopyRect(rect, (on ? bmp_skin_b.get() : bmp_skin_a.get())->Canvas, rect);
    }
    void __fastcall skindef_mouse_key_on(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->note_on(param2, 127);
    }
    void __fastcall skindef_mouse_key_off(float value, TMouseButton button, int param1, int param2)
    {
        midisynth::channel* channel = synthesizers[(param1 - 1) / 16]->get_channel((param1 - 1) % 16);
        channel->note_on(param2, 0);
    }
    
    void init_skin()
    {
        define_skin("title", 0, 0, skindef_paint_title, NULL, NULL, NULL);
        define_skin("copyright", 0, 0, skindef_paint_copyright, NULL, NULL, NULL);
        define_skin("song", 0, 0, skindef_paint_song, NULL, NULL, NULL);
        define_skin("position", 0, 0, skindef_paint_position, skindef_mouse_position, skindef_mouse_position, skindef_mouse_position);
        define_skin("bpm", 0, 0, skindef_paint_bpm, NULL, NULL, NULL);
        define_skin("notecount", 0, 0, skindef_paint_notecount, NULL, NULL, NULL);
        for(int i = 0; i < 16; ++i){
            define_skin("spectrum%d", i + 1, 0, skindef_paint_spectrum, NULL, NULL, NULL);
        }
        for(int i = 0; i < 4; ++i){
            define_skin("port%d-systemmode-gm", i + 1, 0, skindef_paint_systemmode_gm, skindef_mouse_systemmode_gm, NULL, NULL);
            define_skin("port%d-systemmode-gm2", i + 1, 0, skindef_paint_systemmode_gm2, skindef_mouse_systemmode_gm2, NULL, NULL);
            define_skin("port%d-systemmode-gs", i + 1, 0, skindef_paint_systemmode_gs, skindef_mouse_systemmode_gs, NULL, NULL);
            define_skin("port%d-systemmode-xg", i + 1, 0, skindef_paint_systemmode_xg, skindef_mouse_systemmode_xg, NULL, NULL);
            define_skin("port%d-mastervolume", i + 1, 0, skindef_paint_mastervolume, skindef_mouse_mastervolume, skindef_mouse_mastervolume, skindef_mouse_mastervolume);
            define_skin("port%d-masterbalance", i + 1, 0, skindef_paint_masterbalance, skindef_mouse_masterbalance, skindef_mouse_masterbalance, skindef_mouse_masterbalance);
            define_skin("port%d-masterfinetuning", i + 1, 0, skindef_paint_masterfinetuning, skindef_mouse_masterfinetuning, skindef_mouse_masterfinetuning, skindef_mouse_masterfinetuning);
            define_skin("port%d-mastercoarsetuning", i + 1, 0, skindef_paint_mastercoarsetuning, skindef_mouse_mastercoarsetuning, skindef_mouse_mastercoarsetuning, skindef_mouse_mastercoarsetuning);
        }
        for(int i = 0; i < NUM_PORTS * 4; ++i){
            define_skin("ch%d-mute", i + 1, 0, skindef_paint_mute, skindef_mouse_mute, NULL, NULL);
            define_skin("ch%d-solo", i + 1, 0, skindef_paint_solo, skindef_mouse_solo, NULL, NULL);
            define_skin("ch%d-mono", i + 1, 0, skindef_paint_mono, skindef_mouse_mono, NULL, NULL);
            define_skin("ch%d-damper", i + 1, 0, skindef_paint_damper, skindef_mouse_damper_on, NULL, skindef_mouse_damper_off);
            define_skin("ch%d-sostenute", i + 1, 0, skindef_paint_sostenute, skindef_mouse_sostenute_on, NULL, skindef_mouse_sostenute_off);
            define_skin("ch%d-freeze", i + 1, 0, skindef_paint_freeze, skindef_mouse_freeze_on, NULL, skindef_mouse_freeze_off);
            define_skin("ch%d-pan", i + 1, 0, skindef_paint_pan, skindef_mouse_pan, skindef_mouse_pan, skindef_mouse_pan);
            define_skin("ch%d-volume", i + 1, 0, skindef_paint_volume, skindef_mouse_volume, skindef_mouse_volume, skindef_mouse_volume);
            define_skin("ch%d-expression", i + 1, 0, skindef_paint_expression, skindef_mouse_expression, skindef_mouse_expression, skindef_mouse_expression);
            define_skin("ch%d-pitchbend", i + 1, 0, skindef_paint_pitchbend, skindef_mouse_pitchbend, skindef_mouse_pitchbend, skindef_mouse_pitchbend);
            define_skin("ch%d-pitchbendsensitivity", i + 1, 0, skindef_paint_pitchbendsensitivity, skindef_mouse_pitchbendsensitivity, skindef_mouse_pitchbendsensitivity, skindef_mouse_pitchbendsensitivity);
            define_skin("ch%d-channelpressure", i + 1, 0, skindef_paint_channelpressure, skindef_mouse_channelpressure, skindef_mouse_channelpressure, skindef_mouse_channelpressure);
            define_skin("ch%d-modulationdepth", i + 1, 0, skindef_paint_modulationdepth, skindef_mouse_modulationdepth, skindef_mouse_modulationdepth, skindef_mouse_modulationdepth);
            define_skin("ch%d-modulationdepthrange", i + 1, 0, skindef_paint_modulationdepthrange, skindef_mouse_modulationdepthrange, skindef_mouse_modulationdepthrange, skindef_mouse_modulationdepthrange);
            define_skin("ch%d-finetuning", i + 1, 0, skindef_paint_finetuning, skindef_mouse_finetuning, skindef_mouse_finetuning, skindef_mouse_finetuning);
            define_skin("ch%d-coarsetuning", i + 1, 0, skindef_paint_coarsetuning, skindef_mouse_coarsetuning, skindef_mouse_coarsetuning, skindef_mouse_coarsetuning);
            define_skin("ch%d-program", i + 1, 0, skindef_paint_program, skindef_mouse_program, NULL, NULL);
            for(int j = 0; j < 128; ++j){
                define_skin("ch%d-key%d", i + 1, j, skindef_paint_key, skindef_mouse_key_on, NULL, skindef_mouse_key_off);
            }
        }
    }
    void load_skin()
    {
        bmp_skin_a.reset(new Graphics::TBitmap);
        bmp_skin_b.reset(new Graphics::TBitmap);
        bmp_skin_a->LoadFromFile("skin-a.bmp");
        bmp_skin_b->LoadFromFile("skin-b.bmp");
        std::FILE* fp = std::fopen((ExtractFilePath(Application->ExeName) + "skin.txt").c_str(), "rt");
        if(!fp){
            fp = std::fopen("skin.txt", "rt");
        }
        if(!fp){
            ShowMessage("skin.txtを読み込めません。");
        }else{
            while(!std::feof(fp)){
                if(std::fgetc(fp) == '@'){
                    char name[256];
                    int x, y, w, h;
                    if(std::fscanf(fp, "%255s%d%d%d%d", name, &x, &y, &w, &h) == 5){
                        skindefs[compute_skindef_hash(name)].rect = Bounds(x, y, w, h);
                    }
                }
            }
            std::fclose(fp);
        }
    }
    int hit_test(int x, int y)
    {
        for(std::map<int, SKINDEF>::iterator i = skindefs.begin(); i != skindefs.end(); ++i){
            if(x >= i->second.rect.left && x < i->second.rect.right && y >= i->second.rect.top && y < i->second.rect.bottom){
                if(i->first != compute_skindef_hash("text")){
                    return i->first;
                }
            }
        }
        return 0;
    }
}
namespace{
    class skindef_key_comparator{
    public:
        skindef_key_comparator(){}
        bool operator()(const std::map<std::string, SKINDEF>::value_type& v, const char* s)const
        {
            return std::strcmp(v.first.c_str(), s) < 0;
        }
    };
}
void update_skin()
{
    for(std::map<int, SKINDEF>::iterator i = skindefs.begin(); i != skindefs.end(); ++i){
        i->second.repaint = true;
    }
    repaint_skin = true;
}
void update_skin(int hash)
{
    std::map<int, SKINDEF>::iterator i = skindefs.find(hash);
    if(i != skindefs.end()){
        i->second.repaint = true;
        repaint_skin = true;
    }
}
void update_skin(const char* format, int param1, int param2)
{
    char s[256];
    std::sprintf(s, format, param1, param2);
    int hash = compute_skindef_hash(s);
    update_skin(hash);
}
//---------------------------------------------------------------------------
namespace{
    void load_programs()
    {
        std::FILE* fp = std::fopen((ExtractFilePath(Application->ExeName) + "programs.txt").c_str(), "rt");
        if(!fp){
            fp = std::fopen("programs.txt", "rt");
        }
        if(!fp){
            ShowMessage("programs.txtを読み込めません。");
        }else{
            while(!std::feof(fp)){
                int c = std::getc(fp);
                if(c == '@'){
                    int prog;
                    midisynth::FMPARAMETER p;
                    if(std::fscanf(fp, "%d%d%d%d", &prog, &p.ALG, &p.FB, &p.LFO) == 4
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op1.AR, &p.op1.DR, &p.op1.SR, &p.op1.RR, &p.op1.SL, &p.op1.TL, &p.op1.KS, &p.op1.ML, &p.op1.DT, &p.op1.AMS) == 10
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op2.AR, &p.op2.DR, &p.op2.SR, &p.op2.RR, &p.op2.SL, &p.op2.TL, &p.op2.KS, &p.op2.ML, &p.op2.DT, &p.op2.AMS) == 10
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op3.AR, &p.op3.DR, &p.op3.SR, &p.op3.RR, &p.op3.SL, &p.op3.TL, &p.op3.KS, &p.op3.ML, &p.op3.DT, &p.op3.AMS) == 10
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op4.AR, &p.op4.DR, &p.op4.SR, &p.op4.RR, &p.op4.SL, &p.op4.TL, &p.op4.KS, &p.op4.ML, &p.op4.DT, &p.op4.AMS) == 10){
                        note_factory.set_program(prog, p);
                    }
                }else if(c == '*'){
                    int prog;
                    midisynth::DRUMPARAMETER p;
                    if(std::fscanf(fp, "%d%d%d%d%d%d%d", &prog, &p.ALG, &p.FB, &p.LFO, &p.key, &p.panpot, &p.assign) == 7
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op1.AR, &p.op1.DR, &p.op1.SR, &p.op1.RR, &p.op1.SL, &p.op1.TL, &p.op1.KS, &p.op1.ML, &p.op1.DT, &p.op1.AMS) == 10
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op2.AR, &p.op2.DR, &p.op2.SR, &p.op2.RR, &p.op2.SL, &p.op2.TL, &p.op2.KS, &p.op2.ML, &p.op2.DT, &p.op2.AMS) == 10
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op3.AR, &p.op3.DR, &p.op3.SR, &p.op3.RR, &p.op3.SL, &p.op3.TL, &p.op3.KS, &p.op3.ML, &p.op3.DT, &p.op3.AMS) == 10
                    && std::fscanf(fp, "%d%d%d%d%d%d%d%d%d%d", &p.op4.AR, &p.op4.DR, &p.op4.SR, &p.op4.RR, &p.op4.SL, &p.op4.TL, &p.op4.KS, &p.op4.ML, &p.op4.DT, &p.op4.AMS) == 10){
                        note_factory.set_drum_program(prog, p);
                    }
                }
            }
            std::fclose(fp);
        }
    }
}
//---------------------------------------------------------------------------
namespace{
    std::vector<std::string> playlist;
    std::size_t playlist_index;
}
//---------------------------------------------------------------------------
static void play_file(const char* filename)
{
    std::FILE* fp = std::fopen(filename, "rb");
    if(!fp){
        playlist.clear();
        ShowMessage(AnsiString(filename) + ":" + std::strerror(errno));
    }else{
        bool ret = sequencer.load(fp);
        fclose(fp);
        if(!ret){
            playlist.clear();
            ShowMessage(AnsiString() + filename + ":読み込み失敗");
        }else{
            EnterCriticalSection(&cs);
            midi_reset();
            songtext = " " + sequencer.get_song();
            songptr = 1;
            songprev = 0;
            sequencer_start_time = timeGetTime();
            if(sequencer_start_time == 0){
                sequencer_start_time = 1;
            }
            LeaveCriticalSection(&cs);
        }
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    init_skin();
    load_skin();
    load_programs();

    timeBeginPeriod(1);
    InitializeCriticalSection(&cs);
    easywave_initialize(sampling_rate, WAVE_MAPPER);
    last_timer_callback = last_heavy_time = timeGetTime();
    DWORD thread_id;
    hThread = CreateThread(NULL, 0, thread_entry_point, NULL, 0, &thread_id);
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
    if(hThread){
        thread_termination_flag = true;
        WaitForSingleObject(hThread, INFINITE);
    }
    easywave_finalize();
    DeleteCriticalSection(&cs);
    timeEndPeriod(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    ClientWidth = bmp_skin_a->Width;
    ClientHeight = bmp_skin_a->Height;
    
    const TRect& rect = skindefs[compute_skindef_hash("text")].rect;
    Font->Assign(Screen->IconFont);
    Font->Color = (TColor)RGB(rect.left, rect.top, rect.Width());
    Font->Height = rect.Height();

    hwnd = Handle;

    DragAcceptFiles(hwnd, TRUE);

    int n = waveOutGetNumDevs();
    for(int i = 0; i < n; ++i){
        WAVEOUTCAPS caps;
        TMenuItem* item = new TMenuItem(this);
        if(waveOutGetDevCaps(i, &caps, sizeof(caps)) == 0){
            item->Caption = caps.szPname;
        }else{
            item->Caption = "unknown";
        }
        item->RadioItem = true;
        item->OnClick = WaveMapperMenu->OnClick;
        item->Tag = i;
        WaveoutMenu->Insert(1 + i, item);
    }

    n = midiInGetNumDevs();
    for(int i = 0; i < n; ++i){
        MIDIINCAPS caps;
        TMenuItem* item = new TMenuItem(this);
        if(midiInGetDevCaps(i, &caps, sizeof(caps)) == 0){
            item->Caption = caps.szPname;
        }else{
            item->Caption = "unknown";
        }
        item->OnClick = NoMidiInMenu->OnClick;
        item->Tag = i;
        MidiInMenu->Add(item);
        NoMidiInMenu->Visible = false;

        MIDIIN_MAPPER mapper;
        mapper.hMidiIn = NULL;
        mapper.sysex_port = i % 4;
        for(int j = 0; j < 16; ++j){
            mapper.channel_map[j] = (i % 4) * 16 + j;
        }
        midiin_mapper.push_back(mapper);
    }

    n = ParamCount();
    for(int i = 1; i <= n; ++i){
        playlist.push_back(ParamStr(i).c_str());
    }
    if(!playlist.empty()){
        Caption = playlist[0].c_str();
        play_file(playlist[0].c_str());
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    for(std::size_t i = 0; i < midiin_mapper.size(); ++i){
        HMIDIIN hMidiIn = midiin_mapper[i].hMidiIn;
        if(hMidiIn){
            midiin_mapper[i].hMidiIn = NULL;
            midiInStop(hMidiIn);
            midiInReset(hMidiIn);
            midiInClose(hMidiIn);
        }
    }
    if(wav_writer.get()){
        EnterCriticalSection(&cs);
        try{
            wav_writer->close();
        }catch(...){
        }
        wav_writer.reset();
        LeaveCriticalSection(&cs);
        Form4->Hide();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::X1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::A1Click(TObject *Sender)
{
    ShowMessage("ソフトウェアFM音源MIDIプレイヤー\nCopyright(c)2003-2004, yuno");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MmMimData(TMessage& message)
{
    HMIDIIN hMidiIn = reinterpret_cast<HMIDIIN>(message.WParam);
    std::size_t i;
    for(i = 0; i < midiin_mapper.size(); ++i){
        if(midiin_mapper[i].hMidiIn == hMidiIn){
            break;
        }
    }
    if(i == midiin_mapper.size()){
        midi_message(0, message.LParam);
    }else{
        int port = midiin_mapper[i].sysex_port;
        switch(message.LParam & 0xF0){
        case 0x80:
        case 0x90:
        case 0xA0:
        case 0xB0:
        case 0xC0:
        case 0xD0:
        case 0xE0:
            {
                int channel = midiin_mapper[i].channel_map[message.LParam & 15];
                message.LParam &= ~0xF;
                message.LParam |= channel & 0x0F;
                port = channel / 16;
            }
            break;
        default:
            break;
        }
        midi_message(port, message.LParam);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MmMimLongdata(TMessage& message)
{
    HMIDIIN hMidiIn = reinterpret_cast<HMIDIIN>(message.WParam);
    MIDIHDR* midihdr = reinterpret_cast<MIDIHDR*>(message.LParam);

    std::size_t i;
    for(i = 0; i < midiin_mapper.size(); ++i){
        if(midiin_mapper[i].hMidiIn == hMidiIn){
            break;
        }
    }
    if(i == midiin_mapper.size()){
        midi_sysex(0, midihdr->lpData, midihdr->dwBytesRecorded);
    }else{
        midi_sysex(midiin_mapper[i].sysex_port, midihdr->lpData, midihdr->dwBytesRecorded);
    }

    midiInUnprepareHeader(hMidiIn, midihdr, sizeof(MIDIHDR));

    if(midiin_mapper[i].hMidiIn == hMidiIn){
        midihdr->dwBytesRecorded = 0;
        midiInPrepareHeader(hMidiIn, midihdr, sizeof(MIDIHDR));
        midiInAddBuffer(hMidiIn, midihdr, sizeof(MIDIHDR));
    }else{
        free(midihdr);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WaveMapperMenuClick(TObject *Sender)
{
    TMenuItem* item = dynamic_cast<TMenuItem*>(Sender);
    if(item){
        item->Checked = true;
        EnterCriticalSection(&cs);
        waveout_device = item->Tag;
        easywave_initialize(sampling_rate, waveout_device);
        LeaveCriticalSection(&cs);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N192kHz1Click(TObject *Sender)
{
    TMenuItem* item = dynamic_cast<TMenuItem*>(Sender);
    if(item){
        item->Checked = true;
        EnterCriticalSection(&cs);
        sampling_rate = item->Tag;
        easywave_initialize(sampling_rate, waveout_device);
        LeaveCriticalSection(&cs);
        update_equalizer();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    TCanvas* canvas = Canvas;
    canvas->Brush->Style = bsClear;
    canvas->Font->Assign(Font);
    canvas->Draw(0, 0, bmp_skin_a.get());
    update_skin();
}
//---------------------------------------------------------------------------
int capture_element;
TMouseButton capture_button;
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    capture_element = hit_test(X, Y);
    if(capture_element){
        SetCaptureControl(this);
        capture_button = Button;
        SKINDEF& def = skindefs[capture_element];
        if(def.mousedown){
            float value = static_cast<float>(X - def.rect.left) / (def.rect.Width() - 1);
            if(value < 0){
                value = 0;
            }else if(value > 1){
                value = 1;
            }
            EnterCriticalSection(&cs);
            (def.mousedown)(value, Button, def.param1, def.param2);
            LeaveCriticalSection(&cs);
            update_skin(capture_element);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if(capture_element){
        SKINDEF& def = skindefs[capture_element];
        if(def.mousemove){
            float value = static_cast<float>(X - def.rect.left) / (def.rect.Width() - 1);
            if(value < 0){
                value = 0;
            }else if(value > 1){
                value = 1;
            }
            EnterCriticalSection(&cs);
            (def.mousemove)(value, capture_button, def.param1, def.param2);
            LeaveCriticalSection(&cs);
            update_skin(capture_element);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if(capture_element && Button == capture_button){
        SKINDEF& def = skindefs[capture_element];
        if(def.mouseup){
            float value = static_cast<float>(X - def.rect.left) / (def.rect.Width() - 1);
            if(value < 0){
                value = 0;
            }else if(value > 1){
                value = 1;
            }
            EnterCriticalSection(&cs);
            (def.mouseup)(value, capture_button, def.param1, def.param2);
            LeaveCriticalSection(&cs);
            update_skin(capture_element);
        }
        capture_element = 0;
    }
    SetCaptureControl(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PlaylistTimerTimer(TObject *Sender)
{
    if(!playlist.empty()){
        EnterCriticalSection(&cs);
        float time = (timeGetTime() - sequencer_start_time) / 1000.0;
        if(time > sequencer.get_total_time()){
            sequencer_start_time = 0;
            LeaveCriticalSection(&cs);
            ++playlist_index;
            if(playlist_index < playlist.size()){
                Caption = playlist[playlist_index].c_str();
                play_file(playlist[playlist_index].c_str());
            }
        }else{
            LeaveCriticalSection(&cs);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::O2Click(TObject *Sender)
{
    EnterCriticalSection(&cs);
    playlist.clear();
    sequencer_start_time = 0;
    LeaveCriticalSection(&cs);

    midi_reset();

    OpenDialogMid->FileName = "";
    if(OpenDialogMid->Execute()){
        int n = OpenDialogMid->Files->Count;
        for(int i = 0; i < n; ++i){
            playlist.push_back(OpenDialogMid->Files->Strings[i].c_str());
        }
        playlist_index = 0;
        Caption = playlist[0].c_str();
        play_file(playlist[0].c_str());
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ApplicationEvents1Idle(TObject *Sender, bool &Done)
{
    if(repaint_skin){
        repaint_skin = false;
        TCanvas* canvas = Canvas;
        canvas->Brush->Style = bsClear;
        canvas->Font->Assign(Font);
        for(std::map<int, SKINDEF>::iterator i = skindefs.begin(); i != skindefs.end(); ++i){
            if(i->second.repaint){
                i->second.repaint = false;
                if(i->second.rect.Width() > 0 && i->second.paint){
                    EnterCriticalSection(&cs);
                    (i->second.paint)(canvas, i->second.rect, i->second.param1, i->second.param2);
                    LeaveCriticalSection(&cs);
                }
            }
        }
    }
    Done = false;
    Sleep(1);
}
//---------------------------------------------------------------------------
// exports for Unit3
void set_program_parameter(int n, const midisynth::FMPARAMETER& p)
{
    EnterCriticalSection(&cs);
    note_factory.set_program(n, p);
    LeaveCriticalSection(&cs);
}
void get_program_parameter(int n, midisynth::FMPARAMETER& p)
{
    EnterCriticalSection(&cs);
    note_factory.get_program(n, p);
    LeaveCriticalSection(&cs);
}
void all_sound_off_immediately()
{
    EnterCriticalSection(&cs);
    for(int i = 0; i < NUM_PORTS; ++i){
        synthesizers[i]->all_sound_off_immediately();
    }
    LeaveCriticalSection(&cs);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EDITP1Click(TObject *Sender)
{
    Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NoMidiInMenuClick(TObject *Sender)
{
    TMenuItem* item = dynamic_cast<TMenuItem*>(Sender);
    if(item){
        int device = item->Tag;
        MIDIIN_MAPPER& mapper = midiin_mapper[device];
        Form2->Port->ItemIndex = mapper.sysex_port;
        Form2->ChannelMap1->ItemIndex = mapper.channel_map[0];
        Form2->ChannelMap2->ItemIndex = mapper.channel_map[1];
        Form2->ChannelMap3->ItemIndex = mapper.channel_map[2];
        Form2->ChannelMap4->ItemIndex = mapper.channel_map[3];
        Form2->ChannelMap5->ItemIndex = mapper.channel_map[4];
        Form2->ChannelMap6->ItemIndex = mapper.channel_map[5];
        Form2->ChannelMap7->ItemIndex = mapper.channel_map[6];
        Form2->ChannelMap8->ItemIndex = mapper.channel_map[7];
        Form2->ChannelMap9->ItemIndex = mapper.channel_map[8];
        Form2->ChannelMap10->ItemIndex = mapper.channel_map[9];
        Form2->ChannelMap11->ItemIndex = mapper.channel_map[10];
        Form2->ChannelMap12->ItemIndex = mapper.channel_map[11];
        Form2->ChannelMap13->ItemIndex = mapper.channel_map[12];
        Form2->ChannelMap14->ItemIndex = mapper.channel_map[13];
        Form2->ChannelMap15->ItemIndex = mapper.channel_map[14];
        Form2->ChannelMap16->ItemIndex = mapper.channel_map[15];
        if(Form2->ShowModal() == mrOk){
            mapper.sysex_port = Form2->Port->ItemIndex;
            mapper.channel_map[0] = Form2->ChannelMap1->ItemIndex;
            mapper.channel_map[1] = Form2->ChannelMap2->ItemIndex;
            mapper.channel_map[2] = Form2->ChannelMap3->ItemIndex;
            mapper.channel_map[3] = Form2->ChannelMap4->ItemIndex;
            mapper.channel_map[4] = Form2->ChannelMap5->ItemIndex;
            mapper.channel_map[5] = Form2->ChannelMap6->ItemIndex;
            mapper.channel_map[6] = Form2->ChannelMap7->ItemIndex;
            mapper.channel_map[7] = Form2->ChannelMap8->ItemIndex;
            mapper.channel_map[8] = Form2->ChannelMap9->ItemIndex;
            mapper.channel_map[9] = Form2->ChannelMap10->ItemIndex;
            mapper.channel_map[10] = Form2->ChannelMap11->ItemIndex;
            mapper.channel_map[11] = Form2->ChannelMap12->ItemIndex;
            mapper.channel_map[12] = Form2->ChannelMap13->ItemIndex;
            mapper.channel_map[13] = Form2->ChannelMap14->ItemIndex;
            mapper.channel_map[14] = Form2->ChannelMap15->ItemIndex;
            mapper.channel_map[15] = Form2->ChannelMap16->ItemIndex;
            if(!mapper.hMidiIn){
                if(midiInOpen(&mapper.hMidiIn, device, reinterpret_cast<DWORD>(hwnd), 0, CALLBACK_WINDOW) != MMSYSERR_NOERROR){
                    ShowMessage("デバイスオープン失敗");
                }else{
                    MIDIHDR* midihdr = static_cast<MIDIHDR*>(malloc(sizeof(MIDIHDR) + 1024));
                    if(midihdr){
                        memset(midihdr, 0, sizeof(MIDIHDR));
                        midihdr->lpData = reinterpret_cast<LPSTR>(midihdr + 1);
                        midihdr->dwBufferLength = 1024;
                        midiInPrepareHeader(mapper.hMidiIn, midihdr, sizeof(MIDIHDR));
                        midiInAddBuffer(mapper.hMidiIn, midihdr, sizeof(MIDIHDR));
                    }
                    midiInStart(mapper.hMidiIn);
                    item->Checked = true;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateTimerTimer(TObject *Sender)
{
    update_skin("position");
    for(int i = 0; i < 16; ++i){
        update_skin("spectrum%d", i + 1);
    }
    if(wav_writer.get()){
        EnterCriticalSection(&cs);
        unsigned long bytes = wav_writer->get_written_bytes();
        LeaveCriticalSection(&cs);
        char s[64];
        std::sprintf(s, "%lu", bytes);
        Form4->Written->Text = s;
    }
    bool Done = true;
    ApplicationEvents1Idle(this, Done);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WaveFileOutputMenuClick(TObject *Sender)
{
    SaveDialogWav->FileName = "";
    if(SaveDialogWav->Execute()){
        AnsiString FileName = SaveDialogWav->FileName;
        const char* filename = FileName.c_str();
        EnterCriticalSection(&cs);
        wav_writer.reset(new wav_file_writer(filename, sampling_rate));
        LeaveCriticalSection(&cs);
        Form4->FileName->Text = FileName;
        Form4->Written->Text = "0.0";
        Form4->CloseButton->OnClick = Form4CloseButtonClick;
        Form4->ActiveControl = Form4->CloseButton;
        Form4->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Form4CloseButtonClick(TObject *Sender)
{
    bool err = false;
    EnterCriticalSection(&cs);
    if(wav_writer.get()){
        try{
            wav_writer->close();
        }catch(std::runtime_error& e){
            err = true;
        }
        wav_writer.reset();
    }
    LeaveCriticalSection(&cs);

    Form4->Hide();
    if(err){
        ShowMessage("ファイル書き込みエラー");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WmWavWriteError(TMessage& message)
{
    Form4->Hide();
    ShowMessage("ファイル書き込みエラー");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WmDropFiles(TMessage& message)
{
    EnterCriticalSection(&cs);
    playlist.clear();
    sequencer_start_time = 0;
    LeaveCriticalSection(&cs);

    midi_reset();

    char filename[1024];
    HDROP hDrop = reinterpret_cast<HDROP>(message.WParam);
    int n = DragQueryFile(hDrop, -1, NULL, 0);
    for(int i = 0; i < n; ++i){
        if(DragQueryFile(hDrop, i, filename, sizeof(filename) - 1) > 0){
            filename[1023] = '\0';
            playlist.push_back(filename);
        }
    }
    playlist_index = 0;
    if(!playlist.empty()){
        Caption = playlist[0].c_str();
        play_file(playlist[0].c_str());
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::E1Click(TObject *Sender)
{
    Form5->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OutputSilenceClick(TObject *Sender)
{
    OutputSilence->Checked = output_silence = !OutputSilence->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MenuMuteClick(TObject *Sender)
{
    MenuMute->Checked = waveout_mute = !MenuMute->Checked;
}
//---------------------------------------------------------------------------

