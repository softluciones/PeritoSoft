//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <jpeg.hpp>
#include <DBCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMainMenu *MainMenu1;
        TMenuItem *menu11;
        TMenuItem *menu21;
        TMenuItem *Autopartes1;
        TMenuItem *NuevaActa1;
        TPanel *Panel2;
        TPanel *Panel3;
        TSplitter *Splitter2;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel7;
        TDatabase *Database1;
        TTable *Table1;
        TDataSource *DataSource1;
        TQuery *Query1;
        TDataSource *DataSource2;
        TPanel *Panel8;
        TLabel *Label1;
        TPanel *Panel9;
        TLabel *Label2;
        TCheckListBox *CheckListBox1;
        TCheckListBox *CheckListBox2;
        TSplitter *Splitter3;
        TSplitter *Splitter4;
        TPanel *Panel10;
        TPanel *Panel11;
        TPanel *Panel12;
        TPanel *Panel4;
        TLabel *Label3;
        TPanel *Panel13;
        TImage *Image5;
        TPanel *Panel14;
        TImage *Image3;
        TImage *Image2;
        TImage *Image1;
        TImage *Image4;
        TPanel *Panel15;
        TPanel *Panel16;
        TPanel *Panel17;
        TPanel *Panel18;
        TImage *Image6;
        TPanel *Panel19;
        TLabel *Label4;
        TQuery *Query2;
        TDataSource *DataSource3;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TPanel *Panel20;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TMenuItem *PeritoAvaluador1;
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        String reparar[30000];
        int idreparar[30000],totalreparar;
        String cambiar[30000];
        int activado;
        int idcambiar[30000],totalcambiar;
        __fastcall TForm1(TComponent* Owner);
void __fastcall rellenar();
void __fastcall llamalo();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
