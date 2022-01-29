#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,j ;
    cin>>n ;
    i = (int) n/5 ;
    j = n%5 ;
    if(j==0)
        cout<<i ;
    else
        cout<<i+1 ;
    return 0 ;
}

