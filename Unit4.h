//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TLabel *Label1;
    TEdit *FileName;
    TLabel *Label2;
    TEdit *Written;
    TButton *CloseButton;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
    __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
