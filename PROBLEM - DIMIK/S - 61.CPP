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
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n;
        cin>>n;
        vector<ll> x,y,z;
        for(ll j=0; j<n; j++){
            ll tem;
            cin>>tem;
            x.push_back(tem);
        }
        y=z=x;
        sort(y.begin(),y.end(),less<ll>());
        sort(z.begin(),z.end(),greater<ll>());
        if(y==x || z==x)
            cout<<"YES"<<lne;
        else
            cout<<"NO"<<lne;
    }
//    fileclose
    return 0;
}

