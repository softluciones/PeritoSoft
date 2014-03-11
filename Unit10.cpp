//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
String estados[100]={"AMAZONAS.",
"ANZO�TEGUI.",
"APURE.",
"ARAGUA.",
"BARINAS.",
"BOL�VAR.",
"CARABOBO.",
"COJEDES.",
"DELTA AMACURO.",
"DISTRITO FEDERAL.",
"FALC�N.",
"GU�RICO.",
"LARA.",
"M�RIDA.",
"MIRANDA.",
"MONAGAS.",
"NUEVA ESPARTA.",
"PORTUGUESA.",
"SUCRE.",
"T�CHIRA.",
"VARGAS.",
"YARACUY.",
"ZULIA.",
};
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
        : TForm(Owner)
{
        ComboBox1->Clear();
        ComboBox1->Text="Estado...";
        for (int i=0;i<23;i++)
        {
                ComboBox1->Items->Add(estados[i]);
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm10::Image4Click(TObject *Sender)
{
        exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=toupper(Key);
        }
        else{
                Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit2KeyPress(TObject *Sender, char &Key)
{
        Edit1KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit3KeyPress(TObject *Sender, char &Key)
{
        Edit2KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit4KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8){
            Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit5KeyPress(TObject *Sender, char &Key)
{
        Edit4KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

