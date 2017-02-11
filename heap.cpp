#include <iostream>
#include <vector>

using namespace std;

vector < int > heap(101);
int s;

void heapify(int a)
{
int l=a;
if(2*a <=s)
{
if(heap[l]<heap[2*a]){l=2*a;}

if(2*a+1 <=s)
{
	if(heap[l]<heap[2*a+1]){l=2*a+1;}
}

if(l!=a)
{
	int t;
	t=heap[l];
	heap[l]=heap[a];
	heap[a]=t;

heapify(l);
}

}

}

void delet()
{
int a;

}

void insert(int a)
{
	heap[s+1]=a;
	s++;

	heapify(1);
}

int main()
{

	int n,v;
	cin>>n;
	for(int i=1;i<=n;i++){heap[i]=-999;}

	for(int i=1;i<=n;i++)
	{
		cin>>v;

		insert(v);
		cout<<" \niteration : "<<i<<endl;

		for(int j=1;j<=n;j++)
		{
			cout<<heap[j]<<" ";

		}
	}


	return 0;
}




