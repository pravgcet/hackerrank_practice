#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string s;
typedef long long int lli;
lli md=1e9+7;

lli power(lli a, lli y)
{
	lli o;
   if(y==1)
        return a;
 
   else if(y%2==1)
        {o=power(a,y/2);
        return (((o*o)%md)*y)%md;}
   else
    {   o=power(a,y/2);
        return (o*o)%md;}
}

int check(int e)
    {
    for(int i=0;i<e;i++)
        {
        if(s[i]!=s[e+i]){return 0;}
    }
    return 1;
}

int findall(int st,int e,int l)
    {
    cerr<<"In T"<<endl;
    int i,c=e;
    while(1)
    {
        for(i=st;i<e;i++)
         {
            if((c==l-1)&&(i!=e-1))
                {return 0;}
            
            if(c!=l)
            {
            if(s[i]!=s[c])
                { cerr<<"In T, Not equal : "<<i<<" - "<<c<<endl;
                return 0;}
            c++;
            
        		}}
        if(c==l){return (e-st);}
    }
}

int main() {
    int r,t;
		long long int n,inv,l;
    getline(cin,s);
    cin>>n;
    l=s.length();
    while(1)
    {
      for(int i=1;i<l;i++)
        {
         if(s[i]==s[0])
           {
             r=check(i);
             cerr<<"Found at "<<i<<" r : "<<r<<endl;
             if(r>0)
                {
                 t=findall(0,i,l);
                 cerr<<"T : "<<t<<endl;
                 if(t>0)
                   {
                    cerr<<"Found"<<endl;
										//inv=power(t,md-2);
										cout<<(n/((lli)t))%md;
                    return 0;
                   }
                }
            }
        }
            if(r==0||t==0)
                {
                cerr<<"Whole string "<<endl;
								//inv=power(l,md-2);
                cout<<(n/l)%md;
                return 0;
            }


    }
    
    return 0;
}

