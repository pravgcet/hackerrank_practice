//Matrix Right rotation [Square Matrix]
//Not efficient as rotation will be done one by one

#include <iostream>

using namespace std;

int main()
{
lli mat[1000][1000];
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		cin>>mat[i][j];
	}
}
int ul,ll,bl,rl,t,s;

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}
cout<<endl<<endl<<endl;

lli times;
times=3;//Number of times to rotate left
while(times--)
{
ul=0;ll=0;bl=n-1;rl=n-1;
	while(1)
	{
		s=mat[ul][ll];
		for(int i=ll+1;i<=rl;i++)
		{
			t=mat[ul][i];
			mat[ul][i]=s;
			s=t;
		}

		for(int i=ul+1;i<=bl;i++)
		{
			t=mat[i][rl];
			mat[i][rl]=s;
			s=t;
		}

		for(int i=rl-1;i>=ll;i--)
		{
			t=mat[bl][i];
			mat[bl][i]=s;
			s=t;
		}

		for(int i=bl-1;i>ul;i--)
		{
			t=mat[i][ll];
			mat[i][ll]=s;
			s=t;
		}
		mat[ul][ll]=s;
		ll++;ul++;bl--;rl--;
		if(ll>=rl){break;}
	}
}

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}



