#include <iostream>
#include <stdlib.h>
using namespace std;

struct SINHVIEN
{
	char HoTen[31];
	int Mssv;
	float Dtb;
};
typedef struct SINHVIEN sv;
void swap(sv *a, sv *b)
{
	sv temp = *a;
	*a=*b;
	*b=temp;
}
void binaryInsertionSortDtb(sv A[],int n)
{
	for(int i=1;i<n;i++)
	{
		int l,r,m;
		sv x;
		l=0;
		r=i-1;
		x=A[i];
		while(l<=r)
		{
			m=(l+r)/2;
			if(A[m].Dtb>x.Dtb) r=m-1;
			else l=m+1;
		}
		for(int j=i;j>l;j--)
			A[j]=A[j-1];
		A[l]=x;
	}
}
void binaryInsertionSortMssv(sv A[], int n)
{
	for(int i=1;i<n;i++)
	{
		int l,r,m;
		sv x;
		l=0;
		r=i-1;
		x=A[i];
		while(l<=r)
		{
			m=(l+r)/2;
			if(A[m].Mssv>x.Mssv) r=m-1;
			else l=m+1;
		}
		for(int j=i;j>l;j--)
			A[j]=A[j-1];
		A[l]=x;
	}
}
void DtbMssv(sv A[], int n)
{
	binaryInsertionSortDtb(A,n);
	for(int i=0;i<n-1;i++)
	{
		if(A[i].Dtb==A[i+1].Dtb)
		{
			if(A[i].Mssv>A[i+1].Mssv)
			{
				swap(A[i],A[i+1]);
			}
		}
	}
}
void nhap1sv(sv &x)
{
	fflush(stdin);
	printf("Nhap ho va ten: ");
	gets(x.HoTen);
	printf("Nhap ma so sinh vien: ");
	scanf("%d",&x.Mssv);
	printf("Nhap diem trung bình: ");
	scanf("%f",&x.Dtb);
}
void xuat1sv(sv x)
{
	puts(x.HoTen);
	printf("%d\n",x.Mssv);
	printf("%2.2f \n",x.Dtb);
	
}
void nhapDSsv (sv A[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Nhap thong tin sinh vien thu %d: \n",i+1);
		nhap1sv(A[i]);
	}
}
void xuatDSsv(sv A[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Thong tin cua sinh vien thu %d: \n",i+1);
		xuat1sv(A[i]);
	}
}
int main()
{
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	sv A[100];
	nhapDSsv(A,n);
	binaryInsertionSortDtb(A,n);
	printf("\t---Sap xep theo DTB---\n");
	xuatDSsv(A,n);
	printf("\t---Sap xep theo MSSV---\n");
	binaryInsertionSortMssv(A,n);
	xuatDSsv(A,n);
	DtbMssv(A,n);
	printf("\t---Sap xep theo DTB+MSSV---\n");
	xuatDSsv(A,n);
}

