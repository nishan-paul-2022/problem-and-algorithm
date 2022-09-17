#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,high,posh,low,posl,test=0 ;
    cin>>n ;
    int a[n] ;
    for(i=0; i<n; i++)
    {
        cin>>a[i] ;
        if(i==0)
        {
            high=a[i] ;
            posh=i ;
            low=a[i] ;
            posl=i ;
        }
            if(a[i]>high)
            {
                high = a[i] ;
                posh = i ;
            }
            if(a[i]<=low)
            {
                low = a[i] ;
                posl = i ;
            }
    }
    for(i=1; i<n; i++)
        if(a[i]!=a[i-1]) test++ ;
    if(test!=0)
    {
        if(posh<posl)
            cout<<posh+(n-(posl+1)) ;
        else
            cout<<posh+(n-(posl+1))-1 ;
    }
    else
        cout<<0 ;
    return 0 ;
}

