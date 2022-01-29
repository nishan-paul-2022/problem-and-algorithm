#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std ;
int main()
{
    int dice, turn, i ;
    cin>>dice>>turn ;
    double n=dice, m=turn, sum=1 ;
    if(dice!=1)
    {
        sum=0 ;
        for(i=1; i<=dice; i++)
        {
            double uny, p1, p2 ;
            uny = i ;
            p1 = pow( (uny-1)/n, m ) ;
            p2 = pow( uny/n, m ) ;
            sum = sum + uny*(p2-p1) ;
        }
    }
    printf("%.12lf",sum) ;
    return 0 ;
}
