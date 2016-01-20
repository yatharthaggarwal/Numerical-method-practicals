#include<iostream>
#include<math.h>
using namespace std;
void intake_matrix(float p[][5],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cout<<"\n Enter the value for "<<i+1<<" row and "<<j+1<<" column: ";
			cin>>p[i][j];
		}
	}	
}
void print_matrix(float p[][5], int n)
{
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if(j==n)
			cout<<'|';
			cout<<"\t"<<p[i][j];
		}
		cout<<endl;
	}
}
void forward_substitution(float a[][5],int n,float x[])
{
	float sum;
	for(int k=0;k<n;k++)
	{	sum=0;
		for(int j=0;j<k;j++)
		{
			sum+=(a[k][j]*x[j]);
		}
		x[k]=(a[k][n]-sum)/a[k][k];
		cout<<endl<<" y"<<k+1<<" = "<<x[k];
	}
}
void back_substitution(float a[][5],int n,float x[])
{
	cout<<"\n\n Solution is ";
	float sum;
	for(int k=n-1;k>=0;k--)
	{	sum=0;
		for(int j=k+1;j<n;j++)
		{
			sum+=(a[k][j]*x[j]);
		}
		x[k]=(a[k][n]-sum)/a[k][k];
		cout<<endl<<" x"<<k+1<<" = "<<x[k];
	}
}
void LU_factorization(float a[][5],int n,float x[5])
{
	float l[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
	float u[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
	float sum1,sum2,sum3,sum;
	u[0][0]=a[0][0]/l[0][0];
	for(int j=1;j<n;j++)
	{
		u[0][j]=a[0][j]/l[0][0];
		l[j][0]=a[j][0]/u[0][0];
	}
	for(int i=1;i<n;i++)
	{
		sum1=0;
		for(int k=0;k<=i-1;k++)
		{
			sum1+=(l[i][k]*u[k][i]);
		}
		u[i][i]=a[i][i]-sum1;
		for(int j=i+1;j<n;j++)
		{
			sum2=sum3=0;
			for(int k=0;k<=i-1;k++)
			{
				sum2+=(l[i][k]*u[k][j]);
			}
			u[i][j]=a[i][j]-sum2;
			for(int k=0;k<=i-1;k++)
			{
				sum3+=(l[j][k]*u[k][i]);
			}
			l[j][i]=1/u[i][i]*(a[j][i]-sum3);
		}
	}
	cout<<"\n The Lower Matrix: ";
	print_matrix(l,n);
	cout<<"\n The Upper Matrix: ";
	print_matrix(u,n);
	for (int p=0;p<n;p++)
	{
		l[p][n]=a[p][n];
	}
	float y[5]={0,0,0,0,0};
	forward_substitution(l,n,y);
	for (int p=0;p<n;p++)
	{
		u[p][n]=y[p];
	}
	back_substitution(u,n,x);	
}	
int main()
{
	float a[5][5], x[5]={0,0,0,0,0};
	int n;
	label:
	cout<<"\n Enter the order of matrix: ";
	cin>>n;
	if(n==5)
		{
			cout<<"\n NOT ALLOWED ";
			goto label;
		}
	intake_matrix(a,n);
	cout<<" Initial Matrix: ";
	print_matrix(a,n);
	LU_factorization(a,n,x);
}
