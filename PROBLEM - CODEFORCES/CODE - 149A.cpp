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
int main()
{
    inout
    //fileopen
    ll k, val=0, i;
    cin>>k;
    ll a[12];
    for(ll i=0; i<12; i++)
        cin>>a[i];
    sort(a,a+12,greater<ll>());
    for(i=0; i<12 && val<k; i++)
        val+=a[i];
    if(val<k) cout<<-1;
    else cout<<i;
    //fileclose
    return 0;
}

