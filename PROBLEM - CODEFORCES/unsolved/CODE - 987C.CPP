#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n,t1,t2,sum=300000001;
    cin>>n;
    cin>>t1>>t2;
    vector<ll> idx, v={t1,t2};
    for(ll i=2; i<n; i++)
    {
        ll val;
        cin>>val;
        v.push_back(val);
        if(v[i-2]<v[i-1] && v[i-1]<v[i])
            idx.push_back(i);
    }
    cin>>t1>>t2;
    vector<ll> g={t1,t2};
    ll j=0, sze=idx.size();
    for(ll i=2; i<n; i++)
    {
        ll val;
        cin>>val;
        g.push_back(val);
        if(i==idx[j]){
            sum=min(g[i]+g[i-1]+g[i-2],sum);
            j++;
        }
    }
    if(sum=300000001)
        cout<<-1;
    else
        cout<<sum;
    return 0;
}

