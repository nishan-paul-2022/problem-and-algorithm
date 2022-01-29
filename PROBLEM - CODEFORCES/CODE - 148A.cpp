#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int k,l,m,n,d,i=1,c=0 ;
    cin>>k>>l>>m>>n>>d ;
    while(i<=d)
    {
        if( i%k==0 || i%l==0 || i%m==0 || i%n==0 )
            c++ ;
        i++ ;
    }
    cout<<c ;
    return 0 ;
}
