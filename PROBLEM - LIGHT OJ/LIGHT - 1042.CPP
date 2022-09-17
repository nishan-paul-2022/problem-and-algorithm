///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
ll cnt(ll n)
{
    ll one=0;
    for(ll i=1; i<=n; i*=2){
        if(n&i)
            one++;
    }
    return one;
}
int main()
{
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n,m;
        cin>>n;
        for(ll i=1; i<=n; i*=2){
            if(n&i){
                m=n+i;
                break;
            }
        }
        ll d=cnt(n)-cnt(m);
        for(ll i=0; i<d; i++){
            m=m+(1<<i);
        }
        cout<<"Case "<<i<<": "<<m<<lne;
    }
    return 0;
}
