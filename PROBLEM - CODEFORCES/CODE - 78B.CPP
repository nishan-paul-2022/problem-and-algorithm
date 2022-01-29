#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n;
    cin>>n;
    string s="ROYGBIV",t="",u="GBIV";
    ll sze=n/7;
    for(ll i=0; i<sze; i++)
        t+=s;
    ll lgt=n%7;
    for(ll i=0; i<lgt; i++)
        t+=u[i%4];
    cout<<t;
    return 0;
}
