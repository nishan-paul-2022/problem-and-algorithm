#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,m,rem,rem1 ;
    cin>>n ;
    if(n>=0)
        cout<<n ;
    else
    {
        n=abs(n) ;
        rem = n%10 ;
        rem1 = (n%100)/10 ;
        n = (int) n/10 ;
        m = n+(rem-rem1) ;
        cout<<-min(n,m) ;
    }
    return 0 ;
}
