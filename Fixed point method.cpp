#include<iostream>
#include<math.h>
using namespace std;
#define f(x) pow((10/(4+x)),1/2)
#define tolerance pow(10,-5)

int main()
{
	float p,a,p0 = 1.5;
	int i=0;
	while(1)
	{
		cout<<endl<<f(p0);
		p = f(p0);
		if(fabs(p-p0)<tolerance)
		{
			cout<<"\n Solution is: "<<p;
			break;
		}
		p0=p;
		i++;
	}
	cout<<"\n No. of iterations: "<<i+1;
}
