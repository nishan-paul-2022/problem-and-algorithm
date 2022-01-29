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
    ll a[16]={1};
    for(ll i=1; i<=15; i++)
        a[i]=i*a[i-1];
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n;
        cin>>n;
        cout<<a[n]<<lne;
    }
//    fileclose
    return 0;
}
