#include<iostream>
#include<vector>
#include<string>
using namespace std ;
int main()
{
    string s ;
    cin>>s ;
    int n,i ;
    cin>>n ;
    vector<int> v( s.length(),0 ) ;
    for(i=1; i<s.length(); i++)
    {
        if( s[i]==s[i-1] )
            v[i]=v[i-1]+1 ;
        else
            v[i]=v[i-1] ;
    }
    while(n--)
    {
        int x,y,sum ;
        cin>>x>>y ;
        sum = v[y-1]-v[x-1] ;
        cout<<sum<<endl ;
    }
    return 0 ;
}

