#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define pb push_back
#define pp pop_back
#define newline cout<<endl
using namespace std;
int main() 
{
 int n,k,q,s,t,w,x,y;
 cin>>n>>k>>q;
vector<vector<int> > teams(n+1);
vector<int > t1;
vector<int> t2;
vector<int > :: iterator it;    
while(n--)
    {
    cin>>s>>t;
    teams[t].pb(s);
}

for(int i=1;i<=k;i++)
    {
 sort(teams[i].begin(),teams[i].end());
/*    
    for(it=teams[i].begin();it!=teams[i].end();it++)
        {
        cout<<*it<<" ";
    }
    newline;*/
}

while(q--)
    {
    cin>>w>>x>>y;
    if(w==1)
    {
       teams[y].pb(x);
       sort(teams[y].begin(),teams[y].end());
    } 
    else
    {
       t1=teams[x];
       t2=teams[y];
      while(1)
          {
          int s1=t1.size(),s2=t2.size(),p;
          cout<<s1<<" "<<s2;
          newline;
        int ch=1;
          while(1)
          {
              if(ch==1)
              {
               p=t1[s1-1];    
               while(p--&&s2>0)
                   {
                   t2.pp();
                   s2--;
               }
                 if(s2<1){
                  cout<<x;
                  newline;
                     break;
                }
                ch=2;
              }
              else
                  {
               p=t2[s2-1];    
               while(p--&&s1>0)
                   {
                   t1.pp();
                   s1--;
               }
                 if(s1<1){
                  cout<<y;
                  newline;
                     break;
                }
                ch=1;
              }
          }
      }
    }
}
    return 0;
}

