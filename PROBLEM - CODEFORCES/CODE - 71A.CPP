#include<stdio.h>
#include<string.h>
int main()
{
    int T ;
    scanf("%d",&T) ;
    getchar() ;
    while(T--)
    {
        char w[100] ;
        gets(w) ;
        int n = strlen(w) ;
        if(n<=10)
            printf("%s",w) ;
        else
        {
            printf("%c%d%c",w[0],n-2,w[n-1]) ;
        }
        printf("\n") ;
    }
    return 0 ;
}
