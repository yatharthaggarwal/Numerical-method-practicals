#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	float ip, x[20],y[20],sum=0,prod=1;
	cout<<"\n Enter the number of points for interpolation: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter the "<<i+1<<" point: ";
		cin>>x[i];
		cout<<"\n Enter the corresponding value: ";
		cin>>y[i];
	}
	cout<<"\n Enter the interpolating point: ";
	cin>>ip;
	
	for(int i=0;i<n;i++)
	{
		cout<<endl<<x[i]<<"\t"<<y[i];
	}
	cout<<"\n Lagrange coefficients :";
	for(int i=0;i<n;i++)
	{
		prod=1;
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			prod=prod*((ip-x[j])/(x[i]-x[j]));
		}
		cout<<endl<<"L"<<i<<"\t"<<prod;
		sum+=(y[i]*prod);
	}
	cout<<"\n The value of function at x = "<<ip<<" is "<<sum; 
}
