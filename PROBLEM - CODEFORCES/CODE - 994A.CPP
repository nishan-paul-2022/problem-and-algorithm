#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> v(10,0), v1;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        v1.push_back(tem);
        v[tem]++;
    }
    for(ll i=0; i<m; i++){
        ll tem;
        cin>>tem;
        v[tem]++;
    }
    for(ll i=0; i<n; i++){
        if(v[v1[i]]==2)
            cout<<v1[i]<<' ';
    }
    return 0;
}

