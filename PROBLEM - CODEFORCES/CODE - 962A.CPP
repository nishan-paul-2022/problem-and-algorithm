#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll i,n,sum=0,sol=0;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2==0) sum=sum/2;
    else sum=1+sum/2;
    for(i=0; sol<sum; i++){
        sol+=a[i];
    }
    cout<<i<<lne;
    return 0;
}
