#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n,a,b,dis=0,sum,res=0;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll sze=s.length();
    vector<ll> v;
    for(ll i=0; i<sze; i++){
        if(s[i]=='.')
            dis++;
        else{
            v.push_back(dis);
            dis=0;
        }
    }
    if(dis!=0) v.push_back(dis);
    sze=v.size();
    for(ll i=0; i<sze; i++){
        ll x,y;
        x=v[i]/2;
        y=x+v[i]%2;
        if(a>b) swap(a,b);
        if(a>0) res=res+min(x,a);
        if(b>0) res=res+min(y,b);
        a=a-min(x,a);
        b=b-min(y,b);
    }
    cout<<res<<lne;
    return 0;
}
