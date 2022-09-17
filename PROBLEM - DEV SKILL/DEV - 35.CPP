#define ONLINE_JUDGE 1
#include<stdio.h>
#include<math.h>
int main()
{
    int T, t=1 ;
    scanf("%d",&T) ;
    while(t<=T)
    {
        int n,i ;
        scanf("%d",&n) ;
        i = (int) sqrt(n) ;
        if( i - sqrt(n) )
            printf("Case %d: NO",t) ;
        else
            printf("Case %d: YES",t) ;
        printf("\n") ;
        t++ ;
    }
    return 0 ;
}
