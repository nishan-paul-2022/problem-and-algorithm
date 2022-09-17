#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std ;
int main()
{
    int y,k,n,i,sum=0,test=0 ;
    cin>>y>>k>>n ;
    for(i=y/k+1; k*i<=n; i++)
    {
        sum = k*i ;
        if(sum%k==0)
        {
            cout<<(sum-y)<<" " ;
            test++ ;
        }
    }
    if(test==0)
        cout<<-1 ;
    return 0 ;
}
