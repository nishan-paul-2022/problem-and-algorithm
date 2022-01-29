#include<stdio.h>
int main()
{
    int n,m,a ;
    long long int r,c ;
    scanf("%d %d %d",&n,&m,&a) ;
    r = (int) n/a ;
    c = (int) m/a ;
    if(n%a)
        r++ ;
    if(m%a)
        c++ ;
    printf("%I64d",r*c) ;
    return 0 ;
}
