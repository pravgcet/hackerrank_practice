#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
int ar[100];
for(int i=0;i<100;i++){cin>>ar[i];}
int l,nl;
l=max(ar[0],ar[1]);
nl=min(ar[0],ar[1]);

for(int i=2;i<100;i++)
{
if(ar[i]>l){nl=l;l=ar[i];}
else if(ar[i]>nl){nl=ar[i];}

}

sort(ar,ar+100);

for(int i=0;i<100;i++)
{
cout<<ar[i]<<endl;
}

cout<<nl<<endl;
return 0;
}


