#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
bool f(pair<ll,ll> a,pair<ll,ll> b){
    return a.second>b.second;
}
int main()
{
    ll n,m,cnt=0;
    cin>>n>>m;
    vector< pair<ll,ll> > v;
    for(ll i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),f);
    for(ll i=0; i<m && n>0; i++){
        ll tem=min(v[i].first,n);
        cnt+=tem*v[i].second;
        n=n-tem;
    }
    cout<<cnt;
    return 0;
}
