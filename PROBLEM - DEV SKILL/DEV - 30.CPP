#define ONLINE_JUDGE 1
#include<stdio.h>
#include<string.h>
int main()
{
    int T,t=1 ;
    scanf("%d",&T) ;
    getchar() ;
    while(t<=T)
    {
        char a[100], i ;
        int j,k,n ;
        scanf("%s",a) ;
        n = strlen(a) ;
        printf("Case %d:\n",t) ;
        for(i=97; i<=122; i++)
        {
            k=0 ;
            for(j=0; j<n; j++)
            {
                if(a[j]==i)
                    k++ ;
            }
            if(k)
            printf("%c %d\n",i,k) ;
        }
        t++ ;
    }
    return 0 ;
}
