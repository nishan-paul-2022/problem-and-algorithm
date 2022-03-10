///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,i,tem;
    scanf("%lld %lld",&n,&m);
    ll a[n+1], mn=n+1;
    for(i=0; i<n+1; i++)
        a[i]=0;
    for(i=0; i<m; i++)
    {
        scanf("%lld",&tem);
        a[tem]++;
    }
    for(i=1; i<n+1; i++)
    {
        mn=min(mn,a[i]);
    }
    printf("%lld\n",mn);
    return 0;
}
