#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,m1,fst=0,scd=0;
    cin>>n;
    map<ll,ll> m;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        m[tem]=i+1;
    }
    cin>>m1;
    for(ll i=0; i<m1; i++){
        ll tem;
        cin>>tem;
        fst+=m[tem];
        scd+=n-m[tem]+1;
    }
    cout<<fst<<spc<<scd;
    return 0;
}
