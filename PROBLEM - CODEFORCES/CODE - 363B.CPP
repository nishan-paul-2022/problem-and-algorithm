#include<iostream>
using namespace std ;
int main()
{
    int n, k, i, j, comp, res=1, sum=0 ;
    cin>>n>>k ;
    int tem[n] ;
    for(i=0; i<n; i++)
    {
        cin>>tem[i] ;
        sum+=tem[i] ;
        if( i==k-1 ) comp=sum+1 ;
        if( i>=k-1 )
        {
            if(sum<comp)
            {
                comp=sum ;
                res=i-k+1 ;
            }
            sum-=tem[i-k+1] ;
        }
    }
    cout<<res+1 ;
    return 0 ;
}

