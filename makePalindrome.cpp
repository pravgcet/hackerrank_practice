//https://www.hackerrank.com/challenges/palindrome-index

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int res(int a,int b)
{
	while(b>a)
	{
		if(s[a]==s[b]){a++;b--;}
		else return -1;
	}
return 0;
}

int main() {
int t,l,a,b,cnt,x,r,q;

    cin>>t;
    while(t--)
        {
        cin>>s;
        l=s.length();
        a=0;b=l-1;cnt=0;
        while(b>a)
        {
            if(s[a]==s[b]){a++;b--;}
            else if(b-1>a&&a+1<b&&s[b-1]==s[a]&&s[b]==s[a+1])
						{
								cnt++;r=res(a,b-1);q=res(a+1,b);
								if(r==-1)
								{
									if(q==-1){cnt++;cout<<-1;break;}
									else{x=a;a+=2;b--;}
								}
								else
								{
									x=b;
									b-=2;a++;
								}
						}
								
            else if(b-1>a&&s[b-1]==s[a]){x=b;a++;b-=2;cnt++;}
            else if(a+1<b&&s[a+1]==s[b]){x=a;a+=2;b--;cnt++;}
        
            
            if(cnt>1){cout<<-1<<endl;break;}
        }
        if(cnt==0){cout<<-1<<endl;}
        if(cnt==1){cout<<x<<endl;}
    }
    return 0;
}


