#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<ll> v(1001,0), fck, str;
    ll n,cnt=0;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll tem;
        cin>>tem;
        fck.push_back(tem);
        v[tem]++;
        if(v[tem]==1) cnt++;
    }
    cout<<cnt<<'\n';
    for(ll i=fck.size()-1; i>=0; i--)
        if(v[ fck[i] ]>0){
            str.push_back(fck[i]);
            v[ fck[i] ]=0;
        }
    for(ll i=str.size()-1; i>=0; i--)
        cout<<str[i]<<' ';
    return 0;
}
