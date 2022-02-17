//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "ddWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdirectdrawWindow *directdrawWindow;
//---------------------------------------------------------------------------
__fastcall TdirectdrawWindow::TdirectdrawWindow(TComponent* Owner)
        : TForm(Owner)
{
lpDD = 0;
lpDDS = 0;
lpBack=0;
lpDDC=0;
Color = 255;
randomize();

  RA = 16 + random(16);
  GA = 16 + random(16);
  BA = 16 + random(16);

  RF = 2 + random(5);
  GF = 2 + random(5);
  BF = 2 + random(5);

  RS = random(64);
  GS = random(64);
  BS = random(64);
ColorShift = 0;
if(InitDirectDraw());
Draw();
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void TdirectdrawWindow::CalcPalette()
{
  for(int i=0;i<256;i++)
  {

  pe[i].peRed= 82 + RA * sin((RS + i * RF) * M_PI / 128);
  pe[i].peGreen =82 + GA * sin((GS + i* GF) * M_PI / 128);
  pe[i].peBlue = 82 + BA * sin((BS + i * BF) * M_PI / 128);
   /*
  pe[i].peRed= 256-i;
  pe[i].peGreen =i;
  pe[i].peBlue = 0;
  */
}

 lpDD->CreatePalette(DDPCAPS_8BIT,pe,&pal332,0);
 lpDDS->SetPalette(pal332);
}
//---------------------------------------------------------------------------

void TdirectdrawWindow::Bar(int X,int Y,int X2,int Y2,int Color)
{
 			DDBLTFX BBFX;
			ZeroMemory(&BBFX,sizeof(BBFX));
			BBFX.dwSize = sizeof(BBFX);
			BBFX.dwFillColor=Color;
			RECT rt;
			rt.top = Y;
			rt.left = X;
			rt.bottom=Y2;
			rt.right=X2;
    			lpDDS->Blt(&rt,0,0,DDBLT_COLORFILL,&BBFX);
}
//---------------------------------------------------------------------------

void TdirectdrawWindow::putpixel(int X,int Y,BYTE Color)
{
if(X>=0 && Y>=0 && X<=1023 && Y <=767)
{
 			DDBLTFX BBFX;
			ZeroMemory(&BBFX,sizeof(BBFX));
			BBFX.dwSize = sizeof(BBFX);
			BBFX.dwFillColor=Color;
			RECT rt;
			rt.top = Y;
			rt.left = X;
			rt.bottom=Y+1;
			rt.right=X+1;
    			lpBack->Blt(&rt,0,0,DDBLT_COLORFILL,&BBFX);
				VidMem[Y][X] = Color;
}
}
//---------------------------------------------------------------------------

int TdirectdrawWindow::getpixel(int X,int Y)
{
if(X>=0 && Y>=0 && X<=1023 && Y <=767)
{
	return VidMem[Y][X];
}
else return 0;
}

//======================================================RotatePalette
void TdirectdrawWindow::RotatePalette(void)
{
/*
	PALETTEENTRY pl[256];
	PALETTEENTRY p1;
 pal332->GetEntries(0,0,256,pl);
 p1 = pl[0];
 memmove(&pl[0],&pl[1],255*4);
 pl[254]=p1;
pal332->SetEntries(0,0,256,pl);
 */

   for(int i=0;i<256;i++)
  {

  pe[i].peRed= 82 + RA * sin((RS + (i+ColorShift) * RF) * M_PI / 128);
  pe[i].peGreen =82 + GA * sin((GS + (i+ColorShift)* GF) * M_PI / 128);
  pe[i].peBlue = 82 + BA * sin((BS + (i+ColorShift)* BF) * M_PI / 128);
   /*
  pe[i].peRed= 256-i;
  pe[i].peGreen =i;
  pe[i].peBlue = 0;
  */
}
ColorShift++;
if(ColorShift == 256)ColorShift = 0;
pal332->SetEntries(0,0,256,pe);
}


//---------------------------------------------------------------------------

void TdirectdrawWindow::Plasma(int x,int y,int x2,int y2)
{
  int xm = (x2+x)/2,ym = (y2+y)/2;
 int i,j;

double n = (x2-x)/8;
double   n2 = (y2-y)/8;
double R=0.9;
double Rnd = random(n+n2)*R;

unsigned char color1 = (getpixel(x,y)+getpixel(x2,y2)+getpixel(x2,y)+getpixel(x,y2))/4+Rnd;
//Rnd = Random(n2)*R;
unsigned char color2 = (getpixel(x,y)+getpixel(x2,y))/2+Rnd;
//Rnd = Random(n)*R;
unsigned char color3 = (getpixel(x2,y)+getpixel(x2,y2))/2+Rnd;
//Rnd = Random(n2)*R;
unsigned char color4 = (getpixel(x,y2)+getpixel(x2,y2))/2+Rnd;
//Rnd = Random(n)*R;
unsigned char color5 = (getpixel(x,y)+getpixel(x,y2))/2+Rnd;

//color1 = (color1+color2+color3+color4)/4;


 putpixel(xm,ym,color1);

	if(getpixel(xm,y)==0)
		putpixel(xm,y,color2);

if(getpixel(xm,y2)==0)
    putpixel(xm,y2,color4);

	if(getpixel(x,ym)==0)
		putpixel(x,ym,color5);
if(getpixel(x2,ym)==0)
	putpixel(x2,ym,color3);





 if(y2-y > 1)
 {
  Plasma(x,ym,xm,y2);
  Plasma(x,y,xm,ym);
  Plasma(xm,y,x2,ym);
  Plasma(xm,ym,x2,y2);
 }

}

//---------------------------------------------------------------------------

int TdirectdrawWindow::InitDirectDraw()
{
	HRESULT hr;

   if(FAILED(hr = DirectDrawCreate(NULL,&lpDD,NULL) ) )
   {
   return 0 ;
  }

  if(FAILED(hr = lpDD->SetCooperativeLevel(Handle,DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN)))
   {
   MessageBox(NULL,"Error? Setting Cooperative Level!!!","test",MB_OK);
   return 0 ;
   }
//===============================================Display Mode Change
lpDD->SetDisplayMode(640,480,8);

   memset(&SD,0,sizeof(SD));
   SD.dwSize = sizeof(SD);
  SD.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
 SD.dwBackBufferCount = 1;
   SD.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP | DDSCAPS_COMPLEX;
   if(FAILED(hr = lpDD->CreateSurface(&SD,&lpDDS,0)))
   {
	MessageBox(NULL,"Error? creating Primary Surface!!!","test",MB_OK);
    return 0 ;
   }


//==============================================================================
/*
   if(FAILED(hr = lpDD->CreateClipper(0,&lpDDC,NULL) ) )
   {
   MessageBox(NULL,"Error? creating DirectDraw Clipper!!!","test",MB_OK);
   return 0 ;
   }
  lpDDC->SetHWnd(0, Handle );


   if(FAILED(hr = lpDDS->SetClipper(lpDDC)))
   {
  //	MessageBox(NULL,"Error? Attaching Clipper!!!","test",MB_OK);
    return 0 ;
   }
//lpDDC->Release();
 */


DDSCAPS ddc;
   memset(&ddc,0,sizeof(ddc));
   ddc.dwCaps = DDSCAPS_BACKBUFFER;

if(FAILED(hr = lpDDS->GetAttachedSurface(&ddc,&lpBack)))
return 0;


CalcPalette();

 			DDBLTFX BBFX;
			ZeroMemory(&BBFX,sizeof(BBFX));
			BBFX.dwSize = sizeof(BBFX);
			BBFX.dwFillColor=0;
			RECT rt;
                        rt.left=0;
                        rt.top = 0;
                        rt.right=ClientWidth;
                        rt.bottom=ClientHeight;
  			lpBack->Blt(&rt,0,0,DDBLT_COLORFILL,&BBFX);
//lpDDS->Flip(0,0);
 return 1;
}

//===============================================================DRAW
void TdirectdrawWindow::Draw(void)
{

Plasma(0,0,639,479 );
lpDDS->Flip(0,0);

}


void __fastcall TdirectdrawWindow::FormDestroy(TObject *Sender)
{
	if(lpDDS !=0)lpDDS->Release();
}
//---------------------------------------------------------------------------

void __fastcall TdirectdrawWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Timer1->Enabled = false;
while(FAILED(lpDD->SetCooperativeLevel(Handle,DDSCL_NORMAL)));
lpDD->Release();
this->DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TdirectdrawWindow::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 Timer1->Enabled = false;
while(FAILED(lpDD->SetCooperativeLevel(Handle,DDSCL_NORMAL)));
lpDD->Release();
this->DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TdirectdrawWindow::Timer1Timer(TObject *Sender)
{
RotatePalette();
}
//---------------------------------------------------------------------------

