#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s1, s2, s3, sum ;
    cin>>s1>>s2>>s3 ;
    sum = s1+s2 ;
    sort( sum.begin(),sum.end(),less<char>() ) ;
    sort( s3.begin(),s3.end(),less<char>() ) ;
    if( sum.compare(s3)==0 )
        cout<<"YES" ;
    else
        cout<<"NO" ;
    return 0 ;
}
