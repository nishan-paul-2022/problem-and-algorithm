#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s ;
    cin>>s ;
    int i,k=0 ;
    for(i=0; i<s.size(); i++)
    {
        if( s[i]=='W' && s[i+1]=='U' && s[i+2]=='B' )
        {
            i=i+2 ;
            if(k!=0) cout<<" " ;
        }
        else
        {
            cout<<s[i] ;
            k++ ;
        }
    }
    return 0 ;
}

