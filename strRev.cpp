#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
string s,a;
getline(cin,s);
stack<string> st;

stringstream ss(s);
while(ss>>a)
{
st.push(a);
}

while(!st.empty())
{
cout<<st.top()<<" ";
st.pop();
}

cout<<endl;


return 0;
}
