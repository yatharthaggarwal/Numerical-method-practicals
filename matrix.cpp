#include<iostream>
#include<math.h>
using namespace std;
void intake_matrix(float p[][5],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cout<<"\n Enter value for "<<i+1<<" row and "<<j+1<<" column: ";
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



int main()
{
	float a[5][5], x[5];
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
	print_matrix(a,n);
	
}

