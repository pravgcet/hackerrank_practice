#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define nl cout<<endl
#define loop(a,b) for(int i=a;i<b;i++)
using namespace std;

int pr[20000000];
int mx[20000000];


int main()
{
int n,q,l=0;

loop(1,11000000)
{
cin>>pr[i];
}
mx[1]=1;
l=1;

loop(2,11000000)
{
if(l<pr[i])
	{
		l=pr[i];
	}
	mx[i]=l;
}
cout<<1<<endl<<2<<endl<<4;nl;
l=mx[4];
loop(5,11000000)
{
	if(l<mx[i]){l=mx[i];cout<<i;nl;}
}
return 0;
}

