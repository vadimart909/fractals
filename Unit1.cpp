//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "ddwindow.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TmainWindow *mainWindow;
//---------------------------------------------------------------------------
__fastcall TmainWindow::TmainWindow(TComponent* Owner)
	: TForm(Owner)
{
   frt = 0;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::N2Click(TObject *Sender)
{
HideAll();
EnableAll();
 if(frt != 0) delete frt;
 frt = new Mandel();
 Reset();
 if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Мандельброт";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TmainWindow::N31Click(TObject *Sender)
{
HideAll();
EnableAll();
 if(frt != 0) delete frt;
 frt = new Mandel3();
 Reset();
 if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Мандельброт^3";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TmainWindow::N41Click(TObject *Sender)
{
HideAll();
EnableAll();
 if(frt != 0) delete frt;
 frt = new Mandel4();
 Reset();
 if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Мандельброт^4";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::N3Click(TObject *Sender)
{
HideAll();
EnableAll();
 if(frt != 0) delete frt;
 frt = new Spider();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Паук";
Reset();
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TmainWindow::N4Click(TObject *Sender)          //Julia
{
EnableAll();
HideAll();
 if(frt != 0) delete frt;
 frt = new Julia();
Reset();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Джулия";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
JuliaBox1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TmainWindow::N6Click(TObject *Sender)
{
  Graphics::TBitmap *bm= new Graphics::TBitmap();
  bm->Width = drawWindow->ClientWidth;
  bm->Height = drawWindow->ClientHeight;
  TRect sor,tar;
  sor.Left = 0;
  sor.Top = 0;
  sor.Right = bm->Width;
  sor.Bottom = bm->Height;
  tar = sor;
  bm->Canvas->CopyRect(tar,drawWindow->Canvas,sor);
  if(SaveDialog1->Execute())
      bm->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TmainWindow::N7Click(TObject *Sender)
{
/*
Reset();
if(frt != 0) delete frt;
 frt = new Julia();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
  frt->setdisplay(drawWindow);
N6->Enabled = true;
*/
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::N8Click(TObject *Sender) // Koh
{
Panel1->Show();
ToolBar1->Show();
DisableAll();
Edit6->Enabled = true;
Label6->Enabled =true;
 Edit6->Text  = "3";
  HideAll();
if(frt != 0) delete frt;
 frt = new Koh();
Reset();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Кривая Коха";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::N9Click(TObject *Sender)
{

Panel1->Show();
ToolBar1->Show();
  HideAll();
  GroupBox1->Hide();
  DragonBox1->Top = GroupBox1->Top;
  DragonBox1->Left = GroupBox1->Left;
  DragonBox1->Show();
if(frt != 0) delete frt;
 frt = new Dragon();
 Reset();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
  drawWindow->Caption = "Кривая Дракона и другие афинные преобразования";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::ToolButton1Click(TObject *Sender)
{
if(frt != 0)frt->Draw();
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::ToolButton2Click(TObject *Sender)
{
 Reset(1);
}
//---------------------------------------------------------------------------
void TmainWindow::Reset(int v)
{
 Edit1->Text = "-2";
 Edit2->Text = "-2";
 Edit3->Text = "4";
 Edit4->Text = "4";
 Edit5->Text = "0";

 switch(frt->type)
{
case 12: Edit6->Text = "3"; break;
case 14: Edit6->Text = "17"; break;
case 100: Edit6->Text = "20"; break;

default:  Edit6->Text = "200";
}

 Edit7->Text = "20";
 Edit8->Text = "12";
 Edit9->Text = "1";

 Edit12->Text="17";
 Edit13->Text="0,5";
 Edit14->Text="0,5";
 Edit15->Text="0,5";
 Edit16->Text="0,5";
 Edit17->Text="0,5";
 Edit18->Text="0,5";
 Edit19->Text="0,5";
 Edit20->Text="0,5";
 Edit21->Text="0,5";
if( v && frt != 0 )frt->Draw();
}
//---------------------------------------------------------------------------
void TmainWindow::HideAll(void)
{
 JuliaBox1->Hide();
 DragonBox1->Hide();
 GroupBox1->Show();
 }
//---------------------------------------------------------------------------
void TmainWindow::EnableAll(void)
{
 Panel1->Show();
 ToolBar1->Show();
 Edit1->Enabled = true;
 Edit2->Enabled = true;
 Edit3->Enabled = true;
 Edit4->Enabled = true;
 Edit5->Enabled = true;
 Edit6->Enabled = true;
 Edit7->Enabled = true;
 Edit8->Enabled = true;
 Edit9->Enabled = true;
 Label1->Enabled=true;
 Label2->Enabled=true;
 Label3->Enabled=true;
 Label4->Enabled=true;
 Label5->Enabled=true;
 Label6->Enabled=true;
 Label7->Enabled=true;
 Label8->Enabled=true;
 Label9->Enabled=true;
 L1->Enabled = true;
}

//---------------------------------------------------------------------------
void TmainWindow::DisableAll(void)
{
 Edit1->Enabled = false;
 Edit2->Enabled = false;
 Edit3->Enabled = false;
 Edit4->Enabled = false;
 Edit5->Enabled = false;
 Edit6->Enabled = false;
 Edit7->Enabled = false;
 Edit8->Enabled = false;
 Edit9->Enabled = false;
 Label1->Enabled=false;
 Label2->Enabled=false;
 Label3->Enabled=false;
 Label4->Enabled=false;
 Label5->Enabled=false;
 Label6->Enabled=false;
 Label7->Enabled=false;
 Label8->Enabled=false;
 Label9->Enabled=false;
}

void __fastcall TmainWindow::N10Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::N11Click(TObject *Sender)
{
directdrawWindow = new TdirectdrawWindow(0);
}
//---------------------------------------------------------------------------


void __fastcall TmainWindow::L1Click(TObject *Sender)
{
 //if(frt != 0) delete frt;
//if(drawWindow != 0) delete drawWindow;
        lsystemWindow = new TlSystemForm(this);
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::j11Click(TObject *Sender)
{
 if(frt != 0) delete frt;
 frt = new Barnsleyj1();
Reset();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Барнсли j1";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::j21Click(TObject *Sender)
{
 if(frt != 0) delete frt;
 frt = new Barnsleyj2();
Reset();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Барнсли j2";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::j31Click(TObject *Sender)
{
 if(frt != 0) delete frt;
 frt = new Barnsleyj3();
Reset();
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Барнсли j3";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TmainWindow::N15Click(TObject *Sender)
{
 if(frt != 0) delete frt;
 frt = new Newton();
Reset();
//if(lsystemWindow != 0) delete lsystemWindow;
if(drawWindow != 0) delete drawWindow;
            drawWindow = new TdrawWindow(this);
            drawWindow->Caption = "Фрактал Ньютон";
  frt->setdisplay(drawWindow);
N6->Enabled = true;
ToolButton5->Enabled = true;
}
//---------------------------------------------------------------------------

