#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
#define mod 1000000007
using namespace std;
ll pwr(ll a,ll n)
{
    if(n==0) return 1;
    ll val = pwr(a,n/2);
    val = (val*val)%mod;
    if(n%2==1) val = ( val*(a%mod) )%mod;
    return val;
}
int main()
{
    ll x,k;
    cin>>x>>k;
    if(x==0)
        cout<<0;
    else{
        ll one = pwr(2,k);
        ll two = (2*x-1)%mod;
        ll three = (one*two)%mod;
        ll val =  (three+1)%mod;
        cout<<val;
    }
    return 0;
}
