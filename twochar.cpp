//https://www.hackerrank.com/contests/world-codesprint-7/challenges/two-characters
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int > vec,tec;
vector<int > :: iterator it,it2;

int check(int w)
{
    int a;
    if(w==1)
        {
         it=vec.begin();
         a=*it;it++;
         for(;it!=vec.end();it++)
             {
                if(*it==a+1){return 1;}
             		a=*it;
             }
    }
    else
       {
          it=tec.begin();
         a=*it;it++;
         for(;it!=tec.end();it++)
             {
                if(*it==a+1){return 1;}
								a=*it;
             }
        }
    return 0;
}
    
int verify()
{/*
cerr<<"Verifying===================="<<endl;
     for(it=vec.begin();it!=vec.end();it++)
       {
       	cerr<<*it<<" ";
				}
		cerr<<endl;
      for(it=tec.begin();it!=tec.end();it++)
        {
         	cerr<<*it<<" ";
				}
				cerr<<endl;
*/
int s=vec.size(),t=tec.size();
vector<int > hur;
for(int i=0;i<s;i++)
{
	hur.push_back(vec[i]);
}
for(int i=0;i<t;i++)
{
	hur.push_back(tec[i]);
}
sort(hur.begin(),hur.end());
int j,k,turn;
if(hur[0]==vec[0])
{
	j=1;k=0;turn=2;
	for(int i=1;i<s+t;i++)
	{
		if(turn==1)
		{
			if(hur[i]==vec[j]){j++;turn=2;}
			else{return -1;}
		}
		else
		{
			if(hur[i]==tec[k]){k++;turn=1;}
			else{return -1;}
		}
	}
}
else
{
	j=0;k=1;turn=1;
	for(int i=1;i<s+t;i++)
	{
		if(turn==1)
		{
			if(hur[i]==vec[j]){j++;turn=2;}
			else{return -1;}
		}
		else
		{
			if(hur[i]==tec[k]){k++;turn=1;}
			else{return -1;}
		}
	}
}
return t+s;
}

int main(){
    int n,al[26],mx=-2,a,b,c,z;
    memset(al,0,sizeof(al));
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
    {
     al[s[i]-97]=1;
    }    

    for(int i=0;i<26;i++)
    {
     if(al[i]==1)
      {
        vec.clear();
        for(int j=0;j<n;j++)
          {
            if((s[j]-97)==i)
              {
               vec.push_back(j);
              }
          }
    b=check(1);
    if(b==0)
    {
	//	cout<<(char)(i+97)<<endl;
    z=i+1;
    while(1)
    {
     for(int k=z;k<26;k++)
       {
        if(al[k]==1)
        {
        tec.clear();
        for(int j=0;j<n;j++)
          {
            if((s[j]-97)==k)
              {
               tec.push_back(j);
              }
          }
           b=check(2);        
           if(b==0)
           {
		//				cout<<(char)(k+97)<<" - "<<endl;       
            c=verify(); 
            if(c>mx){mx=c;}
           }
           else
           {
            al[k]=0;   
           }
        }
        }
    z++; 
    if(z>25){break;}
    }
  }
  }
 }
 if(mx<2)
 {
 	cout<<0;
 	return 0;
 }
  cout<<mx<<endl;  
 return 0;
}

