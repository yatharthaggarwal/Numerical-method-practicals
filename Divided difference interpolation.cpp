#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	float x[20],y[20],d[20][20],ip,sum;
	cout<<"\n Enter the number of sub-intervals ";
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cout<<"\n Enter the "<<i+1<<" point: ";
		cin>>x[i];
		cout<<"\n Enter the corresponding value: ";
		cin>>y[i];
	}
	cout<<"\n Enter the interpolating point: ";
	cin>>ip;
	for(int i=0;i<=n;i++)			
	{
		for(int k=0;k<=n;k++)
		{
			d[i][k]=0;
		}
	}
	cout<<"\n Divided difference \n\t\t";
	for(int i=1;i<=n;i++)
	{
		cout<<" \t "<<i<<" \t ";
	}
	for(int k=0;k<=n;k++)
	{
		d[k][0]=y[k];
	}
	
	for(int i=1;i<=n;i++)			//compute all divided difference
	{
		for(int k=1;k<=i;k++)
		{
			d[i][k]=(d[i][k-1]-d[i-1][k-1])/(x[i]-x[i-k]);
		}
	}
	
	sum=d[n][n];
	for(int i=0;i<=n;i++)			
	{
		cout<<endl<<x[i]<<"\t";
		for(int k=0;k<=n;k++)
		{
			cout<<d[i][k]<<"\t";
		}
		
	}	
	for(int k=n-1;k>=0;k--)
	{
		sum=sum*(ip-x[k])+d[k][k];
	}
	cout<<"\n The value of function at x = "<<ip<<" is "<<sum;
}
