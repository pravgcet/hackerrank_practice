//Matrix Left rotation [Rectangular Matrix]
//Not efficient as rotation will be done one by one

#include <iostream>

using namespace std;

int main()
{
typedef long long int lli;
lli mat[1000][1000],t,s,times,tim,ti;
int m,n;
cin>>m>>n>>times;
for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		cin>>mat[i][j];
	}
}
int ul=0,ll=0,bl=m-1,rl=n-1;
/*
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}
cout<<endl<<endl<<endl;
*/
//times=1;//Number of times to rotate left
ul=0;ll=0;bl=m-1;rl=n-1;
while(1)
{
ti=times%(2*(bl-ul+1)+2*(rl-ll+1-2));
//cerr<<"Times "<<ti<<endl;
		while(ti--)
		{
			s=mat[ul][ll];
			for(int i=ul+1;i<=bl;i++)
			{
				t=mat[i][ll];
				mat[i][ll]=s;
				s=t;
			}
			for(int i=ll+1;i<=rl;i++)
			{
				t=mat[bl][i];
				mat[bl][i]=s;
				s=t;
			}
			for(int i=bl-1;i>=ul;i--)
			{
				t=mat[i][rl];
				mat[i][rl]=s;
				s=t;
			}
			for(int i=rl-1;i>ll;i--)
			{
				t=mat[ul][i];
				mat[ul][i]=s;
				s=t;
			}
			mat[ul][ll]=s;
		}
ll++;ul++;bl--;rl--;
if(ll>=rl||ul>=bl){break;}
}

for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}



