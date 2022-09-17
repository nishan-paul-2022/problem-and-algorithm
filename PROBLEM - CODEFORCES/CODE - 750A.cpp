#include<iostream>
using namespace std ;
int main()
{
    int n,k,i,sum=1 ;
    cin>>n>>k ;
    k=240-k ;
    for(i=1; i<=n; i++)
    {
        sum=5*i*(i+1)/2 ;
        if(sum>k)
            break ;
    }
    i-- ;
    cout<<i ;
    return 0 ;
}


