#include<bits/stdc++.h>
using namespace std ;
int main()
{
    char s1[100000],s2[100000] ;
    cin>>s1 ;
    cin>>s2 ;
    strrev(s1) ;
    if( strcmp(s1,s2)==0 )
        cout<<"YES" ;
    else
        cout<<"NO" ;
    return 0 ;
}
