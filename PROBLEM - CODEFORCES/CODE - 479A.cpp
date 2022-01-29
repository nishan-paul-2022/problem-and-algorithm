#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int a1,a2,a3, s[6] ;
    cin>>a1>>a2>>a3 ;
    s[0] = a1+a2+a3 ;
    s[1] = a1*(a2+a3) ;
    s[2] = (a1*a2)+a3 ;
    s[3] = a1+(a2*a3) ;
    s[4] = (a1+a2)*a3 ;
    s[5] = a1*a2*a3 ;
    sort(s,s+6) ;
    cout<<s[5] ;
    return 0 ;
}
