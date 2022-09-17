#define ONLINE_JUDGE 1
#include<stdio.h>
int main()
{
    int T, i, a,b,c,d,a1,b1,c1,d1 ;
    scanf("%d",&T) ;
    for(i=0; i<T; i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d) ;
        scanf("%d %d %d %d",&a1,&b1,&c1,&d1) ;
        if(a+b>c+d && a1+b1>c1+d1)
            printf("Banglawash") ;
        else
            printf("Miss") ;
        printf("\n") ;
    }
    return 0 ;
}