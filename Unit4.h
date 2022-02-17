//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include "unit3.h"
#include "FlatPoint.h"
class Frt
{
 public:
  long type,iter;
  long R,G,B;
  double dw,dh,cosa,sina,a,x,y,x0,y0,width,height;
  TdrawWindow *display;
 Frt(void);
 virtual ~Frt(void);
void setdisplay(TdrawWindow *d);
virtual void setparameters(void);
virtual void Draw();
 virtual double GetPixel(double x,double y)=0;
 };


class Mandel: public Frt
{
 private:
public:
  Mandel(void);
  ~Mandel(void);
double GetPixel(double x,double y);
};

class Mandel4: public Frt
{
 private:
public:
  Mandel4(void);
  ~Mandel4(void);
double GetPixel(double x,double y);
};

class Mandel3: public Frt
{
 private:
public:
  Mandel3(void);
  ~Mandel3(void);
double GetPixel(double x,double y);
};

class Newton: public Frt
{
 private:
 int P;
public:
  Newton(void);
  ~Newton(void);
  void setparameters(void);
  double GetPixel(double x,double y);
};

class Barnsleyj1: public Frt
{
 private:
   Complex c;
   double Max;
public:
  Barnsleyj1(void);
  ~Barnsleyj1(void);
double GetPixel(double x,double y);
void setparameters(void);
};

class Barnsleyj2: public Frt
{
 private:
   Complex c;
   double Max;
public:
  Barnsleyj2(void);
  ~Barnsleyj2(void);
double GetPixel(double x,double y);
void setparameters(void);
};

class Barnsleyj3: public Frt
{
 private:
   Complex c;
   double Max;
public:
  Barnsleyj3(void);
  ~Barnsleyj3(void);
double GetPixel(double x,double y);
void setparameters(void);
};


class Spider: public Frt
{
 private:
  double cx,cy;
public:
  Spider(void);
  ~Spider(void);
double GetPixel(double x,double y);
};

class Julia: public Frt
{
 private:
  double cx,cy;
public:
  Julia(void);
  ~Julia(void);
void setparameters(void);
double GetPixel(double x,double y);
};


class Koh: public Frt
{
public:
  Koh(void);
  ~Koh(void);
void setparameters(void);
double GetPixel(double x,double y);
void Iter(int n,FlatPoint *p);
void Draw();
};

class Dragon: public Frt
{
public:
  Dragon(void);
  ~Dragon(void);
void setparameters(void);
double GetPixel(double x,double y);
void Iter(int n,float x,float y);
void Draw();
private:
float w,h,cx1,cy1,cx2,cy2,cx3,cy3,cx4,cy4,zoom;
};

class Serp: public Frt
{
public:
  Serp(void);
  ~Serp(void);
void setparameters(void);
double GetPixel(double x,double y);
void Draw();
};

class Plasma: public Frt
{
private:
   unsigned char R[256],G[256],B[256];
   unsigned long Colors[256];
   void Divide(int Col);
   float Rug;
   float Random;
void GetMiddle(int x,int y,int &R,int &G,int &B);
void SetMiddle(int x,int y,int grain,unsigned long Color);
void FractPlasma(int il, int jl,int  ih,int jh);

public:
  Plasma(void);
  ~Plasma(void);
void setparameters(void);
double GetPixel(double x,double y);
void Draw();
};


#endif
