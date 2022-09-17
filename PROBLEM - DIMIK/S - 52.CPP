///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vll vector<long long>
#define vull vector<unsigned long long>
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
    ll n=1000000;
    vector<vll> v(1+n);
    for(ll i=1; i<=n; i++)
        for(ll j=i; j<=n; j+=i)
            v[i].push_back(j);
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll x,n;
        cin>>x>>n;
        if(n<x)
            cout<<"Invalid!"<<lne;
        else{
            ll sze=v[x].size();
            for(ll j=0; j<sze && v[x][j]<=n; j++)
                cout<<v[x][j]<<lne;
        }
    }
//    fileclose
    return 0;
}
