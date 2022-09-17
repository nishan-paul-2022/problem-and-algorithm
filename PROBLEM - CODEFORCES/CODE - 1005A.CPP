#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,cnt=0;
    vector<ll> v;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==1) cnt++;
    }
    for(ll i=1; i<n; i++){
        if(a[i]==1)
            v.push_back(a[i-1]);
    }
    v.push_back(a[n-1]);
    cout<<cnt<<lne;
    for(auto i:v)
        cout<<i<<spc;
    return 0;
}
