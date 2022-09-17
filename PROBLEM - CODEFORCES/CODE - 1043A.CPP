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
    ll n,mx=1,sum=0,me=0;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }
    sum++;
    for(ll i=0; i<n; i++)
        me+=mx-a[i];
    if(me>=sum)
        cout<<mx;
    else{
        ll tem=sum-me;
        ll x=tem/n;
        if(tem%n) x++;
        cout<<mx+x;
    }
//    fileclose
    return 0;
}
