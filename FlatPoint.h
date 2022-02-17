//---------------------------------------------------------------------------

#ifndef FlatPointH
#define FlatPointH
//---------------------------------------------------------------------------

class FlatPoint{
public:
  int In;
double x,y;
double vx,vy;
 FlatPoint *next;
 FlatPoint *prev;
FlatPoint(void);
~FlatPoint(void);
FlatPoint(float,float);
FlatPoint(FlatPoint*);
Insert(FlatPoint*);
Insert2(FlatPoint*);
Add(FlatPoint*);
void ClearConnections();
};

struct Complex{
double a;
double b;
operator =(Complex v2);
operator =(double v2);
Complex operator *(Complex v2);
Complex operator *(double v2);
Complex operator +(Complex v2);
Complex operator -(Complex v2);
Complex operator +(int v);
Complex operator -(int v);
Complex operator /(Complex v2);
};
Complex ComplexPow(Complex v,double pow);
double Modulus(Complex v);
Complex operator /(double v1,Complex v2);
#endif
 