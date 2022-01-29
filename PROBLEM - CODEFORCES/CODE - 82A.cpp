#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int i,j=5,k=1,seq ;
    cin>>i ;
    string s[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"} ;
    while(j<i)
    {
        i=i-j ;
        j=j*2 ;
        k=k*2 ;
    }
    seq=(int)(i-1)/k ;
    cout<<s[seq] ;
    return 0 ;
}
