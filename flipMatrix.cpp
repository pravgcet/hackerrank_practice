#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int q,n,ar[300][300],tm[300][300];
long long int sm,ts;

void copy()
 {
   for(int i=0;i<2*n;i++)
   {
    for(int j=0;j<2*n;j++)
     {
      tm[i][j]=ar[i][j];
     }
  }
}

long long int rever(int r,int c)
{
    int z;
    long long int o=0;
    for(int i=0;i<n;i++)
        {
        z=tm[i][c];
        tm[i][c]=tm[2*n-1-i][c];
        tm[2*n-1-i][c]=z;
    }

    for(int i=0;i<n;i++)
        {
        z=tm[r][i];
        tm[r][i]=tm[r][2*n-1-i];
        tm[r][2*n-1-i]=z;
    }
  
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
            {
            o+=tm[i][j];
            }
        }

    for(int i=0;i<n;i++)
        {
        z=tm[r][i];
        tm[r][i]=tm[r][2*n-1-i];
        tm[r][2*n-1-i]=z;
    }

    for(int i=0;i<n;i++)
        {
        z=tm[i][c];
        tm[i][c]=tm[2*n-1-i][c];
        tm[2*n-1-i][c]=z;
    }
    
    return o;
}

int main() {
   cin>>q;
   while(q--)
   {
    sm=0;
    cin>>n;
    for(int i=0;i<2*n;i++)
        {
        for(int j=0;j<2*n;j++)
            {
    	        cin>>ar[i][j];
            }
        }
     copy();
     for(int i=0;i<2*n;i++)
      {
        for(int j=0;j<2*n;j++)
            {
                ts=rever(i,j);
                if(ts>sm){sm=ts;}
            }
        }
      cout<<sm<<endl; 
    }
   return 0;
}

