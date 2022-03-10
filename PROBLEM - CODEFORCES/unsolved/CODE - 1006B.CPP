#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,k,sum=0;
    cin>>n>>k;
    ll a[n];
    vector<ll> v;
    map<ll,ll> m;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(m[ a[i] ]==0) m[ a[i] ] = i+1;
    }
    sort(a,a+n,greater_equal<ll>());
    for(ll i=0; i<k; i++){
        sum+=a[i];
        v.push_back(m[ a[i] ]);
    }
    v.push_back(n);
    sort(v.begin(),v.end());
    cout<<sum<<lne;
    if(k==1)
        cout<<n;
    else{
        ll lgt=v.size();
        cout<<v[0]<<spc;
        for(ll i=1; i<=lgt-3; i++)
            cout<<(v[i]-v[i-1])<<spc;
        cout<<v[lgt-1]-v[lgt-3]<<spc;
    }
    return 0;
}
