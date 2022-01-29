#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,k=0 ;
    string s ;
    char c ;
    cin>>n ;
    for(i=0; i<n; i++)
    {
        cin>>s ;
        if(i==0) c=s[0] ;
        else
        {
            if(c!=s[0])
            {
                k++ ;
                c=s[0] ;
            }
        }
    }
    cout<<k+1 ;
    return 0 ;
}
