#include<iostream>
#include<math.h>
using namespace std;
#define f(x) pow(x,2)-sin(x)
#define tolerance pow(10,-8)
int main()
{
	double a,b,r,p,fa,fb,c,d;
	int i=0;
	r=0.6180339;
	cout<<"\nEnter the starting point: ";
	cin>>a;
	cout<<"\nEnter the ending point: ";
	cin>>b;
	fa=f(a);
	fb=f(b);
	while(1)
	{
		if(fabs(fa-fb)<tolerance)
		{
			break;
		}
		c=a+(1-r)*(b-a);
		d=a+r*(b-a);
		if(f(c)<=f(d))
			b=d;
		else
			a=c;
		fa=f(a);
		fb=f(b);
		cout<<endl<<a<<"\t"<<b;
		i++;
	}
	cout<<endl<<"iterations "<<i;
}
