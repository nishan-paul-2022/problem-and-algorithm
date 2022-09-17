#include<bits/stdc++.h>
using namespace std ;
int gcd(int big,int small)
{
    if(small==0)
        return big ;
    else
        gcd(small,big%small) ;
}
int main()
{
    int a,b,c,big,small,i=0 ;
    cin>>a>>b>>c ;
    while( c!=0 )
    {
        if(i==0)
        {
            big = c>=a? c:a ;
            small = c<=a? c:a ;
            c = c-gcd(big,small) ;
            i=1 ;
        }
        else if(i==1)
        {
            c = c-gcd(c,b) ;
            i=0 ;
        }
    }
    if(i==1)
        cout<<"0" ;
    else
        cout<<"1" ;
    return 0 ;
}

