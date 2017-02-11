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
//	cerr<<"Hello"<<endl;
	vector<int> chr;
	vector<vector<int> > loc(128);

	vector<int> :: iterator it,lt;
	int n,m,prs[128],l,cnt=0,mx;
	string s1,s2,s3,s4;	
	cin>>s1>>s2;
//	cerr<<"Hello"<<endl;

	n=s1.length();
	m=s2.length();
	cerr<<n<<" "<<m<<endl;
//	cerr<<"Hello"<<endl;
	s3=s1;
	s4=s2;
	memset(prs,0,sizeof(prs));
//	cerr<<"Hello"<<endl;
	for(int i=0;i<m;i++){prs[s2[i]]=1;};	
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
			}
			else if(a[i-1][j]>a[i][j-1])
			{
				a[i][j]=a[i-1][j];
			}
			else
			{
				a[i][j]=a[i][j-1];
			}
		}
	}
//cerr<<"Operation on normal string done"<<endl;
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
mx=a[n+1][m+1];	
/*
cerr<<s3<<endl<<s4;nl;

for(int i=2;i<n+2;i++)
{
	for(int j=2;j<m+2;j++)
		{
		cerr<<a[i][j]<<"  ";
}
nl;
}
cerr<<"-----------------------------------";nl;
for(int i=2;i<n+2;i++)
{
	for(int j=2;j<m+2;j++)
		{
		cerr<<mat[i][j]<<"  ";
}
nl;
}
*/
//cerr<<"MX is "<<mx<<endl;
//Checking a's first place
//cerr<<"First place ";nl;
for(int i=0;i<128;i++)
{
	if(prs[i]==1){chr.push_back(i);}
}

for(it=chr.begin();it!=chr.end();it++)
{
//	cerr<<"Putting "<<(char)(*it);nl;
		for(int k=0;k<m;k++)
			{
				if(*it==s4[k])
					{
						if(k==0)
							{
								l=mat[n+1][m-1-k-1+2]+1;
  							//cerr<<"I at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}
							else if(k==m-1)
							{
								l=1;
	  						//cerr<<"II at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}
							else
							{
								l=mat[n+1][m-1-k-1+2]+1;
					  		//cerr<<"III at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}						
					}			
			}		
}

//cerr<<"Cnt is "<<cnt<<endl;
nl;
//Checking a's last place
//cerr<<"Last place ";nl;
for(it=chr.begin();it!=chr.end();it++)
{
	//cerr<<"Putting "<<(char)i;nl;
		for(int k=0;k<m;k++)
			{
				if(*it==s4[k])
					{
						if(k==0)
							{
							l=1;
							//cerr<<"I at K "<<k<<" : "<<l;nl;
							if(l>mx){cnt++;break;}
							}
							else if(k==m-1)
							{
								l=a[n+1][m]+1;
							//cerr<<"II at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}
							else
							{
								l=a[n+1][k+1]+1;
							  //cerr<<"III at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}						
					}			
			}		
}
for(int k=0;k<m;k++)
{
	loc[(int)s4[k]].push_back(k);
}

int k;
//cerr<<"Cnt is "<<cnt<<endl;
nl;
//cerr<<"Checking intermediate"<<endl;
for(it=chr.begin();it!=chr.end();it++)
{
//	cerr<<"Putting "<<(char)(*it);nl;
		for(int j=0;j<n-1;j++)
		{
		//cerr<<"At j = "<<j<<endl;
for(lt=loc[(*it)].begin();lt!=loc[(*it)].end();lt++)
//		for(int k=0;k<m;k++)
			{k=(*lt);
//			if(*it==s4[k])
					{
					if(k==0)
							{	l=mat[n-1-j-1+2][m]+1;
							  //cerr<<"I at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}
							else if(k==m-1)
							{
								l=a[j+2][m]+1;
							  //cerr<<"II at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}
							else
							{
								l=mat[n-1-j-1+2][m-1-k-1+2]+a[j+2][k+1]+1;
//							cerr<<a[j+2][k+1]<<endl;
							  //cerr<<"III at K "<<k<<" : "<<l;nl;
								if(l>mx){cnt++;break;}
							}						
					}			
			}		
	}
}

cout<<cnt;
//nl;nl;nl;
return 0;

}






 
