//Length of longest Arithmatic Progression
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int findlen(map<int, vector<pair<int,int > > > mpl,int vl)
{
vector<pair<int,int> > vc;
vector<pair<int,int> > :: iterator vit;
int mx=2,tx=0,el;
sort(mpl[vl].begin(),mpl[vl].end());

while(1)
{
	if(tx>mpl[vl].size()){break;}
	vit=mpl[vl].begin();
	el=(*vit).second;
	mpl[vl].erase(vit);
	vit=mpl[vl].begin();	tx=2;
	while(vit!=mpl[vl].end())
	{
	if((*vit).first==el){tx++;el=(*vit).second;mpl[vl].erase(vit);vit=mpl[vl].begin();}
	else{vit++;}
	}
	if(tx>mx){mx=tx;}
}

return mx;
}


int longestAP(int ar[],int n)
{
	int dif[n+1][n+1];
	map<int, int> mp;
	map<int, vector<pair<int,int > > > mpl;
	map<int, int> :: iterator mit;
	map<int, vector<pair<int,int > > > mvpit;
	vector<pair<int,int> > vc;
	vector<pair<int,int> > :: iterator vit;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dif[i][j]=ar[j]-ar[i];
			if(mp.find(dif[i][j])==mp.end()){mp[dif[i][j]]=1;}
			else {mp[dif[i][j]]=mp[dif[i][j]]+1;}
			mpl[dif[i][j]].push_back(make_pair(i,j));
		}
	}

	for(mit=mp.begin();mit!=mp.end();mit++){vc.push_back(make_pair(mit->second,mit->first));}

	sort(vc.begin(),vc.end());
	reverse(vc.begin(),vc.end());
	
	int len=2,mx=2;

	for(vit=vc.begin();vit!=vc.end();vit++)
	{
		cout<<(*vit).first<<" - "<<(*vit).second<<endl;	
		
		if(mpl[(*vit).second].size>len)	
		{
			len=findlen(mpl,(*vit).second);				
			if(len>mx){mx=len;}
		}
	
	}
	
return mx;
}

int main()
{
	int n,ar[100];
	cin>>n;
	for(int i=1;i<=n;i++){cin>>ar[i];}
	cout<<longestAP(ar,n)<<endl;
	return 0;
}
