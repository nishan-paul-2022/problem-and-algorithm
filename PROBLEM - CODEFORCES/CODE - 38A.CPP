///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n, sum=0;
    cin>>n;
    ll arr[n-1];
    for(ll i=0; i<n-1; i++)
        cin>>arr[i];
    ll a,b;
    cin>>a>>b;
    if(a!=b)
        for(ll i=a-1; i<b-1; i++)
            sum+=arr[i];
    cout<<sum;
    return 0;
}