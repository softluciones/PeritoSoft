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

void __fastcall TForm10::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                if(!Edit2->Text.IsEmpty()){
                        if(!Edit3->Text.IsEmpty()){
                                if(!Edit4->Text.IsEmpty()){
                                        if(!Edit5->Text.IsEmpty()){
                                                if(ComboBox1->ItemIndex!=-1){
                                                        if(!Edit6->Text.IsEmpty()){
                                                                Edit4->Text=FormatFloat("##,###,###",Edit4->Text.ToDouble());
                                                                String cadena,aca;
                                                                int total=0;
                                                                cadena="select count(*) total from perito";
                                                                Query1->Close();
                                                                Query1->SQL->Clear();
                                                                Query1->SQL->Add(cadena);
                                                                Query1->Active=true;
                                                                total=Query1->FieldByName("total")->Value;
                                                                total++;
                                                                aca=total;
                                                                cadena="INSERT INTO perito VALUES("+aca+",'"+Edit1->Text+"','"+Edit2->Text+"','"+Edit3->Text+"','"+Edit4->Text+"','"+(Edit5->Text+" "+estados[ComboBox1->ItemIndex])+"','"+Edit6->Text+"')";
                                                                Query1->Close();
                                                                Query1->SQL->Clear();
                                                                Query1->SQL->Add(cadena);
                                                                Query1->ExecSQL();
                                                                MessageDlg("Agregado con �xito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                Form10->Close();
                                                        }else{
                                                                MessageDlg("Ingrese codigo del perito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                        }

                                                }else{
                                                        MessageDlg("Seleccione el estado", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                }
                                        }else{
                                                MessageDlg("Ingresa tu unidad", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                        }
                                }else{
                                        MessageDlg("Ingresa tu cedula", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                }
                        }else{
                                MessageDlg("Ingresa Profesi�n", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        }
                }else{
                        MessageDlg("Registra tus Apellidos", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("Registra tu nombre completo", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit6KeyPress(TObject *Sender, char &Key)
{
        Edit4KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

