//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <string.h>
#pragma hdrstop

#include "lSystemWork.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TlSystemForm *lSystemForm;
//---------------------------------------------------------------------------
__fastcall TlSystemForm::TlSystemForm(TComponent* Owner)
        : TForm(Owner)
{
 x0 =200;
 y0= 300;
Angle = 60;
l = 60;
vx = 1;
vy = 0;
Iter = 4;
PointNum = 3;
Formula = new char[1000];
Axiom = new char[1000];
strcpy(Formula,"f+f--f+f");
strcpy(Axiom,"f");
FirstPoint = new FlatPoint(0,0);
FirstPoint->vx=1;
FirstPoint->vy=0;

SetParameters();
}
//---------------------------------------------------------------------------
void TlSystemForm::Iterator(int N,FlatPoint* SPoint,double l)
{
int i;
double nx,ny;
FlatPoint *CurrentPoint = SPoint ;
 for(i=0;i<strlen(Formula);i++)
 {
switch(Formula[i])
{
case 'f':
CurrentPoint->Insert2(new FlatPoint(CurrentPoint->x+CurrentPoint->vx*l,
                                    CurrentPoint->y+CurrentPoint->vy*l));
CurrentPoint = CurrentPoint->next;
CurrentPoint->vx = CurrentPoint->prev->vx;
CurrentPoint->vy = CurrentPoint->prev->vy;
break;
case '+':
           nx = cos(-M_PI/180*Angle)*CurrentPoint->vx+
                sin(-M_PI/180*Angle)*CurrentPoint->vy;
           ny = cos(-M_PI/180*Angle)*CurrentPoint->vy-
                sin(-M_PI/180*Angle)*CurrentPoint->vx;
           CurrentPoint->vx = nx;
           CurrentPoint->vy = ny;
break;
case '-':
           nx = cos(M_PI/180*Angle)*CurrentPoint->vx+sin(M_PI/180*Angle)*CurrentPoint->vy;
           ny = cos(M_PI/180*Angle)*CurrentPoint->vy-sin(M_PI/180*Angle)*CurrentPoint->vx;
           CurrentPoint->vx = nx;
           CurrentPoint->vy = ny;
} // end of switch
 } // end of for i=0
CurrentPoint = CurrentPoint->prev;
 if(N>1)
 while(CurrentPoint != 0)
 {
 Iterator(N-1,CurrentPoint,l/PointNum);
 CurrentPoint = CurrentPoint->prev;
 }
}
//---------------------------------------------------------------------------
void TlSystemForm::Draw()
{
Canvas->Brush->Color = 0;
Canvas->Pen->Color = 0;
 int i,j,IterCount;
 double nx,ny;
 FlatPoint *CurrentPoint = FirstPoint;
for(j=0;j<strlen(Axiom);j++)
{
switch(Axiom[j])
{
case 'f':

     Iterator(Iter,CurrentPoint,l);
     CurrentPoint =FirstPoint;
      while(CurrentPoint->next != 0)CurrentPoint=CurrentPoint->next;
break;
case '+':
           nx = cos(-M_PI/180*Angle)*CurrentPoint->vx+sin(-M_PI/180*Angle)*CurrentPoint->vy;
           ny = cos(-M_PI/180*Angle)*CurrentPoint->vy-sin(-M_PI/180*Angle)*CurrentPoint->vx;
           CurrentPoint->vx = nx;
           CurrentPoint->vy = ny;
break;
case '-':
           nx = cos(M_PI/180*Angle)*CurrentPoint->vx+sin(M_PI/180*Angle)*CurrentPoint->vy;
           ny = cos(M_PI/180*Angle)*CurrentPoint->vy-sin(M_PI/180*Angle)*CurrentPoint->vx;
           CurrentPoint->vx = nx;
           CurrentPoint->vy = ny;
  } // end of switch
     CurrentPoint=FirstPoint;
while(CurrentPoint->next != 0)
{
   DrawLine(CurrentPoint->x,CurrentPoint->y,
            CurrentPoint->next->x,CurrentPoint->next->y);
            CurrentPoint = CurrentPoint->next;
  }
FirstPoint->ClearConnections();
  } // end of for j=0
}
//---------------------------------------------------------------------------
void TlSystemForm::DrawLine(int x,int y,int x2,int y2)
{
Canvas->MoveTo(x0+x,y0-y);
Canvas->LineTo(x0+x2,y0-y2);
}
//---------------------------------------------------------------------------
void TlSystemForm::SetParameters()
{
Angle = Edit1->Text.ToDouble();
l = Edit4->Text.ToDouble();
FirstPoint->vx= 1;
FirstPoint->vy= 0;

strcpy(Axiom,Edit2->Text.c_str());
strcpy(Formula,Edit3->Text.c_str());
Iter = Edit5->Text.ToDouble();

//CalcElementPoints();
PointNum =Edit6->Text.ToDouble();
}
//---------------------------------------------------------------------------
void TlSystemForm::CalcElementPoints()
{
int j;
PointNum = -1;
for(j=0;j<strlen(Formula);j++)
{
 if(Formula[j] == 'F')PointNum++;
}
}
//---------------------------------------------------------------------------
void __fastcall TlSystemForm::Button1Click(TObject *Sender)
{
SetParameters();
SetDisplay();
         Draw();
}
//---------------------------------------------------------------------------
void __fastcall TlSystemForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
this->DestroyWnd();
}
//---------------------------------------------------------------------------
void TlSystemForm::SetDisplay()
{
x0 = ClientWidth / 2;
y0 = (ClientHeight-Panel1->Height) /2+Panel1->Height;
Canvas->Brush->Color = 0xFFFFFF;
Canvas->Pen->Color = 0xFFFFFF;
Canvas->Rectangle(0,0,ClientWidth,ClientHeight);

Canvas->Brush->Color = 0xFF0000;
Canvas->Pen->Color = 0xFF0000;
Canvas->MoveTo(x0,0);
Canvas->LineTo(x0,ClientHeight);

Canvas->Brush->Color = 0xFF00FF;
Canvas->Pen->Color = 0x0000FF;
Canvas->MoveTo(0,y0);
Canvas->LineTo(ClientWidth,y0);
}

void __fastcall TlSystemForm::FormPaint(TObject *Sender)
{
SetDisplay();
}
//---------------------------------------------------------------------------

void __fastcall TlSystemForm::FormResize(TObject *Sender)
{
SetDisplay();
Draw();
}
//---------------------------------------------------------------------------

