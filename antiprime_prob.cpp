#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define nl cout<<endl
#define loop(a,b) for(int i=a;i<b;i++)
using namespace std;

int main()
{
int n,q,l=0;
int anti[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400,665280,720720,1081080,1441440,2162160,2882880,3603600,4324320,6486480,7207200,8648640,10810800};

cin>>n;
while(n--)
{
cin>>q;
/*
if(q==1){cout<<1;nl;}
else if(q==2){cout<<2;nl;}
else{*/
loop(0,48)
{
if(anti[i]>=q){cout<<anti[i];nl;break;}
}
}
//}

return 0;
}
