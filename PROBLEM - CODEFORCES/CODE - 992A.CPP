#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n, sum=0;
    cin>>n;
    map<ll,ll> m;
    map<ll,ll>::iterator it;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        if(tem!=0)
            m[tem]++;
    }
    sum=m.size();
    cout<<sum<<lne;
    return 0;
}
