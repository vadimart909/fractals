//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <math.h>
#include <stdlib.h>

#pragma hdrstop

#include "Unit4.h"
#include "unit1.h"
#include "flatPoint.h" 


//---------------------------------------------------------------------------

Frt::Frt()
{
  type=-1;
}
Frt::~Frt()
{
 type= 0;
}

void Frt::setdisplay(TdrawWindow *d)
{
 display = d;
}
void Frt::setparameters(void)
{
 x0 =  mainWindow->Edit1->Text.ToDouble();
 x0 =  mainWindow->Edit1->Text.ToDouble();
 y0 =  mainWindow->Edit2->Text.ToDouble();
 width =  mainWindow->Edit3->Text.ToDouble();
 height = mainWindow->Edit4->Text.ToDouble();
 dw = display->ClientWidth;
 dh = display->ClientHeight;
 float a;
 a = mainWindow->Edit5->Text.ToDouble();
 cosa = cos(3.14159/180*a);
 sina = sin(3.14159/180*a);
 iter = mainWindow->Edit6->Text.ToDouble();
 R = mainWindow->Edit7->Text.ToDouble();
 G = mainWindow->Edit8->Text.ToDouble();
 B = mainWindow->Edit9->Text.ToDouble();
}

void Frt::Draw()
{
setparameters();
long color;
 for(y = 0;y<dh;y+=2)
 {
  for(x = 0; x<dw;x+=2)
  {
color = GetPixel(x,y);
   display->Canvas->Pixels[x][y] = (color*B) << 16 |(color*G)<<8 | color*R;
  }
 }

 for(y = 1;y<dh;y+=2)
 {
  for(x = 0; x<dw;x+=2)
  {
color = GetPixel(x,y);
   display->Canvas->Pixels[x][y] = (color*B) << 16 |(color*G)<<8 | color*R;
  }
 }
 for(y = 0;y<dh;y+=2)
 {
  for(x = 1; x<dw;x+=2)
  {
color = GetPixel(x,y);
   display->Canvas->Pixels[x][y] = (color*B) << 16 |(color*G)<<8 | color*R;
  }
 }

 for(y = 1;y<dh;y+=2)
 {
  for(x = 1; x<dw;x+=2)
  {
color = GetPixel(x,y);
   display->Canvas->Pixels[x][y] = (color*B) << 16 |(color*G)<<8 | color*R;
  }
 }

}

Mandel::Mandel(void)
{
}

Mandel::~Mandel(void)
{
}


double Mandel::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 xs = xt;
 ys = yt;
  do{
   x0 = xb*xb-yb*yb+xt ;
   y0 = 2*xb*yb+yt;
   xb = x0;
   yb = y0;
   i++;
  }while((xb-xs)*(xb-xs)+(yb-ys)*(yb-ys) < 100 && i<iter);
  return i;
}

Mandel4::Mandel4(void)
{
}

Mandel4::~Mandel4(void)
{
}


double Mandel4::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 Complex bb;
 Complex c0 = {xt,yt};

 bb.a = xt;
 bb.b = yt;
 xs = xt;
 ys = yt;
  do{
   bb= ComplexPow(bb,4)+c0;
   i++;
  }while((bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys) < 100 && i<iter);
  return i;
}


Mandel3::Mandel3(void)
{
}

Mandel3::~Mandel3(void)
{
}


double Mandel3::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 Complex bb;
 Complex c0 = {xt,yt};

 bb.a = xt;
 bb.b = yt;
 xs = xt;
 ys = yt;
  do{
   bb= ComplexPow(bb,3)+c0;
   i++;
  }while((bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys) < 100 && i<iter);
  return i;
}


Spider::Spider()
{
type = 3;
}

Spider::~Spider()
{
}



