#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,t,x,i,j=1,v=0,s=1,test=0 ;
    cin>>n>>t ;
    int b[n] ;
    b[0]=1 ;
    for(i=0; i<n-1; i++)
    {
        cin>>x ;
        if(i==v)
        {
            s=s+x ;
            b[j]=s ;
            v=s-1 ;
            j++ ;
        }
    }
    for(i=0; i<j; i++)
        if(t==b[i]) test++ ;
    if(test)
        cout<<"YES" ;
    else
        cout<<"NO" ;
    return 0 ;
}

