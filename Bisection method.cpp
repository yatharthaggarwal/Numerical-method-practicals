#include<iostream>
#include<math.h>
using namespace std;
#define f(x) pow(x,3)+2*pow(x,2)-3*x-1
#define tolerance pow(10,-5)
int main()
{
	cout<<"\n\t\t BISECTION METHOD ";
	cout<<"\n\t\t ________________ \n";
	double a,b,p,sfa,sfp;
	cout<<"\nEnter the starting point: ";
	cin>>a;
	cout<<"\nEnter the ending point: ";
	cin>>b;
	sfa = f(a);
	int i=0;
	while(1)
	{
				p=a+(b-a)/2;
		cout<<endl<<"  "<<i+1<<") "<<p;

		if ((b-a)<2*tolerance)
		{
			cout<<"\n\n Solution is "<<p;
			break;
		}
		sfp=f(p);
		
		if((sfa*sfp)<0)
			b=p;
		else
		{
			a=p;
			sfa=sfp;
		}	
		i++;
	}
	cout<<"\n It took "<<i+1<<" iterations.";	
}
