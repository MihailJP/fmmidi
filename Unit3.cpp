//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
extern void set_program_parameter(int n, const midisynth::FMPARAMETER& p);
extern void get_program_parameter(int n, midisynth::FMPARAMETER& p);
extern void all_sound_off_immediately();
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
    loading_params = true;
}
//---------------------------------------------------------------------------
void TForm3::load_parameters(const midisynth::FMPARAMETER& p)
{
    loading_params = true;
    ALG->Position = p.ALG;
    FB->Position = p.FB;
    LFO->Position = p.LFO;
    AR1->Position = p.op1.AR;
    DR1->Position = p.op1.DR;
    SR1->Position = p.op1.SR;
    RR1->Position = p.op1.RR;
    SL1->Position = p.op1.SL;
    TL1->Position = p.op1.TL;
    KS1->Position = p.op1.KS;
    ML1->Position = p.op1.ML;
    DT1->Position = p.op1.DT;
    AMS1->Position = p.op1.AMS;
    AR2->Position = p.op2.AR;
    DR2->Position = p.op2.DR;
    SR2->Position = p.op2.SR;
    RR2->Position = p.op2.RR;
    SL2->Position = p.op2.SL;
    TL2->Position = p.op2.TL;
    KS2->Position = p.op2.KS;
    ML2->Position = p.op2.ML;
    DT2->Position = p.op2.DT;
    AMS2->Position = p.op2.AMS;
    AR3->Position = p.op3.AR;
    DR3->Position = p.op3.DR;
    SR3->Position = p.op3.SR;
    RR3->Position = p.op3.RR;
    SL3->Position = p.op3.SL;
    TL3->Position = p.op3.TL;
    KS3->Position = p.op3.KS;
    ML3->Position = p.op3.ML;
    DT3->Position = p.op3.DT;
    AMS3->Position = p.op3.AMS;
    AR4->Position = p.op4.AR;
    DR4->Position = p.op4.DR;
    SR4->Position = p.op4.SR;
    RR4->Position = p.op4.RR;
    SL4->Position = p.op4.SL;
    TL4->Position = p.op4.TL;
    KS4->Position = p.op4.KS;
    ML4->Position = p.op4.ML;
    DT4->Position = p.op4.DT;
    AMS4->Position = p.op4.AMS;
    loading_params = false;
}
void TForm3::save_parameters(midisynth::FMPARAMETER& p)
{
    p.ALG = ALG->Position;
    p.FB = FB->Position;
    p.LFO = LFO->Position;
    p.op1.AR = AR1->Position;
    p.op1.DR = DR1->Position;
    p.op1.SR = SR1->Position;
    p.op1.RR = RR1->Position;
    p.op1.SL = SL1->Position;
    p.op1.TL = TL1->Position;
    p.op1.KS = KS1->Position;
    p.op1.ML = ML1->Position;
    p.op1.DT = DT1->Position;
    p.op1.AMS = AMS1->Position;
    p.op2.AR = AR2->Position;
    p.op2.DR = DR2->Position;
    p.op2.SR = SR2->Position;
    p.op2.RR = RR2->Position;
    p.op2.SL = SL2->Position;
    p.op2.TL = TL2->Position;
    p.op2.KS = KS2->Position;
    p.op2.ML = ML2->Position;
    p.op2.DT = DT2->Position;
    p.op2.AMS = AMS2->Position;
    p.op3.AR = AR3->Position;
    p.op3.DR = DR3->Position;
    p.op3.SR = SR3->Position;
    p.op3.RR = RR3->Position;
    p.op3.SL = SL3->Position;
    p.op3.TL = TL3->Position;
    p.op3.KS = KS3->Position;
    p.op3.ML = ML3->Position;
    p.op3.DT = DT3->Position;
    p.op3.AMS = AMS3->Position;
    p.op4.AR = AR4->Position;
    p.op4.DR = DR4->Position;
    p.op4.SR = SR4->Position;
    p.op4.RR = RR4->Position;
    p.op4.SL = SL4->Position;
    p.op4.TL = TL4->Position;
    p.op4.KS = KS4->Position;
    p.op4.ML = ML4->Position;
    p.op4.DT = DT4->Position;
    p.op4.AMS = AMS4->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Change(TObject *Sender)
{
    if(!loading_params){
        midisynth::FMPARAMETER p;
        save_parameters(p);
        set_program_parameter(ComboProgram->ItemIndex, p);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Exit(TObject *Sender)
{
    midisynth::FMPARAMETER p;
    save_parameters(p);
    load_parameters(p);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender)
{
    midisynth::FMPARAMETER p;
    get_program_parameter(ComboProgram->ItemIndex, p);
    load_parameters(p);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    all_sound_off_immediately();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ComboProgramChange(TObject *Sender)
{
    midisynth::FMPARAMETER p;
    get_program_parameter(ComboProgram->ItemIndex, p);
    load_parameters(p);
}
//---------------------------------------------------------------------------
