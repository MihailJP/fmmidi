//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE 管理のコンポーネント
    TCheckBox *CheckEnabled;
    TLabel *Label1;
    TLabel *LabelFilterLength;
    TTrackBar *FilterLength;
    TTrackBar *G62Hz;
    TLabel *Label5;
    TTrackBar *G125Hz;
    TLabel *Label3;
    TTrackBar *G250Hz;
    TLabel *Label4;
    TTrackBar *G500Hz;
    TLabel *Label6;
    TTrackBar *G1kHz;
    TLabel *Label7;
    TTrackBar *G2kHz;
    TLabel *Label8;
    TTrackBar *G4kHz;
    TLabel *Label9;
    TTrackBar *G8kHz;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TTrackBar *G16kHz;
    TLabel *Label13;
    void __fastcall CheckEnabledClick(TObject *Sender);
    void __fastcall FilterLengthChange(TObject *Sender);
    void __fastcall G62HzChange(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
    __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
