#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
class data
{
    public:
        ll idx;
        ll pwr;
        ll coin;
};
bool srtp(data x,data y){
    return x.pwr<y.pwr;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<data> v(n);
    vector<ll> str(n);
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        v[i].idx=i;
        v[i].pwr=tem;
    }
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        v[i].coin=tem;
    }
    sort(v.begin(),v.end(),srtp);
    multiset<ll> m;
    ll bck=0;
    for(ll i=0; i<n; i++){
        str[ v[i].idx ] = bck + v[i].coin;
        bck += v[i].coin;
        m.insert(v[i].coin);
        if(m.size()>k){
            bck -= *(m.begin());
            m.erase(m.begin());
        }
    }
    for(ll i=0; i<n; i++){
        cout<<str[i]<<spc;
    }
    return 0;
}