double Spider::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
  double i=0;
 double x0=0,y0=0,xb=xt,yb=yt , cx = xt,cy = yt ,cx0 = xt,cy0 = yt;
 xs = xt;
 ys = yt;
  do{
   x0 = xb*xb-yb*yb+cx ;
   y0 = 2*xb*yb+cy;
   cx0 = cx/2+x0;
   cy0 = cy/2+y0;
   xb = x0;
   yb = y0;
   cx = cx0;
   cy = cy0;
   i++;
  }while((xb-xs)*(xb-xs)+(yb-ys)*(yb-ys) < 100 && i<iter);
  return i;
}

Julia::Julia(void)
{
}

Julia::~Julia(void)
{
}

void Julia::setparameters(void)
{
 Frt::setparameters();
 cx =mainWindow->Edit10->Text.ToDouble();
 cy =mainWindow->Edit11->Text.ToDouble();
}

double Julia::GetPixel(double x,double y)
{

  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
   xs = xt;
   ys= yt;
 long i=0;
 double xb=xt,yb=yt;
  do{
   x = xb*xb-yb*yb+cx ;
   y = 2*xb*yb+cy;
   xb = x;
   yb = y;
   i++;
  }while((xb-xs)*(xb-xs)+(yb-ys)*(yb-ys) < 100 && i<iter);
  return i;
}



//======================================Geometric fraqs==================

Koh::Koh(void)
{
  type=12;
}

Koh::~Koh(void)
{
}

void Koh::setparameters(void)
{
iter = mainWindow->Edit6->Text.ToDouble();
}

double Koh::GetPixel(double x,double y)
{
 return 0;
}

void Koh::Iter(int N,FlatPoint *p)
{
if(N > 0)
{
   float a = M_PI/180*90;
   FlatPoint *cur,cp,n[3],*c1,*c2,*c3;
    cur = p;

   cp.x = cur->next->x-cur->x;
   cp.y = cur->next->y-cur->y;

   n[0].x = cur->x+cp.x/3;
   n[0].y = cur->y+cp.y/3;
   n[2].x = cur->x+cp.x/3*2;
   n[2].y = cur->y+cp.y/3*2;
   n[1].x = cur->x+cp.x/2+ cp.x/3*cos(a)-cp.y/3*sin(a);
   n[1].y = cur->y+cp.y/2+cp.x/3*sin(a)-cp.y/3*cos(a);

   cur->Insert(new FlatPoint(n[0]));
    c1 = cur->next;
   cur = cur->next;
   cur->Insert(new FlatPoint(n[1]));
    c2 = cur->next;
   cur = cur->next;
   cur->Insert(new FlatPoint(n[2]));
    c3 = cur->next;
   cur = cur->next;
 if(N > 0 ){
 Iter(N-1,p);
 Iter(N-1,c1);
 Iter(N-1,c2);
Iter(N-1,c3);
 }

 }
}

void Koh::Draw()
{
  float w = display->Width , h = display->Height;

  setparameters();
  FlatPoint *p = new FlatPoint(0,0);
   p->Add(new FlatPoint(1,0));
   Iter(iter,p);
   //display->Canvas->CopyMode = pmCopy;
   display->Canvas->Rectangle(0,0,w,h);

  display->Canvas->MoveTo(0,h/2);
  FlatPoint *cur = p;
do{
  display->Canvas->LineTo(w*cur->x,h/2-h*cur->y);
  cur = cur->next;
  }
while(cur != NULL);
}


Dragon::Dragon(void)
{
type = 14;
}
Dragon::~Dragon(void)
{}
void Dragon::setparameters(void)
{
iter = mainWindow->Edit12->Text.ToDouble();
cx1 = mainWindow->Edit14->Text.ToDouble();
cy1= mainWindow->Edit15->Text.ToDouble();
cx2 = mainWindow->Edit16->Text.ToDouble();
cy2= mainWindow->Edit17->Text.ToDouble();
cx3 = mainWindow->Edit18->Text.ToDouble();
cy3= mainWindow->Edit19->Text.ToDouble();
cx4 = mainWindow->Edit20->Text.ToDouble();
cy4= mainWindow->Edit21->Text.ToDouble();
zoom= mainWindow->Edit13->Text.ToDouble();
}

