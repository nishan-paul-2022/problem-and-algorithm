#include<bits/stdc++.h>
using namespace std ;
int main()
{
    long long int n,k,m ;
    cin>>n>>k ;
    m = n%2==0? n/2 : n/2+1 ;
    if(k<=m)
        cout<<(2*k-1) ;
    else
    {
        cout<<(2*(k-m)) ;
    }
    return 0 ;
}
