#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,mx=0;
    cin>>n;
    map<ll,ll> m;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        m[tem]++;
        mx=max(mx,m[tem]);
    }
    cout<<mx;
    return 0;
}
