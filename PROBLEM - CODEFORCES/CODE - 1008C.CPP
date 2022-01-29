#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,i,j,cnt=-1;
    cin>>n;
    ll a[n];
    queue<ll> q;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    for(ll i=0; i<n; i++)
        q.push(a[i]);
    for(i=0; i<n && q.empty()==false; i++){
        cnt++;
        q.pop();
        while( a[i]==q.front() )
            q.pop();

    }
    cout<<cnt;
    return 0;
}
