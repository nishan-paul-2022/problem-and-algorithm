#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i ;
    cin>>n ;
    int a[n], b[n] ;
    for(i=0; i<n; i++)
    {
        cin>>a[i] ;
        b[ a[i]-1 ] = i+1 ;
    }
    for(i=0; i<n; i++)
    {
        cout<<b[i]<<" " ;
    }
    return 0 ;
}
