#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define nl cout<<endl
#define loop(a,b) for(int i=a;i<b;i++)
using namespace std;

int pr[20000000];

int main()
{
int n,q,l=0;
int x1,x2,y1,y2,r;
pr[1]=1;
loop(0,78500)
{
cin>>n;
pr[n]=2;
}

loop(4,11000000)
{
if(pr[i]<2)
{
pr[i]=2;
q=sqrt(i);
r=ceil(i/float(q));
if(r==q){pr[i]++;q--;}
	for(int j=q;j>1;j--)
			{
				if(i%j==0){pr[i]+=2;}
			}
}
cerr<<i<<endl;
}
//cout<<"===================================================";nl;
loop(1,11000000)
{
	cout<<pr[i];nl;
}

return 0;
}