double Dragon::GetPixel(double x,double y)
{

}
void Dragon::Iter(int n,float x,float y)
{
display->Canvas->Pixels[w/2+x][h/2-y] = abs(x*n+y);
 float X1,Y1;
 float X2,Y2;
 X1 = -cx1*x-cy1*y+50*zoom;
 Y1 = cx2*x-cy2*y+50*zoom;
 X2 = cx3*x-cy3*y-50*zoom;
 Y2 = cx4*x+cy4*y+50*zoom;
 if(n>0){
  Iter(n-1,X1,Y1);
  Iter(n-1,X2,Y2);
 }

}

void Dragon::Draw()
{
  w = display->Width ;
  h = display->Height;

  setparameters();
  FlatPoint *p = new FlatPoint(0,0);
   p->Add(new FlatPoint(1,0));
   display->Canvas->Rectangle(0,0,w,h);
Iter(iter,0,0);
}


Serp::Serp(void)
{}
Serp::~Serp(void)
{}

void Serp::setparameters(void)
{
}

double Serp::GetPixel(double x,double y)
{
return 0;
}


void Serp::Draw()
{
}


Plasma::Plasma(void)
{
 Rug = 1.1;
 Random = 10;


 int RA, GA, BA, RF, GF, BF,RS, GS, BS, Counter;

  RA = 16 + random(32-16);
  GA = 16 + random(32-16);
  BA = 16 + random(32-16);

  RF = 2 + random(5);
  GF = 2 + random(5);
  BF = 2 + random(5);

  RS = random(64);
  GS = random(64);
  BS = random(64);


  for(Counter= 0;Counter<=255;Counter++)
  {
    R[Counter]  = 1 + (RA * sin((RS + Counter * RF) * M_PI / 128));
    G[Counter] =  1+ (GA * sin((GS + Counter * GF) * M_PI / 128));
    B[Counter]  = 1 + (BA * sin((BS + Counter * BF) * M_PI/ 128));
    }
}

Plasma::~Plasma(void)
{
}

void Plasma::setparameters(void)
{
Frt::setparameters();
}

double Plasma::GetPixel(double x,double y)
{
}

void Plasma::GetMiddle(int x,int y,int &R,int &G,int &B)
{
 int x0,y0,i=0,grain=5;
       R = 0;
       G = 0;
       B = 0;
       unsigned long A;

 for(x0=x-grain*2;x0<=x+grain*2;x0++)

 for(y0=y-grain*2;y0<=y+grain*2;y0++)
  {
   if( x0 >=0 && x0 <=dw && y0 >=0 && y0 <= dh)
    if( (x0 <= x-grain || x0 >= x+grain) && (y0 <= y-grain || y0 >= y+grain)  )
    {

    A = (unsigned long)display->Canvas->Pixels[x0][y0];
      R+= (A & 0xff);
      G+= (A & 0xff00) >> 8;
      B+= (A & 0xff0000)  >> 16;
      i++;
     }
  }
  R /=i;
  G /= i;
  B /=i;
 }

