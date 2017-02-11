//https://www.hackerrank.com/contests/moodysuniversityhackathon/challenges/asterisk-expressions
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

typedef long long int lli;

lli mod;

int ar[1000000];

lli power(lli a, lli y)
{
   if(y==1)
        return a;
   else if(y%2==1)
        return (power(a,y/2)*power(a,y/2) * a)%mod;
   else
        return (power(a,y/2)*power(a,y/2))%mod;
}

lli eval(int x)
{
lli t,y,u;
stack <lli > st;
vector<lli > vec;

for(int i=0;i<x;i++)
{
	//cerr<<" i "<<i<<endl;
	if(ar[i]>-1)
	{
		vec.push_back(ar[i]);
	}
	else
	{
		if(st.empty()){st.push(ar[i]);}
		else
		{
			t=st.top();
		//cerr<<"T is "<<t<<endl;
			if(ar[i]>t){st.push(ar[i]);}
			else
			{
				//cerr<<"In else"<<endl;
				while(ar[i]<=t)
				{
					vec.push_back(t);
					st.pop();
					if(st.empty())
					{break;}
					t=st.top();
				}
				st.push(ar[i]);
			}
		}
	}
}
while(!(st.empty()))
{
	t=st.top();
	vec.push_back(t);
	st.pop();
}
/*
cerr<<"Postfix is "<<endl;
for(int i=0;i<x;i++)
{
	cerr<<vec[i]<<" ";
}
cerr<<endl;
*/

for(int i=0;i<x;i++)
{
	if(vec[i]<0)
	{
		t=st.top();st.pop();
		y=st.top();st.pop();
		if(vec[i]==-1)
		{
			u=power(y,t);
			
		//	cerr<<"Power : "<<y<<" ^ "<<t<<" : "<<u<<endl;
			st.push(u);
		}
		else
		{
			u=(y*t)%mod;
	//		cerr<<"Mult : "<<u<<endl;
			st.push(u);
		}
	}
	else
	{
		st.push(vec[i]);
	}
}

t=st.top();

return t;
}

int main()
{
char *cs;
int x,l,f,e,t,ct,gh;
string s,sub;
mod=1e9+7;
cin>>t;
while(t--)
{
	cin>>s;
	l=s.length();
	x=0;

	if(s[0]=='0')
	{
	cout<<"Syntax Error"<<endl;
	continue;
	}

	if(l>2){
	if(s[0]=='0'||s[l-1]=='0'&&s[l-2]=='*')
	{
	cout<<"Syntax Error"<<endl;
	continue;
	}}
	if(s[0]=='*'||s[l-1]=='*')
	{
	cout<<"Syntax Error"<<endl;
	continue;
	}
	l--;ct=1;
	for(int i=1;i<l;i++)
	{
		if(s[i]=='*')
		{ct=1;i++;
		while(s[i]=='*'){i++;ct++;}i--;
		if(ct>2){cout<<"Syntax Error"<<endl;break;}
		}
	}	
	l++;
	if(ct>2){continue;}
	for(int i=0;i<l;i++)
	{gh=0;
	if(s[i]==48)
	{
		gh=1;break;
	}
		if(s[i]>48&&s[i]<=57)
		{
			f=i;e=1;
			i++;
			while(s[i]>=48&&s[i]<=57){i++;e++;}
			sub=s.substr(f,e);
			cs=const_cast<char*>(sub.c_str());
			ar[x++]=(atoll(cs))%mod;
			i--;
		}
		else if(s[i]=='*'&&s[i+1]=='*'){ar[x++]=-1;i++;}
		else if(s[i]=='*'&&s[i+1]!='*'){ar[x++]=-2;}
	}
	if(gh==1)
	{
	cout<<"Syntax Error"<<endl;
	continue;
	}
/*
	for(int i=0;i<x;i++)
	{
	cerr<<ar[i]<<"  ";
	}
	cerr<<"x is "<<x<<endl;
*/	cout<<eval(x)<<endl;
}


return 0;
}

