//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#include "filter.hpp"
#include <cmath>
#include <complex>
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
extern void update_equalizer();
//---------------------------------------------------------------------------
void __fastcall TForm5::CheckEnabledClick(TObject *Sender)
{
    update_equalizer();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FilterLengthChange(TObject *Sender)
{
    LabelFilterLength->Caption = IntToStr(1 << FilterLength->Position);
    update_equalizer();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::G62HzChange(TObject *Sender)
{
    update_equalizer();
}
//---------------------------------------------------------------------------
/*
void __fastcall TForm5::PaintBox1Paint(TObject *Sender)
{
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
    std::vector<double> h(length);
    filter::compute_equalizer_fir(&h[0], length, 44100, gains);
    filter::hanning_window(&h[0], &h[0], length);
    std::vector< std::complex<double> > td(length);
    std::vector< std::complex<double> > fd(length);
    for(std::size_t i = 0; i < length; ++i){
        td[i] = h[i];
    }
    filter::fft(&fd[0], &td[0], filter::log2(length));

    double height = PaintBox1->Height - 1;
    double width = PaintBox1->Width - 1;
    TCanvas* canvas = PaintBox1->Canvas;

    double gain = abs(fd[0]);
    canvas->Pen->Color = clBlack;
    canvas->MoveTo(0, height / 2 - (gain ? 20 * log10(gain) : -20) / 40 * height);
    for(std::size_t i = 1; i < length / 2; ++i){
        double freq = i * 44100 / length;
        gain = abs(fd[i]);
        canvas->LineTo(freq / 22050.0 * width, height / 2 - (gain ? 20 * log10(gain) : -20) / 40 * height);
    }
}
*/
//---------------------------------------------------------------------------


