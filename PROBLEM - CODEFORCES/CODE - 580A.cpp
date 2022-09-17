#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,a,b,c=1,d=1 ;
    cin>>n ;
    for(i=0; i<n; i++)
    {
        cin>>a ;
        if(i!=0)
        {
            if(b<=a)
            {
                c++ ;
                d = c>=d? c:d ;
            }
            else
                c=1 ;
        }
        b=a ;
    }
    cout<<d ;
    return 0 ;
}
