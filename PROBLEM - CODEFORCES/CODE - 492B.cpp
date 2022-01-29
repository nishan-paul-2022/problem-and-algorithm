#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,l,mx=0;
    cin>>n>>l;
    ll a[n+2];
    for(ll i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=0;
    a[n+1]=l;
    if(a[1]!=0) a[0]=3*a[1];
    if(a[n]!=l) a[n+1]=2*(a[n]-l)+a[n];
//    for(auto i:a)
//        cout<<i<<spc;
    for(ll i=0; i<=n; i++)
        mx = max(mx,abs(a[i+1]-a[i]));
    double d = (double) mx/2;
    printf("%.10lf",d);
    return 0;
}
