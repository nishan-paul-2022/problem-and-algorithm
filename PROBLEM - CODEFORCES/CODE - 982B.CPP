#include<bits/stdc++.h>
#define ll long long
using namespace std;
void pos(char c,set< pair<ll,ll> > &sze,set< pair<ll,ll> > &extr)
{
    if(c=='0'){
        set< pair<ll,ll> >::iterator p=sze.begin();
        cout<<(*p).second<<' ';
        extr.insert( pair<ll,ll>( -(*p).first,-(*p).second ) );
        sze.erase(p);
    }
    else{
        set< pair<ll,ll> >::iterator p=extr.begin();
        cout<<-(*p).second<<' ';
        extr.erase(p);
    }
}
int main()
{
    ll n;
    cin>>n;
    set< pair<ll,ll> > sze, extr;
    for(ll i=0; i<n; i++)
    {
        ll tem;
        cin>>tem;
        sze.insert( pair<ll,ll>(tem,i+1) );
    }
    string s;
    cin>>s;
    for(ll i=0; i<2*n; i++)
        pos(s[i],sze,extr);
    return 0;
}
