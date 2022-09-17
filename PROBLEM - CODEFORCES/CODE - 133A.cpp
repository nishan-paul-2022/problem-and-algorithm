#include<iostream>
using namespace std ;
int main()
{
    char s[100] ;
    cin>>s ;
    int i=0,ver=0 ;
    while(s[i]!='\0')
    {
        if( s[i]=='H' || s[i]=='Q' || s[i]=='9')
            ver++ ;
        i++ ;
    }
    if(ver!=0)
        cout<<"YES" ;
    else
        cout<<"NO" ;
    return 0 ;
}
