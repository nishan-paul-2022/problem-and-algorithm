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
ll mod(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll a = mod(x,y/2,m);
    ll b = (a*a)%m;
    if(y%2) b = (b*(x%m))%m;
    return b;
}
int main()
{
    inout
    //fileopen
    ll x,y,m;
    while(cin>>x>>y>>m){
        cout<<mod(x,y,m)<<lne;
    }
    //fileclose
    return 0;
}

