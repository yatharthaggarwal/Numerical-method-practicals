#include<iostream>
#include<math.h>
using namespace std;
#define f(x) pow(x,3)+2*pow(x,2)-3*x-1
#define tolerance pow(10,-5)
int main()
{
	cout<<"\n\t\t SECANT METHOD ";
	cout<<"\n\t\t _____________ \n";
	float p0=2;
	float p1=1;
	float p=0.0,a,b,div;
	int i=0;
	 a=f(p0);
	 b=f(p1);
	
	while(1)
	{
		p =  p1-b*(p1-p0)/(b-a);
		cout<<endl<<"  "<<i+1<<") "<<p;		
		if(fabs(p-p1)<tolerance)
		{
			cout<<"\n\n Solution is: "<<p;
			break; 
		}
		p0=p1;
		a=b;
		p1=p;
		b=f(p);
		i++;
	}
	cout<<"\n It took "<<i+1<<" iterations.";
}
