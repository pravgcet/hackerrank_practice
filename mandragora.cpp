#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
long long int t,n,a,ar[100000],f,m,tm,mx;
    long long int s,p;
    cin>>t;
    while(t--)
    {f=0;m=0;mx=0;
        s=1;p=0;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
		sort(ar,ar+n);

        for(int i=n-1;i>-1;i--)
        {
        	m+=ar[i];
        	tm=m*(i+1);
        	if(tm>mx){mx=tm;}
        }
      cout<<mx<<endl;        
        
        
    }
    
    return 0;
}

