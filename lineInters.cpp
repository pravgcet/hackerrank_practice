#include <iostream>

using namespace std;

struct Points
{
int x,y;
};


int orientation(Points p,Points q, Points r)
{
int v;

v=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);

if(v==0) return 0;

return (v>0) ? 1:2 ;
}

bool doInters(Points p1,Points q1,Points p2,Points q2)
{
int o1,o2,o3,o4;
o1=orientation(p1,q1,p2);
o2=orientation(p1,q1,q2);
o3=orientation(p2,q2,p1);
o4=orientation(p2,q2,q1);

if(o1!=o2&&o3!=o4){return true;}

if(o1==0&&orientaion(p1,p2,q1)){return true;}
if(o1==0&&orientaion(p1,q2,q1)){return true;}
if(o1==0&&orientaion(p2,p1,q2)){return true;}
if(o1==0&&orientaion(p2,q1,q2)){return true;}

}

int main()
{
	int n;
	Points p1,q1,p2,q2;
	cin>>p1.x>>p1.y>>q1.x>>q1.y>>p2.x>>p2.y>>q2.x>>q2.y;
	cout<<orientation(p1,q1,p2)<<endl;
	return 0;
}
