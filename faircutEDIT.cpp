#include<bits/stdc++.h>
using namespace std;

// Numeric Constants
#define N 1000000007
#define maxs 200005
#define mins 3005
#define eps 1e-14
#define imax 2000000200
#define llmax 1e16
#define pi 3.141592653589793

// Others
#define ll long long
#define pb push_back
#define gc getchar_unlocked
#define iosbase ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pair<int,int>,int>
#define ppl pair<pll,ll>
#define vi vector<int>
#define sc scanf
#define pr printf
#define lld I64d
#define F first
#define S second
#define siter set<int>::iterator
#define p_pq priority_queue
#define ub upper_bound
#define lb lower_bound

ll dp[mins][mins];
ll n,k,a[maxs];
ll fun(ll pos,ll p1)
{
	if(pos==n)
	{
		if(p1==k){return 0;}
		
		else{return llmax;}
	}
	
	if(p1>k){return llmax;}
	
	if(dp[pos][p1]!=-1)
	{
		return dp[pos][p1];
	}
	
	ll &ret=dp[pos][p1];
	ret=llmax;
	ll prev1=pos-p1;
	ll nxt=(n-k)-prev1;
	//cout<<pos<<" "<<p1<<" "<<prev1<<" "<<nxt<<" "<<(k-p1)<<endl;
	ret=min(ret,prev1*a[pos]-nxt*a[pos]+fun(pos+1,p1+1));
	ret=min(ret,p1*a[pos]-(k-p1)*a[pos]+fun(pos+1,p1));
	return ret;
}

int main()
{
	ll i,j;
	sc("%lld %lld",&n,&k);
	for(i=0;i<n;i++)
	{
		sc("%lld",&a[i]);
	}
  sort(a,a+n);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			dp[i][j]=-1;
		}
	}
	
	ll ans=fun(0,0);
	pr("%lld\n",ans);
	return 0;
}
