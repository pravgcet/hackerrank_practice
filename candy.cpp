#include <iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int ar[200000];
int sn[200000],v,ip,in;
long long int sum=0;
for(int i=1;i<=n;i++){cin>>ar[i];}
ip=1;in=1;v=1;
sn[0]=0;
ar[0]=0;
int ch=0;
//For start
if(n==1)
{
cout<<1<<endl;
return 0;
}
//Check for strictly increasing series
while(in<n&&(ar[in]<ar[in+1])){in++;}
if(ip!=in)
{
ch=1;
	for(int i=ip;i<=in;i++)
	{sn[i]=v++;}
	ip=in;
}
if(ch==0)
{
	//Check for strictly decreasing series
	while(in<n&&(ar[in]>ar[in+1])){in++;}
	if(ip!=in)
	{
	ch=1;
		v=in-ip+1;
		for(int i=ip;i<=in;i++)
		{sn[i]=v--;}
		ip=in;
	}
}
//Check for equality
if(ch==0)
{
	while(in<n&&(ar[in]==ar[in+1])){in++;}
	if(ip!=in)
	{
		for(int i=ip;i<=in;i++)
		{sn[i]=1;}
		ip=in;
	}
}

while(1)
{
	//Check for strictly increasing series
	while(in<n&&(ar[in]<ar[in+1])){in++;}
	if(ip!=in)
	{
		v=sn[ip]+1;
		for(int i=ip+1;i<=in;i++)
		{sn[i]=v++;}
		ip=in;
	}

	//Check for strictly decreasing series
	while(in<n&&(ar[in]>ar[in+1])){in++;}
	if(ip!=in)
	{
		v=in-ip;
		if(sn[ip]-v<1)
		{
			v=in-ip+1;
			for(int i=ip;i<=in;i++)
			{sn[i]=v--;}
			v++;
		}
		else
		{
			for(int i=ip+1;i<=in;i++)
			{sn[i]=v--;}
			v++;
		}
		ip=in;
	}
	
	while(in<n&&(ar[in]==ar[in+1])){in++;}
	if(ip!=in)
	{
		for(int i=ip+1;i<=in;i++)
		{sn[i]=1;}
		ip=in;
	}
	if(in>=n){break;}
}
/*
for(int i=1;i<=n;i++)
{
cerr<<ar[i]<<" ";
}
cerr<<endl<<endl;
int su=0;
for(int i=1;i<=n;i++)
{
cerr<<sn[i]<<" ";
su+=sn[i];
}
cerr<<endl;
*/
for(int i=1;i<=n;i++)
{
sum+=sn[i];
}

cout<<sum<<endl;;
return 0;
}



