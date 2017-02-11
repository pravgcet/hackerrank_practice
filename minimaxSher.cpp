#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int n,p,q,m;
    cin>>n;
    long long int ar[n],mx=-1,in=0,t1,t2;
    for(int i=0;i<n;i++){cin>>ar[i];}
    sort(ar,ar+n);

    for(int i=0;i<n;i++){cerr<<ar[i]<<" ";}
		cerr<<endl;
    cin>>p>>q;
    cerr<<p<<" - "<<q<<endl;
		if(p<ar[0])
		{
			cerr<<"Case 0 - ";
			mx=abs(ar[0]-p);
			in=p;
			cerr<<"mx = "<<mx<<" ... in = "<<in<<endl;
		}	
		if(q>ar[n-1])
		{
			cerr<<"Case 0 - ";
			if(mx<abs(ar[n-1]-q))
				{
					mx=abs(ar[n-1]-q);
					in=q;
			cerr<<"mx = "<<mx<<" ... in = "<<in<<endl;
				}	
		}



		int i=0;
		while(1)
		{
			t2=-1;t1=-1;
			if((p<=ar[i])&&(q>=ar[i+1]))
			{
				m=(ar[i]+ar[i+1])/2;
				t1=min(abs(ar[i]-m),abs(ar[i+1]-m));
				if(m<q)
				{m++;
				t2=min(abs(ar[i]-m),abs(ar[i+1]-m));}
				if(t1>t2)
				{
					if(t1>mx){mx=t1;in=(m<q)?m-1:m;}
					else  if(t2>mx){mx=t2;in=m;}
				}
				cerr<<"Case 1 "<<m-1<<" : "<<t1<<" || "<<m<<" : "<<t2<<" - ";
			cerr<<"mx = "<<mx<<" ... in = "<<in<<endl;

			}
			else if((p>ar[i])&&(p<ar[i+1])&&(q>=ar[i+1]))
			{
				m=(ar[i]+ar[i+1])/2;
				if(p<=m)								
				{
					t1=min(abs(ar[i]-m),abs(ar[i+1]-m));
					if(m<q)
					{m++;
					t2=min(abs(ar[i]-m),abs(ar[i+1]-m));}
					if(t1>t2)
					{
						if(t1>mx){mx=t1;in=(m<q)?m-1:m;}
						if(t2>mx){mx=t2;in=m;}
					}
				}
				else
				{
					t1=min(abs(ar[i]-p),abs(ar[i+1]-p));
					if(t1>t2)
					{
						if(t1>mx){mx=t1;in=p;}
					}
				}
				cerr<<"Case 2 "<<m-1<<" : "<<t1<<" || "<<m<<" : "<<t2<<" - ";
			cerr<<"mx = "<<mx<<" ... in = "<<in<<endl;

			}
			else if((p<=ar[i])&&(q<ar[i+1])&&(q>=ar[i]))
			{
				m=(ar[i]+ar[i+1])/2;
				if(q>=m)								
				{
					t1=min(abs(ar[i]-m),abs(ar[i+1]-m));
					if(m<q)
					{m++;
					t2=min(abs(ar[i]-m),abs(ar[i+1]-m));}
					if(t1>t2)
					{
						if(t1>mx){mx=t1;in=(m<q)?m-1:m;}
						if(t2>mx){mx=t2;in=m;}
					}
				}
				else
				{
					t1=min(abs(ar[i]-q),abs(ar[i+1]-q));
					if(t1>mx){mx=t1;in=q;}
				}
				cerr<<"Case 3 "<<m-1<<" : "<<t1<<" || "<<m<<" : "<<t2<<" - ";
			cerr<<"mx = "<<mx<<" ... in = "<<in<<endl;

			}
			else if((p>=ar[i])&&(p<=ar[i+1]&&(q>=ar[i])&&(q<=ar[i+1])))
			{
				m=(ar[i]+ar[i+1])/2;
				if(m>=p&&m<=q)								
				{
					t1=min(abs(ar[i]-m),abs(ar[i+1]-m));
					if(m<q)
					{m++;
					t2=min(abs(ar[i]-m),abs(ar[i+1]-m));}
					if(t1>t2)
					{
						if(t1>mx){mx=t1;in=(m<q)?m-1:m;}
						if(t2>mx){mx=t2;in=m;}
					}
				}
				else
				{
					t1=min(abs(ar[i]-p),abs(ar[i+1]-p));
					t2=min(abs(ar[i]-q),abs(ar[i+1]-q));					
					if(t1>mx){mx=t1;in=p;}
					if(t2>mx){mx=t2;in=q;}
				}
			cerr<<"Case 4 "<<m-1<<" : "<<t1<<" || "<<m<<" : "<<t2<<" - ";
			cerr<<"mx = "<<mx<<" ... in = "<<in<<endl;

			}
			i++;
			if(i==n-1){cout<<in<<endl<<endl;return 0;}
		}	

    return 0;
}

