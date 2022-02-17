//---------------------------------------------------------------------------

#ifndef ddWindowH
#define ddWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ddraw.h>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------



class TdirectdrawWindow : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations

int   RA, GA, BA,
  RF, GF, BF,
  RS, GS, BS,ColorShift;
BYTE   VidMem[768][1024];
LPDIRECTDRAW lpDD;
LPDIRECTDRAWSURFACE lpDDS,lpBack;
LPDIRECTDRAWCLIPPER lpDDC;
DDSURFACEDESC SD;
DDPIXELFORMAT pxFmt;
LPDIRECTDRAWPALETTE pal332;
PALETTEENTRY pe[256];


long Color;

int Xm,Ym;
char STROUT[100];


int InitDirectDraw();
void Draw(void);
void Plasma(int x,int y,int x2,int y2);
void RotatePalette(void);
int  getpixel(int X,int Y);
void putpixel(int X,int Y,BYTE Color);
void Bar(int X,int Y,int X2,int Y2,int Color);
void CalcPalette();



public:		// User declarations
        __fastcall TdirectdrawWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdirectdrawWindow *directdrawWindow;
//---------------------------------------------------------------------------
#endif
