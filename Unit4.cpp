//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
#include "ctype.h"
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
void __fastcall TForm4::marca()
{
        String consulta="select * from marca",marquita;
        int id=0;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox1->Clear();
        ComboBox1->Text="Seleccione";
        MARCA=0;
        Query1->First();
        while(!Query1->Eof){
                marquita=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Marca[MARCA][0]=marquita;
                Marca[MARCA][1]=id;
                ComboBox1->Items->Add(marquita);
                MARCA++;
                Query1->Next();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image3Click(TObject *Sender)
{
        Form4->Close();
        ComboBox1->Clear();
        ComboBox2->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image5Click(TObject *Sender)
{
        Form5->ShowModal();
}
//--------------------------- ------------------------------------------------

void __fastcall TForm4::Image6Click(TObject *Sender)
{
        AnsiString x;
        if(ComboBox1->ItemIndex!=-1){
                Form6->Label2->Caption=""+Marca[ComboBox1->ItemIndex][0]+"";
                x=Marca[ComboBox1->ItemIndex][1];
                Form6->marca_id=x;
                Form6->ShowModal();
        }
        else
                MessageDlg("Seleccione una marca de vehiculo antes de agregar un modelo", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::modelo(){
        String consulta="select * from modelo where marca_id="+Marca[ComboBox1->ItemIndex][1]+"",modelito;
        int id=0;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox2->Clear();
        ComboBox2->Text="Seleccione";
        MODELO=0;
        Query1->First();
        while(!Query1->Eof){
                modelito=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Modelo[MODELO][0]=modelito;
                Modelo[MODELO][1]=id;
                ComboBox2->Items->Add(modelito);
                MODELO++;
                Query1->Next();
        }
}
void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
        modelo();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::colores()
{
        String consulta="select * from color",Colors;
        int id;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox4->Clear();
        ComboBox4->Text="Seleccione";
        COLOR=0;
        Query1->First();
        while(!Query1->Eof){
                Colors=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Modelo[COLOR][0]=Colors;
                Modelo[COLOR][1]=id;
                ComboBox4->Items->Add(Colors);
                COLOR++;
                Query1->Next();
        }
}
//--------------------------------------------------------------
void __fastcall TForm4::Image8Click(TObject *Sender)
{
        Form7->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::tipo(){
        String consulta="select * from tipo",Tipos;
        int id;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox3->Clear();
        ComboBox3->Text="Seleccione";
        TIPO=0;
        Query1->First();
        while(!Query1->Eof){
                Tipos=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Tipo[TIPO][0]=Tipos;
                Tipo[TIPO][1]=id;
                ComboBox3->Items->Add(Tipos);
                TIPO++;
                Query1->Next();
        }
}


void __fastcall TForm4::Image7Click(TObject *Sender)
{
        Form8->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image9Click(TObject *Sender)
{
        Form9->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit2KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit3KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit4KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit5KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------
