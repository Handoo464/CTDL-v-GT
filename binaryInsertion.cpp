#include <iostream>
#include <stdlib.h>
using namespace std;
void binaryInsertionSort(int *A, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<'\n';
	for(int i=1;i<n;i++)
	{
		int l,r,m,x;
		l=0;
		r=i-1;
		x=A[i];
		while(l<=r)
		{
			m=(l+r)/2;
			if(A[m]>x) r=m-1;
			else l=m+1;
		}
		for(int j=i;j>l;j--)
			A[j]=A[j-1];
		A[l]=x;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int *A = (int *)realloc(0,sizeof(int*)*n);
	for(int i=0;i<n;i++)
	{
		printf("A[%d] = ",i);
		scanf("%d",(A+i));
	}
	binaryInsertionSort(A,n);
    for(int i=0;i<n;i++)
        {
        	printf("%d ",*(A+i));
        }
}

