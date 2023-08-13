//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
    Form1->SamplingRateMenu->Enabled = false;
    Form1->WaveFileOutputMenu->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormHide(TObject *Sender)
{
    Form1->SamplingRateMenu->Enabled = true;
    Form1->WaveFileOutputMenu->Enabled = true;
}
//---------------------------------------------------------------------------
