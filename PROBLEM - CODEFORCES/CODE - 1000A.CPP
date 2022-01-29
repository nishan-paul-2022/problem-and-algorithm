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
    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(a[i]%2==0) a[i]=a[i]-1;
    }
    for(ll i=0; i<n; i++)
        cout<<a[i]<<spc;
    return 0;
}
