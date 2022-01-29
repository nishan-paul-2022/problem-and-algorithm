#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,idx,cnt=0;
    cin>>n>>idx;
    ll a[n+1];
    for(ll i=1; i<=n; i++)
        cin>>a[i];
    if(a[idx]==1) cnt++;
    for(ll i=1; i<idx; i++)
        if(idx+i>n && a[idx-i]==1) cnt++;
        else if(idx-i<1 && a[idx+i]==1) cnt++;
        else if(a[idx+i]==1 && a[idx-i]==1) cnt+=2;
    for(ll i=2*idx; i<=n; i++)
        if(a[i]==1) cnt++;
    cout<<cnt;
    return 0;
}
