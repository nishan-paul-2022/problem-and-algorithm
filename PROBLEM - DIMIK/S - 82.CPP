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
    ll n=20;
    vector<vll> v(1+n);
    for(ll i=1; i<=n; i++){
        v[i].push_back(1);
        for(ll j=1; j<=i-2; j++)
            v[i].push_back(v[i-1][j-1]+v[i-1][j]);
        if(i>1) v[i].push_back(1);
    }
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll val;
        cin>>val;
        for(ll j=1; j<=val; j++){
            vll tem=v[j];
            ll sze=tem.size();
            for(ll k=0; k<sze; k++){
                cout<<tem[k];
                if(k<sze-1) cout<<spc;
            }
            cout<<lne;
        }
    }
//    fileclose
    return 0;
}

