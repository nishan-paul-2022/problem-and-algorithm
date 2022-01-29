#include<bits/stdc++.h>
using namespace std ;
int f(int x)
{
    int i,y,test=0 ;
    y=sqrt(x)+1 ;
    for(i=2; i<=y; i++)
        if(x%i==0)
            test++ ;
    return test ;
}
int main()
{
    int n,i,j,k ;
    cin>>n ;
    for(i=4; i<=n/2; i++)
    {
        j=f(i) ;
        k=f(n-i) ;
        if(j!=0 && k!=0)
        {
            cout<<i<<" "<<n-i ;
            return 0 ;
        }
    }
    return 0 ;
}

