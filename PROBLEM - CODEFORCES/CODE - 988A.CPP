#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    set<ll> s;
    map<ll,ll> m;
    ll n,k;
    cin>>n>>k;
    for(ll i=0; i<n; i++)
    {
        ll tem;
        cin>>tem;
        m[tem]=i+1;
        s.insert(tem);
    }
    set<ll>::iterator it=s.begin();
    if(s.size()>=k)
    {
        cout<<"YES"<<'\n';
        for(ll i=0; i<k; i++){
            cout<<m[(*it)]<<' ';
            it++;
        }
    }
    else
        cout<<"NO"<<'\n';
    return 0;
}

