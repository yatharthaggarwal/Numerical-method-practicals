#include<iostream>
#include<math.h>
using namespace std;
#define tolerance pow(10,-4)	//answer converging to 4 decimal places 	

/*
function : intake_matrix
return type: void
parameter: martix, order of matrix
User to enter values in the A and b for equation Ax=b
*/

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
/*
function : print_matrix
return type: void
parameter: martix, order of matrix
Prints values of A and b for equation Ax=b
*/
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
/*
function : sor
return type: void
parameter: martix, order of matrix, initial iteration vector, 'x' vector, weight
Performs iteration as per Successive over-Relaxation method
*/
void sor(float a[][5], int n, float x0[5],float x[5],float w)
{
	float sum1,sum2; 
	float norm[5],max;
	int m=0;
	while(1)						//infinite loop to find the solution
	{
		for(int i=0;i<n;i++)		//loop for row
		{
			sum1=sum2=0;
			for(int j=0;j<=(i-1);j++)	
			{
				sum1+=a[i][j]*x[j];	
			}
			for(int j=i+1;j<n;j++)	
			{
				sum2+=a[i][j]*x0[j];	
			}
			x[i]=(1-w)*x0[i]+((a[i][n]-sum1-sum2)*w)/a[i][i]; //iteration formula for 'x' vector
		}
		
		for(int k=0;k<n;k++)					//finding infinity norm	of 'x-x0' vector 
		{
			norm[k]=x[k]-x0[k];
			norm[k]=fabs(norm[k]);
		}
		max=norm[0];
		for(int k=1;k<n;k++)
		{
			if(norm[k]>max)
			max=norm[k];
		}							
		if(max<5*tolerance)		//comparing two consecutive iterated vectors till 4 decimal places
		{
			cout<<"\n It took "<<m+1<<" iterations and solution is ";
			break;
		}
		for(int k=0;k<n;k++)			//storing values in 'x0' vector for new iteration 
		{
			x0[k]=x[k];
		}
		m++;
	}
	for(int k=0;k<n;k++)				//printing solutions	
	{
		cout<<endl<<" x"<<k+1<<" = "<<x[k];
	}
		
}
int main()
{
	float a[5][5], x[5]={0,0,0,0,0},x0[5]={0,0,0,0,0};
	float w;
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
	cout<<"\n Enter weight: ";
	cin>>w;
	sor(a,n,x0,x,w);
}
