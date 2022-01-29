#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i=0 ;
    cin>>n ;
    string s ;
    cin>>s ;
    sort(s.begin(),s.end(),less<char>()) ;
    while(s[i]!='D' && s[i]!='\0')
        i++ ;
    if(i==n-i)
        cout<<"Friendship" ;
    else if(i>n-i)
        cout<<"Anton" ;
    else if(i<n-i)
        cout<<"Danik" ;
    return 0 ;
}
