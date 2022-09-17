#include<iostream>
using namespace std ;
int main()
{
    int n,i,time ;
    cin>>n ;
    int x[n], y[n],xodd=0,yodd=0,rot=0 ;
    for(i=0; i<n; i++)
    {
        cin>>x[i]>>y[i] ;
        if( x[i]%2 != 0 ) xodd++ ;
        if( y[i]%2 != 0 ) yodd++ ;
        if( x[i]%2 != y[i]%2 ) rot=1 ;
    }
    if( xodd%2==0 && yodd%2==0 )
        time=0 ;
    else if( xodd%2==1 && yodd%2==1 && rot==1)
        time=1 ;
    else
        time=-1 ;
    cout<<time ;
    return 0 ;
}

