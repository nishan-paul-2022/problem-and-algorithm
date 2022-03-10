#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k,val;
    cin>>n>>k;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    if(k==0)
        val=a[0]-1;
    else
    {
        if(a[k-1]==a[k])
            val=-1;
        else
            val=a[k-1];
    }
    if(val<1)
        cout<<-1;
    else
        cout<<val;
    return 0;
}
