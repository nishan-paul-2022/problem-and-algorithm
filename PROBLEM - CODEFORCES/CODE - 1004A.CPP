#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,d;
    cin>>n>>d;
    ll a[n];
    set<ll> v;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<n; i++){
        ll x,y;
        x=a[i]-d;
        y=a[i]+d;
        if(i!=0 && abs(x-a[i-1]) >= d)
            v.insert(x);
        if(i!=n-1 && abs(y-a[i+1]) >= d)
            v.insert(y);
    }
    cout<<v.size()+2;
    return 0;
}

