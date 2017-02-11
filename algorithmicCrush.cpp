#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
typedef long long int lli;
lli n,m,mx=0,tm=0,a,b,k;
cin>>n>>m;
lli *ar=(lli*)malloc(sizeof(lli)*(n+1));
memset(ar,0,sizeof(ar));

while(m--)
{
cin>>a>>b>>k;
ar[a]+=k;
if(b<n){ar[b+1]-=k;}
}
/*
for(lli i=1;i<=n;i++)
{
	cerr<<ar[i]<<" ";
}
cerr<<endl;
*/
mx=ar[1];
tm=ar[1];
for(lli i=2;i<=n;i++)
{
tm+=ar[i];
if(tm>mx){mx=tm;}
}
cout<<mx;
return 0;
}


