//Coin change with no repetition
#include <iostream>
using namespace std;
int br[11];

int find(int ar[],int n, int v)
{
	if((ar[n]==v)){return 1;}
	else if(n<0){return 0;}
	else return find(ar,n-1,v)+find(ar,n-1,v-ar[n]);
}

int main()
{
	int ar[]={1,2,3,4,5,6,7,8,9,10};
	int v=4;
	cout<<find(ar,1,6)<<endl;
	return 0;
}













