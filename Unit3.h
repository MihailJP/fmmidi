//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include "midisynth.hpp"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE 管理のコンポーネント
    TComboBox *ComboProgram;
    TButton *Button1;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label17;
    TEdit *Edit3;
    TUpDown *AR1;
    TEdit *Edit4;
    TUpDown *DR1;
    TEdit *Edit5;
    TUpDown *SR1;
    TEdit *Edit6;
    TUpDown *RR1;
    TEdit *Edit7;
    TUpDown *SL1;
    TEdit *Edit8;
    TUpDown *TL1;
    TEdit *Edit9;
    TUpDown *KS1;
    TEdit *Edit10;
    TUpDown *ML1;
    TEdit *Edit11;
    TUpDown *DT1;
    TEdit *Edit12;
    TUpDown *AR2;
    TEdit *Edit13;
    TUpDown *DR2;
    TEdit *Edit14;
    TUpDown *SR2;
    TEdit *Edit15;
    TUpDown *RR2;
    TEdit *Edit16;
    TUpDown *SL2;
    TEdit *Edit17;
    TUpDown *TL2;
    TEdit *Edit18;
    TUpDown *KS2;
    TEdit *Edit19;
    TUpDown *ML2;
    TEdit *Edit20;
    TUpDown *DT2;
    TEdit *Edit21;
    TUpDown *AR3;
    TEdit *Edit22;
    TUpDown *DR3;
    TEdit *Edit23;
    TUpDown *SR3;
    TEdit *Edit24;
    TUpDown *RR3;
    TEdit *Edit25;
    TUpDown *SL3;
    TEdit *Edit26;
    TUpDown *TL3;
    TEdit *Edit27;
    TUpDown *KS3;
    TEdit *Edit28;
    TUpDown *ML3;
    TEdit *Edit29;
    TUpDown *DT3;
    TEdit *Edit30;
    TUpDown *AR4;
    TEdit *Edit31;
    TUpDown *DR4;
    TEdit *Edit32;
    TUpDown *SR4;
    TEdit *Edit33;
    TUpDown *RR4;
    TEdit *Edit34;
    TUpDown *SL4;
    TEdit *Edit35;
    TUpDown *TL4;
    TEdit *Edit36;
    TUpDown *KS4;
    TEdit *Edit37;
    TUpDown *ML4;
    TEdit *Edit38;
    TUpDown *DT4;
    TEdit *Edit40;
    TUpDown *AMS1;
    TEdit *Edit41;
    TUpDown *AMS2;
    TEdit *Edit42;
    TUpDown *AMS3;
    TEdit *Edit43;
    TUpDown *AMS4;
    TUpDown *LFO;
    TEdit *Edit39;
    TLabel *Label16;
    TUpDown *FB;
    TEdit *Edit2;
    TLabel *Label2;
    TUpDown *ALG;
    TEdit *Edit1;
    TLabel *Label1;
    void __fastcall Edit1Change(TObject *Sender);
    void __fastcall Edit1Exit(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ComboProgramChange(TObject *Sender);
private:	// ユーザー宣言
    bool loading_params;
    void load_parameters(const midisynth::FMPARAMETER& p);
    void save_parameters(midisynth::FMPARAMETER& p);
public:		// ユーザー宣言
    __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
