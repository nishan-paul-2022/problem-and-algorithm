#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,test=0 ;
    cin>>n ;
    int a[n] ;
    for(i=0; i<n; i++)
    {
        cin>>a[i] ;
        if(a[i]%2==0)
            test++ ;
    }
    if(test==n-1)
    {
        for(i=0; i<n; i++)
        {
            if(a[i]%2!=0)
                cout<<i+1 ;
        }
    }
    else if(test==1)
    {
        for(i=0; i<n; i++)
        {
            if(a[i]%2==0)
                cout<<i+1 ;
        }
    }
    return 0 ;
}
