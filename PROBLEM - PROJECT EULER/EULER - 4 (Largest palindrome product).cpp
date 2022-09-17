///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
ll pwr(ll a,ll b)
{
    if(b==0)
        return 1;
    ll tem = pwr(a,b/2);
    ll val = tem*tem;
    if(b%2)
        val*=a;
    return val;
}
int main()
{
    ll n,x,y;
    cin>>n;
    x=pwr(10,n);
    y=pwr(10,n+1)-1;
    cout<<x<<spc<<y<<lne;
    ll x1=x/11, y1=y/11;
    if(x%11) x1++;
    x1*=11, y1*=11;
    cout<<x1<<spc<<y1<<lne;
    vector<ll> v;
    for(ll i=y1; i>=x1; i-=11){
        for(ll j=y; j>=x; j--){
            ll val=i*j;
            string s,t;
            s=t=to_string(val);
            reverse(t.begin(),t.end());
            if(s==t)
                v.push_back(val);
        }
    }
    sort(v.begin(),v.end(),greater<ll>());
    for(ll i=0; i<v.size(); i++)
        cout<<v[i]<<spc;
    return 0;
}

