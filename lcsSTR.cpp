#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define nl cout<<endl;

using namespace std;
int main()
{
	int n,m;
	string s1,s2;	
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	int a[n+2][m+2],mat[n+2][m+2];
	char b[n+2][m+2];

//Operating on normal string
	for(int i=2;i<n+2;i++)
	{
		a[i][0]=s1[i-2];
		a[i][1]=0;
	}
	
	for(int i=2;i<m+2;i++)
	{
		a[0][i]=s2[i-2];
		a[1][i]=0;
	}
	
	a[1][1]=0;
	a[0][0]=a[1][0]=a[0][1]=0;

	for(int i=2;i<n+2;i++)
	{
		for(int j=2;j<m+2;j++)
		{
			if(a[i][0]==a[0][j])
			{
				a[i][j]=a[i-1][j-1]+1;
				b[i][j]='d';
			}
			else if(a[i-1][j]>a[i][j-1])
			{
				a[i][j]=a[i-1][j];
				b[i][j]='u';
			}
			else
			{
				a[i][j]=a[i][j-1];
				b[i][j]='l';
			}
		}
	}
//Operating on reversed string
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());

	
	for(int i=2;i<n+2;i++)
	{
		mat[i][0]=s1[i-2];
		mat[i][1]=0;
	}
	
	for(int i=2;i<m+2;i++)
	{
		mat[0][i]=s2[i-2];
		mat[1][i]=0;
	}
	
	mat[1][1]=0;
	mat[0][0]=0;
	mat[1][0]=0;
	mat[0][1]=0;
	for(int i=2;i<n+2;i++)
	{
		for(int j=2;j<m+2;j++)
		{
			if(mat[i][0]==mat[0][j])
			{
				mat[i][j]=mat[i-1][j-1]+1;
			}
			else if(mat[i-1][j]>mat[i][j-1])
			{
				mat[i][j]=mat[i-1][j];
			}
			else
			{
				mat[i][j]=mat[i][j-1];
			}
		}
	}
///////End of string preprocessing

	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}

	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
		{
			cout<<mat[i][j]<<"   ";
		}
		cout<<endl;
	}



	for(int i=2;i<n+2;i++)
	{
		for(int j=2;j<m+2;j++)
		{
			cout<<b[i][j]<<"    ";
		}
		cout<<endl;
	}
	int i=n+1,j=m+1,k,c[100],r;
	r=k=a[i][j];
	//cout<<"K is : "<<k<<endl;
	while(k)
	{
		if(b[i][j]=='d')
		{
			//cout<<"Ele : "<<a[0][j]<<endl;
			k--;
			c[k]=a[0][j];
			i--;
			j--;
		}
		else if(b[i][j]=='l')
		{
			j--;
		}
		else
		{
			i--;
		}
	}
	for(int z=0;z<r;z++)
		{
			cout<<c[z]<<" ";
		}
nl;nl;

return 0;
}
