#include<bits/stdc++.h>
using namespace std ;
int main()
{
    long long int n,m,i,l,t ;
    cin>>n>>m ;
    long long int a[m] ;
    i=0 ;
    while(i<m)
    {
        cin>>a[i] ;
        i++ ;
    }
    sort(a+0,a+m) ;
    l=a[n-1]-a[0] ;
    i=0 ;
    while(i<=(m-n))
    {
        t=a[i+n-1]-a[i] ;
        l=t<=l? t:l ;
        i++ ;
    }
    cout<<l ;
    return 0 ;
}
