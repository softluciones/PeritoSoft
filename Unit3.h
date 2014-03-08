//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TPanel *Panel2;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TPanel *Panel3;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TMemo *Memo1;
        TPanel *Panel4;
        TLabel *Label5;
        TMemo *Memo2;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label10;
        TEdit *Edit3;
        TQuery *Query1;
        TComboBox *ComboBox1;
        TLabel *Label8;
        TComboBox *ComboBox2;
        TLabel *Label9;
        TEdit *Edit4;
        TComboBox *ComboBox3;
        TLabel *Label11;
        TComboBox *ComboBox4;
        TLabel *Label12;
        TEdit *Edit5;
        TComboBox *ComboBox5;
        TLabel *Label13;
        TComboBox *ComboBox6;
        TComboBox *ComboBox7;
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Memo1KeyPress(TObject *Sender, char &Key);
        void __fastcall Memo2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2Enter(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
