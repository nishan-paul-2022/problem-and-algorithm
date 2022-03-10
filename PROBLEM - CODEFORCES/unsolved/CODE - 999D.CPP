#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,m,num;
    cin>>n>>m;
    num=n/m;
    vector<ll> v[m];
    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
        v[a[i]%m].push_back(a[i]);
    }

    return 0;
}
