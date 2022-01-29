#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;
    }
    string s="";
    for(ll i=0; i<n; i++)
        if(i%2==0) s+="0";
        else s+="1";
    cout<<s;
    return 0;
}
