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
    vector< vector<ll> > v(100001);
    for(ll i=1; i<=100000; i++){
        for(ll j=i; j<=100000; j+=i)
            v[j].push_back(i);
    }
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n;
        cin>>n;
        vector<ll> x=v[n];
        ll sze=x.size();
        cout<<"Case "<<i<<":";
        for(ll j=0; j<sze; j++)
            cout<<spc<<x[j];
        if(i<tst) cout<<lne;
    }
//    fileclose
    return 0;
}
