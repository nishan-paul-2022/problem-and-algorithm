#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n, cnt=0, pwr=0;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    cnt+=a[0];
    for(ll i=1; i<n; i++){
        ll tem=abs(a[i]-a[i-1]);
        if(a[i-1]<a[i]){
            if(pwr>=tem)
                pwr-=tem;
            else if(pwr<tem){
                cnt+=tem-pwr;
                pwr=0;
            }
        }
        else if(a[i-1]>a[i])
            pwr+=a[i-1]-a[i];
    }
    cout<<cnt;
    return 0;
}
