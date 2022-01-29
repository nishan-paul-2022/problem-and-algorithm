#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,m,cnt=0;
    cin>>n>>m;
    ll a[n];
    queue<ll> q;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<m; i++){
        ll tem;
        cin>>tem;
        q.push(tem);
    }
    ll i=0;
    while(q.empty()==false && i<n){
        ll val=q.front();
        while(a[i]>val && i<n) i++;
        if(i==n){
            break;
        }
        if(a[i]<=val) cnt++;
        i++;
        q.pop();
    }
    cout<<cnt;
    return 0;
}
