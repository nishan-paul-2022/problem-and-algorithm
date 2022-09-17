#include<bits/stdc++.h>
using namespace std ;
int f(int n)
{
    int i=0, test=0 ;
    char s[100] ;
    sprintf(s,"%d",n) ;
    while(s[i]!='\0')
    {
        if(s[i]!='4' && s[i]!='7')
            test++ ;
        i++ ;
    }
    return test ;
}
int main()
{
    int n,i=0,test=0 ;
    cin>>n ;
    test=f(n) ;
    if(test==0)
        cout<<"YES" ;
    else
    {
        test=0 ;
        for(i=2; i<=n/2; i++)
        {
            if(n%i==0)
            {
                if(f(i)==0)
                    test++ ;
            }
        }
        if(test!=0)
            cout<<"YES" ;
        else
            cout<<"NO" ;
    }
    return 0 ;
}

