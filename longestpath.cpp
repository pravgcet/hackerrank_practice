#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#define gc getchar_unlocked
#define mp make_pair
#define pb push_back
using namespace std;
vector <vector<int> > gr(600000);
vector <int> ::iterator it;
int lf[600000],vis[600000];

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int findpathlen(int a)
{
int mpl=0;
memset(vis,0,sizeof(int)*600000);
queue<pair<int,int> > qu;
pair<int,int> p;
for(it=gr[a].begin();it!=gr[a].end();it++)
{
	qu.push(mp(*it,1));
}

while(!qu.empty())
{
	p=qu.front();
	vis[p.first]=1;
	qu.pop();
	if(lf[p.first]==1){mpl=max(mpl,p.second);}
	else 
	{
		for(it=gr[p.first].begin();it!=gr[p.first].end();it++)
		{
			if(vis[*it]==0)
			{	qu.push(mp(*it,p.second+1));}
		}
	}
}
return mpl;
}

int main()
{
int n,a,b;
scanint(n);
for(int i=1;i<n;i++)
{
	scanint(a);
	scanint(b);
	gr[a].pb(b);
	gr[b].pb(a);
	lf[a]++;
	lf[b]++;
}
int mx=0;
for(int i=1;i<=n;i++)
{
	if(lf[i]==1)
	{
		if(!gr[i].empty())
		{//cerr<<"Found leaf : "<<i<<endl;
		mx=max(mx,findpathlen(i));
		}
	}
}
cout<<mx+1<<endl;
return 0;
}
