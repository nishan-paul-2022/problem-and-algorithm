#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n,tem;
    cin>>n;
    vector<ll> v(n+1,0);
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        v[tem]=i+1;
    }
    for(ll i=n; i>=1; i--){
        if(i==n){
            for(ll j=0; j<v[i]-1; j++)
                cout<<lne;
            cout<<i<<' ';
            tem=v[i];
        }
        else{
            if(v[i]<tem)
                cout<<i<<' ';
            else if(v[i]>tem){
                for(ll j=0; j<v[i]-tem; j++)
                    cout<<lne;
                cout<<i<<' ';
                tem=v[i];
            }
        }
    }
    return 0;
}
