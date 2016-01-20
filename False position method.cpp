#include<iostream>
#include<math.h>
using namespace std;
#define f(x) pow(x,3)+2*pow(x,2)-3*x-1
#define tolerance pow(10,-5)
int main()
{
	cout<<"\n\t\t FALSE POSITION METHOD ";
	cout<<"\n\t\t _____________________ \n";
	double a,b,p,sfa,sfb,sfp;
	cout<<"\n Enter the initial p0: ";
	cin>>a;
	cout<<"\n Enter the second point p1: ";
	cin>>b;
	sfa = f(a);
	sfb = f(b);
	int i=0;
	while(1)
	{
		p=b-sfb*((b-a)/(sfb-sfa));
		cout<<endl<<"  "<<i+1<<") "<<p;
		if (fabs(p-b)<tolerance)
		{
			cout<<"\n\n Solution is "<<p;
			break;
		}
		sfp=f(p);
		
		if((sfb*sfp)<0)
		{
			a=b;
			sfa=sfb;
		}
		b=p;
		sfb=sfp;		
		i++;
	}
	cout<<"\n It took "<<i+1<<" iterations.";	
}