void Plasma::SetMiddle(int x,int y,int grain,unsigned long Color)
{
 int x0,y0;
 for(x0=x-grain;x0<=x+grain;x0++)
 for(y0=y-grain;y0<=y+grain;y0++)
  {
   if( x0 >=0 && x0 <=dw && y0 >=0 && y0 <= dh)
    {
      display->Canvas->Pixels[x0][y0] = Color;
     }
  }
 }


  void Plasma::FractPlasma(int il, int jl,int  ih,int jh)
{
    int im, jm;
      Random = random(5);
    im = (il + ih + 1)/ 2;
    jm = (jl + jh + 1)/ 2;

    if (jm < jh)
    {
      Random = random(5);
      if(display->Canvas->Pixels[jm][il]==0)
      {
display->Canvas->Pixels[jm][il] =
(display->Canvas->Pixels[jl][il] + display->Canvas->Pixels[jh][il])/ 2 +
                              Random*Rug*(jh-jl);
      Random = random(5);
      if( il < ih )
      display->Canvas->Pixels[jm][ih] =
      (display->Canvas->Pixels[jl][ih] + display->Canvas->Pixels[jh][ih]) / 2
       +Random*Rug*(jh-jl);
}

      Random = random(5);
    if (im < ih)
    {
      if( display->Canvas->Pixels[jl][im] == 0 )
 display->Canvas->Pixels[jl][im]=
 (display->Canvas->Pixels[jl][il]+ display->Canvas->Pixels[jl][ih]) / 2 +
                              Random*Rug*(ih-il);
      Random = random(5);
      if (jl < jh)
        display->Canvas->Pixels[jh][im]=
        (display->Canvas->Pixels[jh][il] +
          display->Canvas->Pixels[jh][ih]) / 2 +
                              Random*Rug*(jh-jl);
    }
      Random = random(5);

    if ((im < ih) && (jm < jh))
    display->Canvas->Pixels[jm][im]=
    (display->Canvas->Pixels[jl][il] +
    display->Canvas->Pixels[jl][ih] +
    display->Canvas->Pixels[jh][il]+
    display->Canvas->Pixels[jh][ih]) / 4 +
                           Random*Rug*(abs(ih-il)+abs(jh-jl));
    if( (im < ih) || (jm < jh))
    {
      FractPlasma(il, jl, im, jm);
      FractPlasma(il, jm, im, jh);
      FractPlasma(im, jl, ih, jm);
      FractPlasma(im, jm, ih, jh);
    }
 }

}
void Plasma::Divide(int Col)
{

 int x,y,k;
 int R,G,B;
 unsigned long Color;
 unsigned long RandomColor;
 randomize();
for(k=2;k>0;k--)
{
  for(y=0;y<dh;y++)
  {
  for(x=0;x<dw;x++)
    {
      GetMiddle(x,y,R,G,B);
      Color = B << 16 | G << 8 | R;
      B = random(256);
      G = random(256);
      R = random(256);
      RandomColor =  B << 16 | G << 8 | R;
        SetMiddle(x,y,2,Color| RandomColor);
    }
    }
 }
}

void Plasma::Draw()
{
setparameters();
   display->Canvas->Brush->Color=0;
   display->Canvas->Pen->Color=0;
   display->Canvas->Rectangle(0,0,dw,dh);


  int x,y,N=2 ,Col = 2,i=1;
/*
  for(y=0;y<N;y++)
  {
  for(x=0;x<N;x++)
  {
   display->Canvas->Brush->Color= B[i]<<16 | G[i] << 8 | R[i];
   display->Canvas->Pen->Color= B[i]<<16 | G[i] << 8 | R[i];
    if(i)i=0; else i=1;
    display->Canvas->Rectangle(x*dw/Col,y*dh/Col,(x+1)*dw/Col,(y+1)*dh/Col);
  }
    if(i)i=0; else i=1;
 }
 */
  //  display->Canvas->Lock();
 FractPlasma(0,0,dh,dw);
 //   display->Canvas->Unlock();

  for(y=0;y<dh;y++)
  for(x=0;x<dw;x++)
  {
  N = (unsigned char)display->Canvas->Pixels[x][y];
   display->Canvas->Pixels[x][y] = B[N]<< 16 | G[N] << 8 |R[N] ;
  }
 }


Barnsleyj1::Barnsleyj1(void)
{
mainWindow->JuliaBox1->Hide();
mainWindow->Barnj1Box1->Top = mainWindow->JuliaBox1->Top;
mainWindow->Barnj1Box1->Left = mainWindow->JuliaBox1->Left;
mainWindow->Barnj1Box1->Show();
}

Barnsleyj1::~Barnsleyj1(void)
{
mainWindow->Barnj1Box1->Hide();
}

double  Barnsleyj1::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 Complex bb;

 bb.a = xt;
 bb.b = yt;
  xs = xt;
  ys = yt;
  do{
   if(bb.a>=0)
   bb= (bb-1)*c;
   else
   bb= (bb+1)*Modulus(c)/c;
   i++;
  }while((bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys) < Max && i<iter);
  return i;

}

