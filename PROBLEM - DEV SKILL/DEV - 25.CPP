#define ONLINE_JUDGE 1
#include<stdio.h>
#include<string.h>
int main()
{
    int T, i, n,j,k ;
    scanf("%d\n",&T) ;
    for(i=0; i<T; i++)
    {
        char a[100] ;
        scanf("%s",&a) ;
        n = strlen(a) ;
        for(k=0; k<n; k++)
        {
            if(a[k]>=65 && a[k]<=90)
                a[k] = a[k]-'A'+'a' ;
        }
        if(n%2==0)
        {
            for(j=0; j<n/2 && a[j]-a[n-1-j]==0 ; j++) ;

            if(j==n/2)
                printf("Yes") ;
            else
                printf("No") ;
        }
        else
        {
            for(j=0; j<(n-1)/2 && a[j]-a[n-1-j]==0 ; j++) ;

            if(j==(n-1)/2)
                printf("Yes") ;
            else
                printf("No") ;
        }
        printf("\n") ;
    }
    return 0 ;
}
