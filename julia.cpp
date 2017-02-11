#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct tree
{
int val;
struct tree *left,*right;
};

int cnt[200000];

void insert(struct tree *node, int a)
{
if(a<node->val)
{
	if(node->left!=NULL)
	{
		insert(node->left,a);
	}
	else
	{
		struct tree *temp;
		temp=(struct tree*)malloc(sizeof(struct tree));
		temp->val=a;
		temp->left=NULL;
		temp->right=NULL;
		node->left=temp;
	}
}
else
{
	if(node->right!=NULL)
	{
		insert(node->right,a);
	}
	else
	{
		struct tree *temp;
		temp=(struct tree*)malloc(sizeof(struct tree));
		temp->val=a;
		temp->left=NULL;
		temp->right=NULL;
		node->right=temp;
	}
}
}

void pre(struct tree *node,int i)
{
	if(node!=NULL)
	{
		cnt[i]++;
		pre(node->left,i+1);
		pre(node->right,i+1);
	}
}

int main() {
int n,a;
struct tree *root;
cin>>n;
root=(struct tree*)malloc(sizeof(struct tree));

cin>>a;
root->val=a;
root->left=NULL;
root->right=NULL;

for(int i=1;i<n;i++)
{
	cin>>a;
	insert(root,a);
}
pre(root,0);

long long int lo=0;
for(int i=1;i<n;i++)
{
//cerr<<cnt[i]<<" ";
lo+=cnt[i]*i;

}
//cerr<<endl;

cout<<lo;
return 0;
}






