#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,k,j1,j2,test=0 ;
    cin>>n ;
    int a[n],b[n] ;
    for(i=0; i<n; i++)
    {
        cin>>j1>>j2 ;
        a[i]=j1 ;
        b[i]=j2 ;
    }
    for(i=0; i<n; i++)
    {
        for(k=0; k<n; k++)
            if(a[i]==b[k])
                test++ ;
    }
    cout<<test ;
    return 0 ;
}

