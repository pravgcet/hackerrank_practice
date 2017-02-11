//https://www.hackerrank.com/challenges/s10-basic-statistics/submissions/code/28558935

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n,ar[2500];
    long long int sm=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sm+=ar[i];
    }
    cout<<(sm/(double)n)<<endl;
    sort(ar,ar+n);
    if(n%2==0)
    {
      cout<<(ar[n/2-1]+ar[n/2])/2.0<<endl;
    }
    else
    {
       cout<<ar[n/2+1]<<endl;
    }
int c=1,e=ar[0],tc=1;
    for(int i=0;i<n-1;i++)
    {
        if(ar[i]==ar[i+1])
        {
        
            tc++;
        }
        else
        {
            if(tc>c){c=tc;e=ar[i];i++;}
  				//	if(tc>1){cout<<ar[i]<<" - "<<tc<<endl;}
  					tc=1;
  		   }
    }

    cout<<e<<endl;    

    return 0;
}

