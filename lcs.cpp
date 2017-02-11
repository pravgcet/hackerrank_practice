#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#define nl cerr<<endl;

using namespace std;

int a[6000][6000],mat[6000][6000];
char b[6000][6000];

int main()
{

vector<int > vec;
vector<int > ::iterator it;
int n,m,prs[128],l,cnt=0,mx,t;
string s1,s2,s3,s4;	
cin>>t;

while(t--)
{
vec.clear();
	cin>>s1>>s2;

	n=s1.length();
	m=s2.length();

//Operating on normal string
//	cout<<s1<<endl<<s2<<endl;
	for(int i=2;i<n+2;i++)
	{
        if(s1[i-2]>96){a[i][0]=s1[i-2]-32;}
        else{a[i][0]=s1[i-2];}
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
				mat[i][j]=3;
			}
			else if(a[i-1][j]>a[i][j-1])
			{
				a[i][j]=a[i-1][j];
				mat[i][j]=2;
			}
			else
			{
				a[i][j]=a[i][j-1];
				mat[i][j]=1;
			}
		}
	}
if(a[n+1][m+1]==m)
{
	int i=n+1,j=m+1,no=0;
	while(1)
	{
		if(mat[i][j]==3){vec.push_back(i);if(a[i][j]==1){break;}i--;j--;}
		else if(mat[i][j]==2){i--;}
		else {j--;}
	}
	sort(vec.begin(),vec.end());
	for(it=vec.begin();it!=vec.end();it++)
	{
	 *it-=2;
	}
/*
	for(it=vec.begin();it!=vec.end();it++)
	{
	cout<<*it<<" ";
	}
	cout<<endl;
	*/int fd,vl=vec.size(),fs,ix;


int y,sc;
if(m>1)
{
	fs=0;
	ix=0;
	sc=vec[1];
	for(int k=0;k<m-1;k++)
	{
		fd=0;
		for(y=fs;y<sc;y++)
		{
			if(s1[y]==s2[k]){fd=1;s1[y]=100;fs=y+1;break;}
		}
		if(fd==0)
		{
			s1[vec[ix]]=100;
			fs=vec[ix]+1;
		}																										
			ix++;
			sc=vec[ix+1];																											
	}
	int k=m-1;
		sc=n;
		for(y=fs;y<sc;y++)
		{
			if(s1[y]==s2[k]){fd=1;s1[y]=100;fs=y+1;break;}
		}
		if(fd==0)
		{
			s1[vec[ix]]=100;
		}																										
	
}
else
{
	cnt=0;
	for(int k=0;k<n;k++)
	{
	if(s1[k]<97)
	{
	cnt++;
	if(cnt>1)
	{
	break;
	}
	}
	}
	if(cnt>1){cout<<"NO"<<endl;continue;}
	cout<<"YES"<<endl;
}
	for(int k=0;k<n;k++){if(s1[k]<97){no=1;break;}}
	if(no==0)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
else{cout<<"NO"<<endl;}
}
return 0;
}
