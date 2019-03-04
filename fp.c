#include <stdio.h>
void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int prime(int n, int m)
{
	int x=n+m;
	int i,flag=0;

	for(i=2;i<=x/2;i++)
	{
		if(x%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0) return(1);
	else return (0);
}
void permute(int *a, int l, int r)
{
	int i,y=0;
	if(l==r)
	{
		for(i=0;i<r;i++)
		{
			if(prime(a[i],a[i+1])) y++;
		}
		if(y==r)
		{
			for(i=0;i<r+1;i++) printf("%d ", a[i]);
			printf("\n\n");
		}
	}
	else
	{
		for(i=l;i<=r;i++)
		{
			swap((a+l),(a+i));
			permute(a,l+1,r);
			swap((a+l),(a+i));
		}
	}
}
int main()
{
	int n,i,arr[17],t,f;
	printf("\nEnter the number of testcase : ");
	scanf("%d", &t);
	printf("\nEnter the N as it represents the last number of sequence
	starts from 1\n\n");
	printf("************************************************************
	*****************\n\n");
	for(f=1;f<=t;f++)
	{
		printf("N : ");
		scanf("%d", &n);
		for(i=0;i<n;i++) arr[i]=i+1;
		printf("\nCase %.2d:\n\n", f);
		permute(arr,1,n-1);
		printf("******************************************************************
		***********\n\n");
	}
	return 0;
}