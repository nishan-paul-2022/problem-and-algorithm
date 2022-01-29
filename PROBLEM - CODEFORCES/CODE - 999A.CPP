#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,p;
    vector<ll> v;
    cin>>n>>p;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        if(tem>p) v.push_back(i);
    }
    sort(v.begin(),v.end());
    if(v.size()==0)
        cout<<n;
    else{
        ll val=v[0]+(n-1-v[v.size()-1]);
        cout<<val;
    }
    return 0;
}
