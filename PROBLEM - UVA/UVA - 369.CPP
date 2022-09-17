///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
ll Combi(ll n,ll r)
{
    ll ans=1;
    for(ll i=0; i<r; i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
int main()
{
    inout
    //fileopen
    while(1){
        ll n,m;
        cin>>n>>m;
        if(n==0 && m==0) break;
        ll ans=Combi(n,min(m,n-m));
        cout<<n<<" things taken "<<m<<" at a time is "<<ans<<" exactly."<<lne;
    }
    //fileclose
    return 0;
}
