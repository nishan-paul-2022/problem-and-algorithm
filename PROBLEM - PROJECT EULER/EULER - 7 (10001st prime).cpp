///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll lmt=1+sqrt(n);
    vector<bool> v(n+1,true);
    vector<ll> prm;
    v.push_back(2);
    for(ll i=3; i<=lmt; i+=2){
        if(v[i]==true){
            for(ll j=i*i; j<=n; j+=2*i){
                v[j]=false;
            }
        }
    }
//    cout<<2<<spc;
    prm.push_back(2);
    for(ll i=3; i<=n; i+=2){
        if(v[i]==true){
//            cout<<i<<spc;
            prm.push_back(i);
        }
    }
    cout<<prm[10000]<<spc;
    return 0;
}
