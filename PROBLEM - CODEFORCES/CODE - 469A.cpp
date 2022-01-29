#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int i,n,p,q,k=0 ;
    cin>>n ;
    cin>>p ;
    int a[p] ;
    for(i=0; i<p; i++)
        cin>>a[i] ;
    cin>>q ;
    int b[q] ;
    for(i=0; i<q; i++)
        cin>>b[i] ;
    int c[p+q] ;
    for(i=0; i<p+q; i++)
    {
        if(i<p)
            c[i]=a[i] ;
        else
        {
            c[i]=b[k] ;
            k++ ;
        }
    }
    sort(c+0,c+p+q) ;
    k=0 ;
    for(i=0; i<p+q; i++)
    {
        if(c[i]==k+1) k++ ;
        if(k==n)
        {
            cout<<"I become the guy." ;
            return 0 ;
        }
    }
    cout<<"Oh, my keyboard!" ;
    return 0 ;
}

