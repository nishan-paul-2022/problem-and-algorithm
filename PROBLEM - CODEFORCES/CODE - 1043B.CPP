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
    ll n, x=1;
    cin>>n;
    ll a[n+1]={0}, b[n];
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        b[i-1]=a[i]-a[i-1];
    }
    vector<ll> v;
    for(ll i=0; i<n; i++,x++){
        ll k=0, j;
        for(j=i+1; j<n && b[k%x]==b[j]; j++,k++);
        if(j==n) v.push_back(i+1);
    }
    ll sze=v.size();
    cout<<sze<<lne;
    for(ll i=0; i<sze; i++)
        cout<<v[i]<<spc;
//    fileclose
    return 0;
}
