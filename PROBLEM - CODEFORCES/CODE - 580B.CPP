#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,d;
    cin>>n>>d;
    vector< pair<int,int> > v;
    for(ll i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    ll j=0, mx=0, ans=0;
    for(ll i=0; i<n; i++){
        ll val=abs(v[i].first- v[j].first);
        if(val<d){
            ans+=v[i].second;
            mx=max(mx,ans);
        }
        else if(val>=d){
            ans-=v[j].second;
            j++;
            i--;
        }
    }
    cout<<mx;
    return 0;
}
