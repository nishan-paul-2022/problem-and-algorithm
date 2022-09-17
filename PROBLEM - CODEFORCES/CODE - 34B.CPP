///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,m, ans=0;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(ll i=0; i<m; i++)
        if(arr[i]<0)
            ans+=arr[i];
    cout<<abs(ans);
    return 0;
}

