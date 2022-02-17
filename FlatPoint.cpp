//---------------------------------------------------------------------------

#include <math.h>
#pragma hdrstop

#include "FlatPoint.h"

//---------------------------------------------------------------------------

FlatPoint::FlatPoint(void)
{
In=0;
 x=0;y=0;
 next=0;
 prev=0;
}
FlatPoint::~FlatPoint(void)
{
//ClearConnections();
}
FlatPoint::FlatPoint(float nx,float ny)
{
In = 0;
 x = nx;
 y= ny;
 next = 0;
 prev= 0;
}
FlatPoint::FlatPoint(FlatPoint* np)
{
 x = np->x;
 y = np->y;
 In = np->In;
}


FlatPoint::Insert(FlatPoint* np)
{
 np->In = In+1;
 FlatPoint *buf;
 buf = next;
 next =np;
//if(np->next != 0)
        np->next = buf;
//if(np->prev != 0)
        buf->prev  = np;
}

FlatPoint::Insert2(FlatPoint* np)
{
 np->In = In+1;
 FlatPoint *buf;
 if(next != 0)
 {
 buf = next;
 next =np;
        np->next = buf;
        np->prev  = this;
     buf->prev = np;
  }
 else
 {
  next = np;
  np->next = 0;
  np->prev = this;
 }
 }

FlatPoint::Add(FlatPoint* np)
{
 FlatPoint *cur=this;
 while(cur->next != 0) cur = cur->next;
 cur->next = np;
 cur->next->prev = this;

}

void FlatPoint::ClearConnections()
{
if(prev != 0)
{
delete prev;
prev = 0;
}

if(next != 0)
{
delete next;
next = 0;
}
}




Complex::operator =(Complex v2)
{
 a = v2.a;
 b = v2.b;

}

Complex::operator =(double v2)
{
 a = v2;
 b = 0;

}

Complex Complex::operator +(Complex v2)
{
Complex r;
 r.a = a+v2.a;
 r.b = b+v2.b;
 return r;

}

Complex Complex::operator -(Complex v2)
{
Complex r;
 r.a = a-v2.a;
 r.b = b-v2.b;
 return r;

}

Complex Complex::operator *(Complex v2)
{
Complex r;
 r.a = a*v2.a-b*v2.b;
 r.b = v2.a*b+a*v2.b;
 return r;
}

Complex Complex::operator +(int v)
{
 Complex r;
 r.a = a+v;
 r.b = b;
 return r;
}

Complex Complex::operator -(int v)
{
 Complex r;
 r.a = a-v;
 r.b = b;
 return r;
}


Complex ComplexPow(Complex v,double pow)
{
 Complex r = v;
 for(int i=1;i<pow;i++)
 {
   r = r*v;
 }
 return r;
}

double Modulus(Complex v)
{
 return sqrt(v.a*v.a+v.b*v.b); 
}

Complex operator /(double a,Complex v2)
{
Complex r;
r.a = a*v2.a/(v2.a*v2.a+v2.b*v2.b);
r.b = -a*v2.b/(v2.a*v2.a+v2.b*v2.b);
return r;
}
Complex Complex::operator *(double v2)
{
 Complex r,r2;
 r2.a = a;
 r2.b = b;
 r.a = v2;
 r.b = 0;
 r = r2*r;
return r;
}

Complex Complex::operator /(Complex v2)
{
 Complex r;
r.a = (a*v2.a+b*v2.b)/(v2.a*v2.a+v2.b*v2.b);
r.b = (b*v2.a-a*v2.b)/(v2.a*v2.a+v2.b*v2.b);
return r;
}

#pragma package(smart_init)


