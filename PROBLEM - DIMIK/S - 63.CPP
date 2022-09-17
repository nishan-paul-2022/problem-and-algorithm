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
vector<bool> f(ll n)
{
    ll r=1+sqrt(n);
    vector<bool> p(n+1,true);
    p[0]=p[1]=false;
    for(ll i=4; i<=n; i+=2)
        p[i]=false;
    for(ll i=3; i<=r; i+=2)
        if(p[i]==true)
            for(ll j=i*i; j<=n; j+=2*i)
                p[j]=false;
    return p;
}
int main()
{
//    inout
//    fileopen
    ll n=100000;
    vector<bool> p=f(n);
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll a,b,cnt=0;
        cin>>a>>b;
        for(ll j=a; j<=b; j++){
            if(p[j]==true)
                cnt++;
        }
        cout<<cnt<<lne;
    }
//    fileclose
    return 0;
}
