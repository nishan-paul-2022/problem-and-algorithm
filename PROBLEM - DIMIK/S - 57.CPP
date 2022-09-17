///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
ll modpwr(ll base,ll pwr,ll mod)
{
    if(pwr==0)
        return 1;
    ll x=modpwr(base,pwr/2,mod);
    ll y=(x*x)%mod;
    if(pwr%2)
        y = (y*(base%mod))%mod;
    return y;
}
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll p,q,c;
        cin>>p>>q>>c;
        cout<<"Result = "<<modpwr(p,q,c)<<lne;
    }
//    fileclose
    return 0;
}

