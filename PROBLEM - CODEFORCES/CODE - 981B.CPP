#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m,idx,val,sum=0;
    map<ll,ll> v;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>idx>>val;
        v[idx]=val;
    }
    cin>>m;
    for(ll i=0; i<m; i++)
    {
        cin>>idx>>val;
        v[idx]=max(v[idx],val);
    }
    map<ll,ll>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
        sum+=it->second;
    cout<<sum;
    return 0;
}

