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
    ll n=40000000;
    vector<ll> v(n+1,0);
    for(ll i=1; i<=n; i++)
        for(ll j=2*i; j<=n; j+=i)
            v[j]+=i;
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n;
        cin>>n;
        if(n!=v[n])
            cout<<"NO, "<<n<<" is not a perfect number"<<lne;
        else if(n==v[n])
            cout<<"YES, "<<n<<" is a perfect number"<<lne;
    }
//    fileclose
    return 0;
}
