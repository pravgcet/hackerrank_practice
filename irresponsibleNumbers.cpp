#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define loop(a,b) for(int i=a;i<b;i++)

using namespace std;

typedef long long int lli;
lli mod,mi,fv;
lli q,w,e,r;

char buf[20000000],buf2[20000000];

lli fon[10000000],pwr[10000000];

lli largemod(lli n)
{
	int ix,l,ls,s,l1,l2;
	char sml[16];
	lli ln,fln=0;
		ix=0;
		l=strlen(buf);
		if(l>15)
		{
			s=0;
			loop(ix,ix+15)
			{
				sml[s++]=buf[i];
			}
			sml[15]='\0';
			ln=(atoll(sml));
	//		cerr<<ln<<endl;
			ln=ln%mod;
		}
		else
		{
			ln=atoll(buf);
		}
		ix+=15;
	//	cerr<<ln<<endl;
		while(ix<l)
		{	
			s=0;
			loop(ix,(ix+7<l?ix+7:l))
			{
				sml[s++]=buf[i];
			}
			sml[s]='\0';
			l1=atoll(sml);
			ln=(ln*pow(10,s));
	//		cerr<<ln<<" + "<<l1<<" = ";
			ln=(ln+l1);
	//		cerr<<ln<<endl<<endl;
			ln=ln%mod;
	//		cerr<<ln<<endl;
			ix=ix+7;
		}
	lli tln; 	
	fln=ln;
	tln=ln;
	sprintf(sml,"%lld",fln);
	l=strlen(sml);
	cerr<<"n is "<<n<<" "<<fln<<endl;
	n--;
	while(n--)
	{
		tln=tln*pow(10,l)+fln;
		tln=tln%mod;
	}
	return tln;
}

lli power(lli a, lli y)
{
lli f;
	
	if(y==1) 
	{
		return a;
	}

	if(y%2==1) 
	{ 
		f=power(a,y/2);
		return (((f*f)%mod)*a)%mod;
	}
		f=power(a,y/2);
		return (f*f)%mod;
}


lli modInv(lli a, lli m)
{
	return power(a,m-2);
}

lli FofN(lli ii,lli n)
{
	return (((pwr[ii+1]*q)%mod)-e)%mod;
}

lli safe(int n)
{
	lli l = strlen(buf2),v,num;
	lli res=1;
//	cerr<<"In safe "<<buf2<<endl;
		for(lli j=0;j<l;j++)
		{
			v=buf2[j];
			num=v-48;
			v=(num*fon[l-j-1]);
// 	cerr<<num<<" * "<<fon[l-j-1]<<" = "<<v<<endl;

//	cout<<v<<endl;
			res=(res+v%mod)%mod;
		}
	return res;
}


lli unsafe(int n)
{
	cerr<<"Unsafe"<<endl;
	lli l = strlen(buf2),v,num;
	lli res=0;
	for(lli j=0;j<fv;j++)
		{
			v=buf2[j];
			num=v-48;
			v=(num*fon[l-j-1]);
			res=(res+(v%mod))%mod;
		}
		cerr<<"Res is "<<res<<" fv "<<fv<<endl;
		if(buf2[fv]-48!=9)
		{
		v=(5*fon[l-fv-1]);
		res=(res+v%mod)%mod;
		}
		v=0;
	for(lli j=fv+1;j<l;j++)
		{
			if((buf2[j]-48)!=9){v=1;break;}
		}
	if(v==0){res+=1;}

	return res%mod;
}

int main()
{
	int l,sf=1;
	lli v1,v2 , n;
	string s;
	scanf("%s %d",buf,&n);
	strcpy(buf2,buf);
	l=strlen(buf);
	memset(fon,-1,sizeof(fon));
	mod=1e9+7;
//	cerr<<"Calculating modInv"<<endl;
	mi=modInv(4,mod);
//	cerr<<"Done"<<endl;
	pwr[0]=1;
//	cerr<<"Calculating power"<<endl;
	loop(1,l+1)
	{
		pwr[i]=(pwr[i-1]*5)%mod;
	}
//	cerr<<"Done"<<endl;
//	cerr<<"Calculating f(n)"<<endl;
q=modInv(16,mod);
w=power(5,n)-1;
q=(q*w)%mod;
e=(n*mi)%mod;
	loop(0,l)
	{
		fon[i]=FofN(i,n);
	}
//	cerr<<"Done"<<endl;
	loop(0,l)
	{
		if(buf[i]>=53){fv=i;sf=0;break;}
	}
	
	if(sf==1)
	{
//		cerr<<"Calculating large mod"<<endl;
		v1=largemod(n)+1;
//		cerr<<"Done"<<endl;
//		cerr<<"Calculating safe"<<endl;
		v2=safe(n);
//		cerr<<"Done"<<endl;
		cerr<<v1<<" - "<<v2<<endl;
		cout<<((v1-v2)>-1?(v1-v2):((v1-v2)+mod))<<endl;
	}
	else
	{
		v1=largemod(n)+1;
		v2=unsafe(n);
		cerr<<v1<<" - "<<v2<<endl;
		cout<<((v1-v2)>-1?(v1-v2):((v1-v2)+mod))<<endl;
	}
return 0;
}
