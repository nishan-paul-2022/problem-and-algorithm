//#include<iostream>
//#include<cstring>
//#include<cstdio>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int i=0,k=0 ;
    char s[100], test[]="hello" ;
    gets(s) ;
    strlwr(s) ;
    while(s[i]!='\0' && k<=5)
    {
        if(s[i]==test[k])
            k++ ;
        i++ ;
    }
    if(k==5) cout<<"YES" ;
    else cout<<"NO" ;
    return 0 ;
}
