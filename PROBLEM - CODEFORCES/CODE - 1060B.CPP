///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
#define lne '\n'
#define spc ' '
using namespace std;
ll pwr(ll base,ll n)
{
    if(n==0)
        return 1;
    ll v=pwr(base,n/2);
    ll w=v*v;
    if(n%2)
        w*=base;
    return w;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll m,n,i=0,ans=0;
    cin>>m;
    n=m;
    while(n>=10){
        n/=10;
        i++;
    }
    m-=pwr(10,i)-1;
    while(m){
        ans+=(m%10);
        m/=10;
    }
    cout<<ans+9*i;
    return 0;
}
