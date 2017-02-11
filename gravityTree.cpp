#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long int lli;

vector<vector<int> > gr(100001),tr(100001),ch(100000); 
vector<int > chil;
queue <int > tm;
vector<int > :: iterator it,pt;
vector <pair<int,lli> > tb,tc;
vector <pair<int,lli> > :: iterator tt,ty;
void findchil()
{
int a;
	while(!tm.empty())
	{
		a=tm.front();
		tm.pop();
		chil.pb(a);
		for(pt=tr[a].begin();pt!=tr[a].end();pt++)
		{
            tm.push(*pt);
		}
	}	
}
lli findlen(int a,int b)
{
//cerr<<"Finding length"<<endl;
	int k=a,l=b,m=a,n=b;
	pair<int,lli> p;
  lli cn=0,cm=0;
	tb.pb(mp(k,0));
	tc.pb(mp(n,0));
    while(1)
    {
//		cerr<<cn<<endl;
//////////////////////If u has less depth in line graph
		  for(tt=tb.begin();tt!=tb.end();tt++)
			{
				if((*tt).first==l)
		        {
		         return (cn+(*tt).second);
		        }
			}
     p=tb.back();
		if(p.first!=1)	
     {tb.pb(mp(ch[p.first].front(),p.second+1));
     }
     if(l!=1)
     {l=ch[l].front();
     cn++;}
/////////////////////If V has less depth in line graph    
	  for(ty=tc.begin();ty!=tc.end();ty++)
		{
			if((*ty).first==m)
	     {
	      return (cm+(*ty).second);
	     }
		}
    p=tc.back();
		if(p.first!=1)	
    {
    	tc.pb(mp(ch[p.first].front(),p.second+1));
    }
    if(m!=1)
    {m=ch[m].front();
    cm++;}
    }
}

int main()
{
int n,a,q,u,v;
long long int dist,di,dj;
cin>>n;
for(int i=2;i<=n;i++)
{cin>>a;
gr[a].pb(i);
gr[i].pb(a);
tr[a].pb(i);
ch[i].pb(a);
}
cin>>q;
while(q--)
{
dist=0;   
cin>>u>>v;
tm.push(v);
findchil();
    
 for(it=chil.begin();it!=chil.end();it++)
	{
   di=di+1;
    tb.clear();
		tc.clear();
    di=findlen(u,*it);
   // tb.clear();
   // dj=findlen(*it,u);    
	//	di=min(di,dj);
		dist+=di*di;

	}
   
cout<<dist<<endl;
chil.clear();
}
return 0;
}

