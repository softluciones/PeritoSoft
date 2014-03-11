//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
String DIA[100],MESES[100],HORA[100],MINUTOS[100],AMPM[100]={"AM","PM"};

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::formularXD(){
        int aux;
        for (int i=0;i<12;i++)//HORAS,MESES
        {
                if(i<9){
                        MESES[i]=HORA[i]="0";
                        aux=i+1;
                        MESES[i]=HORA[i]+=aux;
                }else{
                        aux=i+1;
                        MESES[i]=HORA[i]+=aux;
                }
        }
        for (int i=0;i<31;i++)//dias
        {
                if(i<9){
                        DIA[i]="0";
                        aux=i+1;
                        DIA[i]+=aux;
                }else{
                        aux=i+1;
                        DIA[i]+=aux;
                }
        }

        for (int i=0;i<59;i++)//MINUTOS
        {
                if(i<9){
                        MINUTOS[i]="0";
                        aux=i+1;
                        MINUTOS[i]+=aux;
                }else{
                        aux=i+1;
                        MINUTOS[i]+=aux;
                }
        }

}

void __fastcall TForm3::Image3Click(TObject *Sender)
{
        Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::super(String sms){

        MessageDlg(sms, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
void __fastcall TForm3::Image2Click(TObject *Sender)
{
        if(ComboBox1->ItemIndex!=-1){
                if(ComboBox2->ItemIndex!=-1){
                        if(!Edit1->Text.IsEmpty()&&Edit1->Text.Length()==4){
                                if(!ComboBox3->ItemIndex!=-1){
                                        if(!ComboBox4->ItemIndex!=-1){
                                                if(ComboBox5->ItemIndex!=-1){
                                                        if(!Edit2->Text.IsEmpty()){
                                                                if(!Memo1->Text.IsEmpty()){
                                                                        if(!Edit3->Text.IsEmpty()){
                                                                                if(ComboBox6->ItemIndex!=-1){
                                                                                        if(ComboBox7->ItemIndex!=1){

                                                                                        }else{
                                                                                                super("Ingrese Mes del acta");
                                                                                        }
                                                                                }else{
                                                                                        super("Seleccione Hora de ejecuci�n del acta");
                                                                                }
                                                                        }else{
                                                                                super("Ingrese o haga Clic para generar el Numero de Experticia");
                                                                        }
                                                                }else{
                                                                        super("Ingrese Direcci�n donde fue el accidente");
                                                                }
                                                        }else{
                                                            super("Ingrese Valor aproximado en Da�os")
                                                        }
                                                }else{
                                                        super("Seleccione si es AM o PM");
                                                }
                                        }else{
                                                super("Selecione minutos del accidente");
                                        }
                                }else{
                                        super("Seleccione Hora del accidente");
                                }
                        }else{
                                super("Ingrese a�o del accidente. Deben aparecer 4 digitos. Ejem: 1950");
                        }
                }else{
                        super("Seleccione Mes de accidente");
                }
        }else{
                super("Seleccione Dia del accidente");
        }
}
//---------------------------------------------------------------------------

