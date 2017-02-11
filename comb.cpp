//Generate n choose k
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
int n,k;
cin>>n>>k;
string s(k,'a');
s.resize(n,'b');

do
{
	for(int i=0;i<n;i++)
	{
	if(s[i]){cout<<i<<" ";}
	}
	cout<<endl;
}while(prev_permutation(s.begin(),s.end()));

return 0;
}