void Barnsleyj1::setparameters(void)
{
Frt::setparameters();
c.a = mainWindow->Edit22->Text.ToDouble();
c.b = mainWindow->Edit23->Text.ToDouble();
Max = mainWindow->Edit24->Text.ToDouble();
}


//=========================================================Barnsleyj2
Barnsleyj2::Barnsleyj2(void)
{
mainWindow->JuliaBox1->Hide();
mainWindow->Barnj1Box1->Top = mainWindow->JuliaBox1->Top;
mainWindow->Barnj1Box1->Left = mainWindow->JuliaBox1->Left;
mainWindow->Barnj1Box1->Show();
}

Barnsleyj2::~Barnsleyj2(void)
{
mainWindow->Barnj1Box1->Hide();
}

double  Barnsleyj2::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 Complex bb;

 bb.a = xt;
 bb.b = yt;
  xs = xt;
  ys = yt;
  do{
   if(bb.a*bb.b+c.a*bb.b>=0)
   bb= (bb-1)*c;
   else
   bb= (bb+1)*c;
   i++;
  }while((bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys) < Max && i<iter);
  return i;

}

void Barnsleyj2::setparameters(void)
{
Frt::setparameters();
c.a = mainWindow->Edit22->Text.ToDouble();
c.b = mainWindow->Edit23->Text.ToDouble();
Max = mainWindow->Edit24->Text.ToDouble();
}

//=========================================================Barnsleyj3
Barnsleyj3::Barnsleyj3(void)
{
mainWindow->JuliaBox1->Hide();
mainWindow->Barnj1Box1->Top = mainWindow->JuliaBox1->Top;
mainWindow->Barnj1Box1->Left = mainWindow->JuliaBox1->Left;
mainWindow->Barnj1Box1->Show();
}

Barnsleyj3::~Barnsleyj3(void)
{
mainWindow->Barnj1Box1->Hide();
}

double  Barnsleyj3::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 Complex bb;

 bb.a = xt;
 bb.b = yt;
  xs = xt;
  ys = yt;
  do{
   if(bb.a>=0)
   bb= (bb.a*bb.a-bb.b*bb.b-1)+i*(2*bb.a*bb.b);
   else
   bb= (bb.a*bb.a-bb.b*bb.b-1+c.a*bb.a)+i*(2*bb.a*bb.b+c.b*bb.a);
   i++;
  }while((bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys) < Max && i<iter);
  return i;

}

void Barnsleyj3::setparameters(void)
{
Frt::setparameters();
c.a = mainWindow->Edit22->Text.ToDouble();
c.b = mainWindow->Edit23->Text.ToDouble();
Max = mainWindow->Edit24->Text.ToDouble();
}
//==============================================================Newton

Newton::Newton(void)
{
mainWindow->JuliaBox1->Hide();
mainWindow->NewtonBox1->Top = mainWindow->JuliaBox1->Top;
mainWindow->NewtonBox1->Left = mainWindow->JuliaBox1->Left;
mainWindow->NewtonBox1->Show();
type=100;
}
Newton::~Newton(void)
{
mainWindow->NewtonBox1->Hide();

}
void Newton::setparameters(void)
{
Frt::setparameters();
P = mainWindow->Edit25->Text.ToDouble();
}

double Newton::GetPixel(double x,double y)
{
  x = x0+width*x/dw;
  y = y0+height*y/dh;
 double xt,yt,xs,ys;
   xt = cosa*x+sina*y;
   yt = cosa*y-sina*x;
 double i=0;
 double x0=0,y0=0,xb=xt,yb=yt;
 Complex bb;

 bb.a = xt;
 bb.b = yt;
  xs = xt;
  ys = yt;
  do{
   bb= (ComplexPow(bb,P)*(P-1)+1)/(ComplexPow(bb,P-1)*P);
   i++;
  }while((bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys) < 100 && i<iter);
  return (bb.a-xs)*(bb.a-xs)+(bb.b-ys)*(bb.b-ys);

}


