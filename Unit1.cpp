//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        activado=0;
        rellenar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rellenar(){
        Form1->Left=0;
        Form1->Top=0;
        int i=0,y,j=0;
        String x="select * from autopartes",var;

        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(x);
        Query1->Active=true;

        Query1->First();
        while(!Query1->Eof){

                y=Query1->FieldByName("tipoautoparte_id")->Value;
                if(y==1){
                        var=Query1->FieldByName("nombre")->Value;
                        CheckListBox1->Items->Add(var.UpperCase());
                        reparar[i]=var.UpperCase();
                        idreparar[i]=Query1->FieldByName("id")->Value;
                        i++;
                }else{
                        var=Query1->FieldByName("nombre")->Value;
                        CheckListBox2->Items->Add(var.UpperCase());
                        cambiar[j]=var.UpperCase();
                        idcambiar[j]=Query1->FieldByName("id")->Value;
                        j++;
                }
                Query1->Next();
        }
        totalreparar=i;
        totalcambiar=j;
}
//--------------Agregar Conductor'-------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{
        Form2->ShowModal();
        Form2->ban=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image4Click(TObject *Sender)
{
       if(activado==2){
        Form3->ShowModal();
       }else{
        MessageDlg("Debes registrar el vehiculo primero", mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
       if(activado==1){
        Form4->marca();
        Form4->colores();
        Form4->tipo();
        Form4->ShowModal();
       }else{
        MessageDlg("Debes registrar el conductor primero", mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
}
//---------------------------------------------------------------------------


