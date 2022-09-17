///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll tst;
    cin>>tst;
    while(tst--){
        ll n, ans=0;
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++)
            cin>>arr[i];
        sort(arr,arr+n,greater<ll>());
        for(ll i=2; i<n; i+=3)
            ans+=arr[i];
        cout<<ans<<lne;
    }
    return 0;
}

