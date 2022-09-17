#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll a,b,mx,mn;
    cin>>a>>b;
    cout<<(a+b-1)<<lne;
    for(ll i=1; i<=b; i++)
        cout<<1<<' '<<i<<lne;
    for(ll i=2; i<=a; i++)
        cout<<i<<' '<<b<<lne;
    return 0;
}
