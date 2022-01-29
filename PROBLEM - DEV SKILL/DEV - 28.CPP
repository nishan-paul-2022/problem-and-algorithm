#include<stdio.h>
int main()
{
    int T,i ;
    float r,s ;
    int v ;
    scanf("%d",&T) ;
    for(i=0; i<T; i++)
    {
        scanf("%f %f",&r,&s) ;
        v = s*100/r ;
        if(v==141)
            printf("Yes\n") ;
        else
            printf("No\n") ;
    }
    return 0 ;
}
