///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n, ans=0;
        cin>>n;
        map<ll,ll> m;
        for(ll j=0; j<n; j++){
            ll tem;
            cin>>tem;
            m[tem]++;
        }
        map<ll,ll>::iterator it, jt=m.end();
        for(it=m.begin(); it!=jt; it++){
            ll team=1+it->first, person=it->second;
            if(team==0)
                ans+=person;
            else if(team>=person)
                ans+=team;
            else if(team<person){
                ll x=person/team;
                if(person%team!=0)
                    x++;
                ans+=(x*team);
            }
        }
        cout<<"Case "<<i<<": "<<ans<<lne;
//        if(i<tst)
//            cout<<lne;
    }
    return 0;
}

