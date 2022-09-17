#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    if(a[n-1]==0)
        cout<<"UP";
    else if(a[n-1]==15)
        cout<<"DOWN";
    else if(n==1)
        cout<<"-1";
    else if(a[n-2]>a[n-1])
        cout<<"DOWN";
    else if(a[n-2]<a[n-1])
        cout<<"UP";
    return 0;
}
