#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll r,g,b,tw=2,mx=0;
    cin>>r>>g>>b;
    ll m=min( tw, min( r,min(g,b) ) ) ;
    for(ll i=0; i<=m; i++){
        ll tem=i+(r-i)/3+(g-i)/3+(b-i)/3;
        mx=max(mx,tem);
    }
    cout<<mx;
    return 0;
}
