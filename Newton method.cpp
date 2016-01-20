#include<iostream>
#include<math.h>
using namespace std;
#define f(x) pow(x,3)+2*pow(x,2)-3*x-1
#define df(x) 3*pow(x,2)+4*x-3
#define tolerance pow(10,-5)
int main()
{
	cout<<"\n\t\t NEWTON METHOD ";
	cout<<"\n\t\t _____________ \n";
	float p0=1;
	float p=0.0,a,b,div;
	int i=0;
	
	while(1)
	{
		a=f(p0);
		b=df(p0);
		div = a/b;
		p =  p0-div;
		cout<<endl<<"  "<<i+1<<") "<<p;		
		if(fabs(p-p0)<tolerance)
		{
			cout<<"\n\n Solution is: "<<p;
			break; 
		}
		p0=p;
		i++;
	}
	cout<<"\n It took "<<i+1<<" iterations.";
}
