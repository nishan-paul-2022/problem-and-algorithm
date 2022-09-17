#include<bits/stdc++.h>
#define ll long long int
#define line '\n'
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        v.push_back(tem);
    }
    sort(v.begin(),v.end());
    if(n%2==0)
        cout<<v[n/2-1];
    else
        cout<<v[n/2];
    return 0;
}

