///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    ll val=a[n-1]-a[0]+1;
    cout<<val-n;
    return 0;
}

