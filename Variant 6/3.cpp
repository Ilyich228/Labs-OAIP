#include <iostream.h>
#include <iomanip.h>
#include <math.h>
int main ()
{
double a,b,h,d,x,y,s,p;
int n,i;
cout<<"Vvedite a,b,n"<<endl;
cin>>a>>b>>n;
h=(b-a)/10;
x=a;
cout<<setw(15)<<x<<setw(15)<<y<<setw(15)<<s<<setw(15)<<d<<endl;
do
{
p=s=x;
for(i=1;i<=n;i++)
{
p*=pow(x,2)/(2*i*(2*i+1));
s+=p;
}
y=(exp(x)-exp((-1)*x))/2;
d=fabs(y-s);
cout<<setw(15)<<x<<setw(15)<<y<<setw(15)<<s<<setw(15)<<d<<endl;
x+=h;
}
while(x<=b+h/2);
cout<<endl;
return 0;
}
