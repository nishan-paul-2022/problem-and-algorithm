#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s1,s2 ;
    cin>>s1 ;
    cin>>s2 ;
    int i=0 ;
    while(s1[i]!='\0')
    {
        if(s1[i]==s2[i])
            s1[i]='0' ;
        else
            s1[i]='1' ;
        i++ ;
    }
    cout<<s1 ;
    return 0 ;
}

