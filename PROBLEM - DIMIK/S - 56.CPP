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
        ll x,y,z;
        cin>>x>>y>>z;
        ll s=(x+y+z)/2;
        double d=sqrt( s*(s-x)*(s-y)*(s-z) );
        cout<<fixed<<setprecision(3)<<"Area = "<<d<<lne;
    }
//    fileclose
    return 0;
}

