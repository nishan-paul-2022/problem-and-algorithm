///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n=2*1000000-1;
    ll lmt=1+sqrt(n), ans=2;
    vector<bool> v(n+1,true);
    vector<ll> prm;
    for(ll i=3; i<=lmt; i+=2){
        if(v[i]==true){
            for(ll j=i*i; j<=n; j+=2*i)
                v[j]=false;
        }
    }
    for(ll i=3; i<=n; i+=2)
        if(v[i]==true)
            ans+=i;
    cout<<ans<<lne;
    return 0;
}
