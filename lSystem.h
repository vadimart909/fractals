//---------------------------------------------------------------------------

#ifndef lSystemH
#define lSystemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "flatpoint.h"

//---------------------------------------------------------------------------
class TlSystemForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit4;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit5;
        TEdit *Edit6;
        TLabel *Label6;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
  double x0,y0,l,vx,vy;
  char *Axiom;
  char *Formula;
  double Angle;
  int Iter;
  double PointNum;
  FlatPoint *FirstPoint;
void Draw();
void Iterator(int N,FlatPoint* SPoint,double l);
void DrawLine(int x,int y,int x2,int y2);
void SetParameters();
void CalcElementPoints();
void SetDisplay(int SetCenter=0);
public:		// User declarations
        __fastcall TlSystemForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TlSystemForm *lSystemForm;
//---------------------------------------------------------------------------
#endif
