#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i ;
    cin>>n ;
    int a[n] ;
    for(i=0; i<n; i++)
        cin>>a[i] ;
    sort(a+0,a+n) ;
    for(i=0; i<n; i++)
        cout<<a[i]<<" " ;
    return 0 ;
}
