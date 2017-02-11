#include <iostream>
#include <stack>

using namespace std;
int v[50][50];

void trav(int r,int c,int n,int m)
{
stack<pair<int,int> > st;
st.push(make_pair(r,c));
pair<int, int > pr;

while(!st.empty())
{
pr=st.top();
int x=pr.first,y=pr.second;
v[pr.first][pr.second]=8;
st.pop();

if(x==0)
{
	if(y==0)
	{
		if(x+1<n)
		{
			if(v[x+1][y]==1){st.push(make_pair(x+1,y));}
			if(y+1<m)
			{
				if(v[x][y+1]==1){st.push(make_pair(x,y+1));}
				if(v[x+1][y+1]==1){st.push(make_pair(x+1,y+1));}
			}
		}
	}
	else if(y==m-1)
	{
		if(x+1<n)
		{
			if(v[x+1][y]==1){st.push(make_pair(x+1,y));}
			if(y-1>-1)
			{
				if(v[x][y-1]==1){st.push(make_pair(x,y-1));}
				if(v[x+1][y-1]==1){st.push(make_pair(x+1,y-1));}
			}
		}
	}
	else
	{
			if(v[x][y-1]==1){st.push(make_pair(x,y-1));}
			if(v[x][y+1]==1){st.push(make_pair(x,y+1));}
			
			if(x<n-1)
			{
				if(v[x+1][y-1]==1){st.push(make_pair(x+1,y-1));}
				if(v[x+1][y]==1){st.push(make_pair(x+1,y));}
				if(v[x+1][y+1]==1){st.push(make_pair(x+1,y+1));}
			}
	}
	
	
}
else if(x==n-1)
{
	if(y==0)
	{
		if(x-1>-1)
		{
			if(v[x-1][y]==1){st.push(make_pair(x-1,y));}
			if(y+1<m)
			{
				if(v[x][y+1]==1){st.push(make_pair(x,y+1));}
				if(v[x-1][y+1]==1){st.push(make_pair(x-1,y+1));}
			}
		}
	}
	else if(y==m-1)
	{
		if(x-1>-1)
		{
			if(v[x-1][y]==1){st.push(make_pair(x-1,y));}
			if(y-1>-1)
			{
				if(v[x][y-1]==1){st.push(make_pair(x,y-1));}
				if(v[x-1][y-1]==1){st.push(make_pair(x-1,y-1));}
			}
		}
	}
}
else
{
	if(v[x-1][y]==1){st.push(make_pair(x-1,y));}
	if(v[x+1][y]==1){st.push(make_pair(x+1,y));}

	if(y==0)
	{
		if(y+1<m)
		{
			if(v[x-1][y+1]==1){st.push(make_pair(x-1,y+1));}
			if(v[x][y+1]==1){st.push(make_pair(x,y+1));}
			if(v[x+1][y+1]==1){st.push(make_pair(x+1,y+1));}
		}
	}
	else if(y==m-1)
	{
		if(y-1>-1)
		{
			if(v[x-1][y-1]==1){st.push(make_pair(x-1,y-1));}
			if(v[x][y-1]==1){st.push(make_pair(x,y-1));}
			if(v[x+1][y-1]==1){st.push(make_pair(x+1,y-1));}
		}
	}
	else
	{
			if(v[x-1][y-1]==1){st.push(make_pair(x-1,y-1));}
			if(v[x][y-1]==1){st.push(make_pair(x,y-1));}
			if(v[x+1][y-1]==1){st.push(make_pair(x+1,y-1));}
			if(v[x-1][y+1]==1){st.push(make_pair(x-1,y+1));}
			if(v[x][y+1]==1){st.push(make_pair(x,y+1));}
			if(v[x+1][y+1]==1){st.push(make_pair(x+1,y+1));}
	}
}
}
}

int main()
{
int m,n,ar[50][50];
cin>>n>>m;
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		cin>>v[i][j];
	}
}

int cn=0;
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		if(v[i][j]==1){trav(i,j,n,m);cn++;
		cout<<endl<<endl;
		for(int ii=0;ii<n;ii++)
			{
				for(int jj=0;jj<m;jj++)
				{
					cout<<v[ii][jj]<<" ";
				}
				cout<<endl;
			}

		}
	}
}
cout<<"Number of islands : "<<cn<<endl;

for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		cout<<v[i][j]<<" ";
	}
	cout<<endl;
}



return 0;
}

//1 2 3 4 5 6 7 8 9 0
