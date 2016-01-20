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
void gauss_elimination(float a[][5],int n)
{
	float m;
	float p[5];
	for(int k=0;k<n-1;k++)
	{
		m=0;
		for(int i=k+1;i<n;i++)
		{
			m=a[i][k]/a[k][k];
			
			for(int j=k;j<=n;j++)
			{
				a[i][j]=a[i][j]-m*a[k][j];
			}			
		}
	}

}
void back_substitution(float a[][5],int n,float x[])
{
	print_matrix(a,n);
	float sum;
	for(int k=n-1;k>=0;k--)
	{	sum=0;
		for(int j=k+1;j<n;j++)
		{
			sum+=(a[k][j]*x[j]);
		}
		x[k]=(a[k][n]-sum)/a[k][k];
		cout<<endl<<"x"<<k+1<<" = "<<x[k];
	}
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
	cout<<"\n Initial Matrix ";
	print_matrix(a,n);
	gauss_elimination(a,n);
	cout<<"\n Solution by Gauss elimination: ";
	back_substitution(a,n,x);
}

