#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, sum = 0;
    cin>>n;

    map<string,ll> m;
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;

    for(int i=0; i<n; i++) {
        string name;
        cin>>name;
        sum += m[name]; 
    }
    cout<<sum;

    return 0;
}
