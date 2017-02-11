#include <iostream>

using namespace std;
int m,s[1000000];

void sieve()
{
s[0]=0;
s[1]=0;
for(int i=2;i<1000000;i++)
{
	if(s[i]==0)
	{
		for(int j=i;j<1000000;j+=i)
		{
			m=j;
			s[j]+=1;
			
			while(1)
			{
				m=m/i;
				if(m%i==0){s[j]+=1;}
				else{break;}			
			}

		}
	}
}
}

int main()
{
int t,n;
cin>>t;
long long int l,r;

sieve();
/*
for(int i=2;i<100;i++)
{
cout<<i<<" : "<<s[i]<<endl;
}
*/
while(t--)
{
	cin>>n;
	r=0;
	while(n--)
	{
	cin>>l;
	r=r^s[l];
	}
	if(r!=0)
	{cout<<"1"<<endl;
	}
	else
	{
	cout<<"2"<<endl;
	}
}
return 0;
}

