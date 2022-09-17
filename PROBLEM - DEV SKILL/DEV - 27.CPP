#define ONLINE_JUDGE 1
#include<stdio.h>
#include<math.h>
int main()
{
    long long int T ;
    scanf("%lld",&T) ;
    while(T>0)
    {
        long long int p, i, r=0 ;
        scanf("%lld",&p) ;
        if(p==0 || p==1)
            printf("No") ;
        else if(p==2 || p==3)
            printf("Yes") ;
        else
        {
            for(i=2; i<=sqrt(p); i++)
            {
                if( p%i==0 )
                    r++ ;
            }
            if(r==0)
                printf("Yes") ;
            else
                printf("No") ;
        }
        printf("\n") ;
        T-- ;
    }
    return 0 ;
}
