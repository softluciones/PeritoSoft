//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        codigo[0]="0414";
        codigo[1]="0424";
        codigo[2]="0416";
        codigo[3]="0426";
        codigo[4]="0276";
        for (int i=0;i<=codigo->Length();i++)
        {
                ComboBox1->Items->Add(codigo[i]);
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Edit2KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=toupper(Key);
        }else{
                Key=NULL;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit4KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=toupper(Key);
        }else{
                Key=NULL;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Memo1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image3Click(TObject *Sender)
{
        Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8)
                Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit3KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8)
                Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit5KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8)
                Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image4Click(TObject *Sender)
{
        MessageDlg("Ejemplo Cedula Conductor: 17877864 (solo numeros)\n\n"
                   "Ejemplo Nombre Conductor: Luis Perez (solo letras)\n\n"
                   "Ejemplo Cedula Propietario: 17827822 (solo numero)\n\n"
                   "Ejemplo Nombre Conductor: Carlos Perez (solo letras)\n\n"
                   "Ejemplo Telefono Propietario: 04141234567 (Solo numeros)\n\n"
                   "Ejemplo Direcci�n: Urb Merida 100-24 (Texto y numeros)\n\n"
                   "Los datos se ingresan as� y autom�ticamente adquieren formato una vez guardado", mtInformation, TMsgDlgButtons() << mbOK, 0);        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2Click(TObject *Sender)
{
        String cadena, total;
        int totals=0;
        if(!Edit1->Text.IsEmpty()){
                if(!Edit2->Text.IsEmpty()){
                        if(!Edit3->Text.IsEmpty()){
                                if(!Edit4->Text.IsEmpty()){
                                        if(ComboBox1->ItemIndex!=-1){
                                                if(!Edit5->Text.IsEmpty()){
                                                        if(!Memo1->Text.IsEmpty()){
                                                                        Form1->activado=1;
                                                                        Edit1->Text=FormatFloat("##,###,###",Edit1->Text.ToDouble());
                                                                        Edit3->Text=FormatFloat("##,###,###",Edit3->Text.ToDouble());
                                                                        Edit5->Text=codigo[ComboBox1->ItemIndex]+"-"+Edit5->Text;
                                                                        cadena="select count(*) as total from conductores";
                                                                        Query1->Close();
                                                                        Query1->SQL->Clear();
                                                                        Query1->SQL->Add(cadena);
                                                                        Query1->Active=true;
                                                                        totals=Query1->FieldByName("total")->Value;
                                                                        totals++;
                                                                        total=totals;
                                                                        cadena="insert into conductores values("+total+",'"+Edit2->Text+"','"+Edit1->Text+"','"+Edit4->Text+"','"+Edit3->Text+"','"+Memo1->Text+"','"+Edit5->Text+"')";
                                                                        Query1->Close();
                                                                        Query1->SQL->Clear();
                                                                        Query1->SQL->Add(cadena);
                                                                        Query1->ExecSQL();
                                                                        MessageDlg("Datos Guardados Con �xito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                        Form1->Label5->Caption=Edit2->Text;//nombre conductor
                                                                        Form1->Label7->Caption=Edit1->Text;//cedula conductor
                                                                        Form1->Label9->Caption=Edit4->Text;//nombre propietario
                                                                        Form1->Label11->Caption=Edit3->Text;//cedula propietario
                                                                        Form1->Label13->Caption=Edit5->Text;//telefono
                                                                        Form1->Label15->Caption=Memo1->Text;//direcci�n
                                                                        Form1->Label17->Caption=total;//id
                                                                        Edit1->Clear();
                                                                        Edit2->Clear();
                                                                        Edit3->Clear();
                                                                        Edit4->Clear();
                                                                        Edit5->Clear();
                                                                        Memo1->Clear();
                                                                        Form2->Close();
                                                        }else{
                                                                MessageDlg("Falta la Direcci�n del Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                        }
                                                }else{
                                                        MessageDlg("Ingrese Numero de telefono del propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                }
                                        }else{
                                                MessageDlg("Seleccione Codigo telefono Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                        }
                                }else{
                                        MessageDlg("Ingrese Nombre del Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                }
                        }else{
                                MessageDlg("Ingrese cedula del Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        }
                }else{
                        MessageDlg("Ingrese el nombre del conductor", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("Ingrese la cedula del conductor", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------
