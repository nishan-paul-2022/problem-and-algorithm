#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,length ;
    cin>>n ;
    char s[n] ;
    cin>>s ;
    strlwr(s) ;
    set<char> some ;
    for(i=0; i<n; i++)
        some.insert(s[i]) ;
    length = some.size() ;
    if(length==26)
        cout<<"YES" ;
    else
        cout<<"NO" ;
}
