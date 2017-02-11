#include <iostream>
using namespace std;

int replace(int *ar,int l,int r,int val)
{
	int tr=1,mid;
	while(1)
	{
		mid=(l+r)/2;
		if(ar[mid]>=val)
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
		if(r-l<=1)
		{
			return (ar[l]>=val?l:r);
		}
	}
}

void find_lis(int *arr, int n)
{
	int *lis=new int [n];
	
	lis[0]=arr[0];
	int sb=1;

	for(int i=1;i<n;i++)
	{
		if(arr[i]>lis[sb-1])
		{
			lis[sb++]=arr[i];
		}
		else
		{
			lis[replace(lis,0,sb-1,arr[i])]=arr[i];
		}
	}
/*
	for(int i=0;i<sb;i++)
	{
		cout<<lis[i]<<"  ";
	}
*/
	cout<<sb;
}

int main()
{
	int n;
	cin>>n;
	int *ar=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}

	find_lis(ar,n);
	return 0;
}
