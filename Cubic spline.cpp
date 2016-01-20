#include<iostream>
#include<math.h>
using namespace std;
float M[21];
float TriDiag(float a[20],float b[20],float c[20],float d[20],int n)
{
	float g[10],z[10];
	g[1]=b[1];
	for(int i=2;i<=n;i++)
	{
		if(g[i-1]==0)
		{
			break;
		}
		g[i]=b[i]-a[i]*c[i-1]/g[i-1];
	}
	z[1]=d[1]/g[1];
	for(int i=2;i<=n;i++)
		z[i]=(d[i]-a[i]*z[i-1])/g[i];
	M[n]=z[n];

	for(int i=n-1;i>=1;i--)
		M[i]=z[i]-c[i]*M[i+1]/g[i];
	return(M[0]);
}

int main()
{
	int n,ch;
	float ip, x[20],y[20],h[20],A[20],B[20],C[20],D[20];
	float a[20],b[20],c[20],d[20],xg,yd0,ydn,yc,temp;
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
	
	for(int i=1;i<=n;i++)
	{
		h[i]=x[i]-x[i-1];			//calculating the difference between successive interval
	}
	for(int i=1;i<n;i++)
	{
		A[i]=h[i];
		B[i]=2*(h[i]+h[i+1]);
		C[i]=h[i+1];
		D[i]=6*((y[i+1]-y[i])/h[i+1]-(y[i]-y[i-1])/h[i]);
	}
	cout<<"\n Enter '1' for clamped spline otherwise natural spline: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n Welcome to Non-periodic spline ";
			cout<<"\n Enter the values of f'(a): ";
			cin>>yd0;
			cout<<"\n Enter the values of f'(b): ";
			cin>>ydn;
			cout<<endl;
			D[0]=6*((y[1]-y[0])/h[1]-yd0)/h[1];
			D[n]=6*(ydn-(y[n]-y[n-1])/h[n])/h[n];
			for(int i=n+1;i>=1;i--)
				D[i]=D[i-1];
			A[n+1]=1;
			B[n+2]=2;
			for(int i=n;i>=2;i--)
			{
				A[i]=A[i-1];
				B[i]=B[i-1];
				C[i]=C[i-1];
			}
			B[1]=2;
			C[1]=1;
			temp=TriDiag(A,B,C,D,n+1);
			for(int i=0;i<=n;i++)
				M[i]=M[i+1];
			break;
		default:	 
			temp=TriDiag(A,B,C,D,n-1);
			M[0]=0;
			M[n]=0;
	}

	
	for(int i=0;i<=n-1;i++)			//coefficients of splines
	{
		a[i]=(M[i+1]-M[i])/(6*h[i+1]);
		b[i]=M[i]/2;
		c[i]=(y[i+1]-y[i])/h[i+1]-(2*h[i+1]*M[i]+h[i+1]*M[i+1])/6;
		d[i]=y[i];
		cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
	}
	if((ip<x[0])||(ip>x[n]))
	{
		cout<<"\n Outside range ";
	}
	for(int i=0;i<=n-1;i++)
	{
		if(ip<x[i+1])
		{
			temp=ip-x[i];
			yc=a[i]*pow(temp,3)+b[i]*pow(temp,2)+c[i]*temp+d[i];
			cout<<"\n For natural spline the value of function at x = "<<ip<<" is "<<yc;
			break; 
		}
	}
	
}
