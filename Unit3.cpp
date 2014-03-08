//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Image3Click(TObject *Sender)
{
        Form3->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit2KeyPress(TObject *Sender, char &Key)
{
        Edit1KeyPress(Sender,Key);
        if(Key==13){
                Edit2Enter(Sender);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Memo1KeyPress(TObject *Sender, char &Key)
{
        Edit1KeyPress(Sender,Key);        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Memo2KeyPress(TObject *Sender, char &Key)
{
        Edit1KeyPress(Sender,Key);        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2Click(TObject *Sender)
{

        if(!Edit2->Text.IsEmpty()){
                if(!Memo1->Text.IsEmpty()){
                        if(!Memo2->Text.IsEmpty()){
                                if(!Edit3->Text.IsEmpty()){
                                        if(!Edit4->Text.IsEmpty()){
                                                if(!Edit5->Text.IsEmpty()){
                                                        String cadena,fechaaccidente,hora;
                                                        ComboBox4->Text
                                                        fechaaccidente=
                                                        cadena="insert into accidente values(null,)";
                                                }else{
                                                        MessageDlg("Ingrese el a�o de la fecha del accidente", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                }
                                        }else{
                                                MessageDlg("ingrese el a�o del acta de avaluo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                        }
                                }else{
                                        MessageDlg("Ingrese valor monetario aproximado en da�os", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                }
                        }else{
                                MessageDlg("Ingrese lugar del accidente", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        }
                }else{
                        MessageDlg("Ingrese lugar de inspecci�n", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("Ingrese numero de experticia", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Edit4KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8){
                Key=NULL;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Edit5KeyPress(TObject *Sender, char &Key)
{
        Edit4KeyPress(Sender,Key);        
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Edit2Enter(TObject *Sender)
{
        String cadena="select count(*) total from avaluo",nombre,apellido,x,y;

        int total=0;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        total=Query1->FieldByName("total")->Value;
        total++;
        cadena="select * from perito";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        nombre=Query1->FieldByName("nombre")->Value;
        apellido=Query1->FieldByName("apellido")->Value;
        x=nombre.c_str()[0];
        x+=apellido.c_str()[0];
        if(total<100){
                if(total<10){
                        y="0";
                        y+="0";
                        y+=total;
                        y+="/"+x;

                }else{
                        
                        y+="0";
                        y+=total;
                        y+="/"+x;
                }
        }else{
                y=total;
                y+="/";
                y+=x;
        }
        Edit2->Text=y;



}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit2Click(TObject *Sender)
{
        Edit2Enter(Sender);        
}
//---------------------------------------------------------------------------

