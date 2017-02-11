#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int inx[1000],ix;

typedef long long int lli;

void filter(int s,int e,int l)
{
if(l==0){return ;}
int m,e1,l1;

if((s+e)%2==1&&l%2==1)
{
m=(s+e)/2;
inx[m]=1;
filter(s,m-1,(l-1)/2);
filter(m+1,e,(l-1)/2);
}

if((s+e)%2==1&&l%2==0)
{
m=(s+e)/2;
e1=ceil((0.33)*m);
l1=(l-2)/3;
inx[m-e1]=1;
inx[m+e1]=1;
filter(s,m-e1-1,l1);
filter(m-e1+1,m+e1-1,l-2-2*l1);
filter(m+e1+1,e,l1);
}

if((s+e)%2==0)
{
m=(s+e)/2;
e1=ceil((0.33)*m);
l1=(l-2)/3;
inx[m-e1+1]=1;
inx[m+e1]=1;
filter(s,m-e1-1,l1);
filter(m-e1+2,m+e1-1,l-2-2*l1);
filter(m+e1+1,e,l1);
}

}

int main()
{
int n,k,m,s,e,sm=0;
lli ar[6000];
cin>>n>>k;
for(int i=0;i<n;i++){cin>>ar[i];}
sort(ar,ar+n);
vector<int> v1,v2;
vector<int> ::iterator it1,it2;
/*
for(int i=0;i<n;i++)
{
	cerr<<ar[i]<<" ";
}
cerr<<endl;
*/
filter(0,n-1,k);

for(int i=0;i<n;i++)
{
if(inx[i]==1)
	{
		v1.push_back(i);
	}
else
{
		v2.push_back(i);
}	
}


for(it1=v1.begin();it1!=v1.end();it1++)
{
	for(it2=v2.begin();it2!=v2.end();it2++)
	{
		sm+=abs(ar[*it1]-ar[*it2]);
	}

}

cout<<sm<<endl;


return 0;
}





