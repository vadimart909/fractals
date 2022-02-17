//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Menus.hpp>
#include "Unit4.h"
#include "lSystem.h"
#include <vcl\Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TmainWindow : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;

	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TSaveDialog *SaveDialog1;
        TMenuItem *Ghy1;
        TMenuItem *N8;
        TMenuItem *N9;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TPanel *Panel1;
        TGroupBox *JuliaBox1;
        TLabel *Label10;
        TEdit *Edit10;
        TEdit *Edit11;
        TLabel *Label11;
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TLabel *Label9;
        TLabel *Label8;
        TLabel *Label7;
        TLabel *Label6;
        TLabel *Label5;
        TLabel *Label4;
        TLabel *Label3;
        TLabel *Label2;
        TLabel *Label1;
        TGroupBox *DragonBox1;
        TLabel *Label24;
        TLabel *Label23;
        TLabel *Label20;
        TLabel *Label19;
        TLabel *Label18;
        TLabel *Label17;
        TLabel *Label16;
        TLabel *Label15;
        TEdit *Edit21;
        TEdit *Edit20;
        TEdit *Edit19;
        TEdit *Edit18;
        TEdit *Edit17;
        TEdit *Edit16;
        TEdit *Edit15;
        TEdit *Edit14;
        TEdit *Edit12;
        TLabel *Label12;
        TMenuItem *N10;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TEdit *Edit13;
        TLabel *Label13;
        TMenuItem *N11;
        TMenuItem *N41;
        TMenuItem *N31;
        TMenuItem *L1;
        TMenuItem *j11;
        TGroupBox *Barnj1Box1;
        TEdit *Edit22;
        TEdit *Edit23;
        TLabel *Label14;
        TLabel *Label21;
        TEdit *Edit24;
        TLabel *Label22;
        TMenuItem *j21;
        TMenuItem *N12;
        TMenuItem *j31;
        TMenuItem *N13;
        TMenuItem *N15;
        TGroupBox *NewtonBox1;
        TLabel *Label25;
        TEdit *Edit25;
	void __fastcall N2Click(TObject *Sender);

	void __fastcall N3Click(TObject *Sender);

	void __fastcall N4Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N41Click(TObject *Sender);
        void __fastcall N31Click(TObject *Sender);
        void __fastcall L1Click(TObject *Sender);
        void __fastcall j11Click(TObject *Sender);
        void __fastcall j21Click(TObject *Sender);
        void __fastcall j31Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
private:	// User declarations
void Reset(int v=0);
void HideAll(void);
void EnableAll(void);
void DisableAll(void);
public:		// User declarations
   TdrawWindow *drawWindow;
   TlSystemForm *lsystemWindow;
   Frt *frt;
	__fastcall TmainWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TmainWindow *mainWindow;
//---------------------------------------------------------------------------
#endif
