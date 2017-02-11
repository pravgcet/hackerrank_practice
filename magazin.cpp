#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
map<string,int > magazine;
vector<string > ransom(30000);
    int m;
    int n;


bool ransom_note() {
    int y=1;
for(int i=0;i<n;i++)
    {
    if(magazine.find(ransom[i])==magazine.end()){return 0;}
    else if(magazine[ransom[i]]<1) 
        {
        {return 0;}
    }
    else
        {
        magazine[ransom[i]]=magazine[ransom[i]]-1;
    }
}
    return y;
}

int main(){
    cin >> m >> n;
    string s;
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >>s;
       if(magazine.find(s)==magazine.end()){magazine[s]=1;}
        else
            {
            magazine[s]=magazine[s]+1;
        }
    }
    cerr<<"All set"<<endl;
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    cerr<<"All inserted"<<endl;
    if(ransom_note())
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

