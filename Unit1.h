//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <mmsystem.h>
#include <AppEvnts.hpp>
#include <Classes.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <string>
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
#define WM_WAVWRITEERROR    (WM_USER + 2)
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
    TMainMenu *MainMenu1;
    TMenuItem *O1;
    TMenuItem *WaveoutMenu;
    TMenuItem *C1;
    TMenuItem *H1;
    TMenuItem *A1;
    TMenuItem *SamplingRateMenu;
    TMenuItem *N4kHz1;
    TMenuItem *N8kHz1;
    TMenuItem *N11kHz1;
    TMenuItem *N22kHz1;
    TMenuItem *N44kHz1;
    TMenuItem *N32kHz1;
    TMenuItem *N48kHz1;
    TMenuItem *N96kHz1;
    TMenuItem *N192kHz1;
    TMenuItem *WaveMapperMenu;
    TMenuItem *F1;
    TMenuItem *O2;
    TMenuItem *X1;
    TMenuItem *N1;
    TMenuItem *MidiInMenu;
    TOpenDialog *OpenDialogMid;
    TTimer *PlaylistTimer;
    TMenuItem *WaveFileOutputMenu;
    TMenuItem *EDITP1;
    TApplicationEvents *ApplicationEvents1;
    TMenuItem *NoMidiInMenu;
    TTimer *UpdateTimer;
    TSaveDialog *SaveDialogWav;
    TMenuItem *E1;
    TMenuItem *OutputSilence;
    TMenuItem *MenuMute;
    TMenuItem *N2;
    void __fastcall X1Click(TObject *Sender);
    void __fastcall A1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall PlaylistTimerTimer(TObject *Sender);
    void __fastcall WaveMapperMenuClick(TObject *Sender);
    void __fastcall N192kHz1Click(TObject *Sender);
    void __fastcall O2Click(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall EDITP1Click(TObject *Sender);
    void __fastcall NoMidiInMenuClick(TObject *Sender);
    void __fastcall UpdateTimerTimer(TObject *Sender);
    void __fastcall WaveFileOutputMenuClick(TObject *Sender);
    void __fastcall Form4CloseButtonClick(TObject *Sender);
    void __fastcall E1Click(TObject *Sender);
    void __fastcall OutputSilenceClick(TObject *Sender);
    void __fastcall MenuMuteClick(TObject *Sender);
private:	// ユーザー宣言
    void __fastcall MmMimData(TMessage& message);
    void __fastcall MmMimLongdata(TMessage& message);
    void __fastcall WmWavWriteError(TMessage& message);
    void __fastcall WmDropFiles(TMessage& message);
public:		// ユーザー宣言
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
protected:
    BEGIN_MESSAGE_MAP
        VCL_MESSAGE_HANDLER(MM_MIM_DATA, TMessage, MmMimData)
        VCL_MESSAGE_HANDLER(MM_MIM_LONGDATA, TMessage, MmMimLongdata)
        VCL_MESSAGE_HANDLER(WM_WAVWRITEERROR, TMessage, WmWavWriteError)
        VCL_MESSAGE_HANDLER(WM_DROPFILES, TMessage, WmDropFiles)
    END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
