#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n,c1=0,c2=0;
    cin>>n;
    ll a[n], b[n];
    for(ll i=0; i<n; i++)
        cin>>a[i]>>b[i];
    for(ll i=0; i<n; i++)
    {
        if(a[i]!=b[i]) c1=1;
        if(i!=0) if(a[i-1]<a[i]) c2=1;
    }
    if(c1==0 && c2==0)
        cout<<"maybe";
    else if(c1==1)
        cout<<"rated";
    else if(c2==1)
        cout<<"unrated";
    return 0;
}
