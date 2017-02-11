#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
int n,ar[50],b;
    long long int a=0,z=0;
    cin>>n;
    for(int i=0;i<n;i++){cin>>ar[i];}
    for(int i=0;i<n;i++)
        {
        cin>>b;
        a+=(b*ar[i]);
        z+=b;
    }
    cout<<fixed<<setprecision(1)<<(a/(double)z);
    
    return 0;
}

