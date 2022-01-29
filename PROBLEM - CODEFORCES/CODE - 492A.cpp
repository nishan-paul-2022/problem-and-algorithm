#include<iostream>
using namespace std ;
int main()
{
    int n,i=0,sum=0 ;
    cin>>n ;
    while(1)
    {
        i++ ;
        sum+=i*(i+1)/2 ;
        if(sum>n)
            break ;
    }
    i-- ;
    cout<<i ;
    return 0 ;
}
