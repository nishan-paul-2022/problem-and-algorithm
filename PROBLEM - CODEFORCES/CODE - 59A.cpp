#include<bits/stdc++.h>
using namespace std ;
int main()
{
    char s[1000] ;
    cin>>s ;
    int n,i,l=0 ;
    n = strlen(s) ;
    for(i=0; i<n; i++)
    {
        if(s[i]>='a' && s[i]<='z')
            l++ ;
    }
    if(n%2==0)
        n = n/2 ;
    else
        n = 1 + (int)n/2 ;
    if(l<n)
        cout<<strupr(s) ;
    else
        cout<<strlwr(s) ;
    return 0 ;
}
