#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,mx=1;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<n; i++){
        ll lft=0, rht=0;
        for(ll j=i+1; j<n && a[j-1]>=a[j]; j++)
            lft++;
        for(ll j=i-1; j>=0 && a[j+1]>=a[j]; j--)
            rht++;
        mx=max(mx,lft+rht+1);
    }
    cout<<mx;
    return 0;
}
