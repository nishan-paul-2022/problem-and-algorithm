#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    vector< pair<ll,ll> > v;
    pair<ll,ll> p;
    for(ll i=0; i<n; i++){
        if(i==0)
            p=make_pair( abs(a[i]-a[i+1]),abs(a[i]-a[n-1]) );
        else if(i==n-1)
            p=make_pair( abs(a[i]-a[i-1]),abs(a[i]-a[0]) );
        else
            p=make_pair( min( abs(a[i]-a[i+1]),abs(a[i]-a[i-1]) ),max( abs(a[i]-a[n-1]),abs(a[i]-a[0]) ) );
        v.push_back(p);
    }
    for(ll i=0; i<n; i++){
        cout<<v[i].first<<' '<<v[i].second<<lne;
    }
    return 0;
}
