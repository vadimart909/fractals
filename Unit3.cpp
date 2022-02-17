//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <vcl\graphics.hpp>
#include <math.h>
#include <dstring.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TdrawWindow::TdrawWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdrawWindow::FormPaint(TObject *Sender)
{
mainWindow->frt->Draw();
}
//---------------------------------------------------------------------------
void __fastcall TdrawWindow::FormResize(TObject *Sender)
{
mainWindow->frt->Draw();
}
//---------------------------------------------------------------------------
void __fastcall TdrawWindow::FormMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
   if(Shift.Contains(ssShift)){
    xs = mainWindow->Edit1->Text.ToDouble();
    ys =mainWindow->Edit2->Text.ToDouble();
    w  =mainWindow->Edit3->Text.ToDouble();
    h  =mainWindow->Edit4->Text.ToDouble();
	x0 = X;
    y0 = Y;
    drag_mouse =3;
    x1 = x0;
    y1= y0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TdrawWindow::FormMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
if(drag_mouse){
double Xm=X,Ym=Y;
   drag_mouse = 0;
    /*
	x0 = xs+w*x0/Width;
    y0 = ys+h*x0/Height;
	x1 = xs+w*X/Width-x0;
    y1 = ys+h*Y/Height-y0;
     */
    double buf;
        if(x0 > Xm){ buf = x0; x0= Xm; Xm=buf;
        buf = y0; y0= Ym; Ym=buf;
        }
x1 = w*(Xm-x0)/ClientWidth;
    y1 = h*(Ym-y0)/ClientHeight;
	x0 = xs+w*(x0)/ClientWidth;
    y0 = ys+h*(y0)/ClientHeight;

    mainWindow->Edit1->Text = * new AnsiString(x0);
    mainWindow->Edit2->Text = * new AnsiString(y0);
    mainWindow->Edit3->Text = * new AnsiString(x1);
    mainWindow->Edit4->Text = * new AnsiString(y1);
Canvas->Pen->Mode = pmCopy;
    mainWindow->frt->Draw();
   }
}
//---------------------------------------------------------------------------
void __fastcall TdrawWindow::FormMouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y)
{
if(drag_mouse)
{
Canvas->Pen->Mode = pmXor;
 Canvas->Rectangle(x0,y0,x1,y1);
 x1 = X;
 y1 = Y;
 Canvas->Rectangle(x0,y0,x1,y1);
Canvas->Pen->Mode = pmCopy;
}
}
//---------------------------------------------------------------------------

void __fastcall TdrawWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
this->DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TdrawWindow::FormActivate(TObject *Sender)
{
mainWindow->Panel1->Show();
mainWindow->ToolBar1->Show();

}
//---------------------------------------------------------------------------

