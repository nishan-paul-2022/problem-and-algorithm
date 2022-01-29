#define ONLINE_JUDGE 1
#include<stdio.h>
int main()
{
    int T ;
    scanf("%d",&T) ;
    while(T>0)
    {
        long int i, n, s=0, m=2 ;
        scanf("%ld",&n) ;
        for(i=1; i<=n-1; i++)
        {
            s = s+m ;
            m = m+4 ;
        }
        printf("%ld\n",s) ;
        T-- ;
    }
    return 0 ;
}
