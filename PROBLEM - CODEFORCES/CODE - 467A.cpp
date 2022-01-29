#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i=0,room=0,cap,high ;
    cin>>n ;
    while(i<n)
    {
        cin>>cap>>high ;
        if(high-cap>=2) room++ ;
        i++ ;
    }
    cout<<room ;
    return 0 ;
}
