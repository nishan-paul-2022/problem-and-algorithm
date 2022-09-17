#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,tem,sum=0,per ;
    double res ;
    cin>>n ;
    tem=n ;
    while(tem--)
    {
        cin>>per ;
        sum=sum+per ;
    }
    res = (double)sum/n ;
    printf("%.12f",res) ;
    return 0 ;
}
