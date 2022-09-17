#define ONLINE_JUDGE 1
#include<stdio.h>
int main()
{
    long long int T ;
    scanf("%lld",&T) ;
    while(T--)
    {
        long long int i,n,s=0 ;
        scanf("%lld",&n) ;
        for(i=1; s<n; i++)
        {
            s = s + i ;
        }
        printf("%lld\n",i-1) ;
    }
    return 0 ;
}
