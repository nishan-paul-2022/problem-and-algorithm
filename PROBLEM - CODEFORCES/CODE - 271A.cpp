#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int i,n,j1,j2,j3,j4 ;
    cin>>i ;
    for(n=i+1; n>i; n++)
    {
        j1 = n%10, j1 = (int) j1/1 ;
        j2 = n%100, j2 = (int) j2/10 ;
        j3 = n%1000, j3 = (int) j3/100 ;
        j4 = n%10000, j4 = (int) j4/1000 ;
        if(j1!=j2 && j1!=j3 && j1!=j4 && j2!=j3 && j2!=j4 && j3!=j4 )
            break ;
    }
    cout<<n ;
    return 0 ;
}
