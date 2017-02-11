#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;


int main()
{
map<lli, vector< pair<lli,lli> > > dat;

map<lli, vector< pair<lli,lli> > > :: iterator mit;

vector< pair<lli,lli> > :: reverse_iterator nit;

vector< pair<lli,lli> > :: iterator it;

lli n,k,a,b,cnt=0,pr=0;
cin>>n>>k;

while(n--)
{
cin>>a>>b;
dat[-a-b].push_back(make_pair(a,b));
}
for(mit=dat.begin();mit!=dat.end();mit++)
{
	sort((mit->second).begin(),(mit->second).end());
//	cout<<mit->first<<" - "<<(mit->second).size()<<endl;
/*		if((mit->second).size()>1)
		{
			for(nit=(mit->second).begin();nit!=(mit->second).end();nit++)
			{
				cout<<nit->first<<" "<<nit->second<<endl;
			}		
		cout<<endl<<endl;
		}
*/
cout<<cnt<<" - "<<pr<<endl;

	for(it=(mit->second).begin();it!=(mit->second).end();it++)
	{
		if(cnt<k)
		{
			pr+=it->first;
			cnt++;
		}
		else
		{
			pr-=it->second;

		}
		
	}

}

cout<<pr;
return 0;
}
