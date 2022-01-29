#define ONLINE_JUDGE 1
#include<stdio.h>
#include<math.h>
int main()
{
    int T, i, a,b,d,e ;
    double c,v ;
    scanf("%d",&T) ;
    for(i=1; i<=T; i++)
    {
        scanf("%d %d %lf %d %d",&a,&b,&c,&d,&e) ;
        v = sqrt((a-d)*(a-d)+(b-e)*(b-e)) ;
        if(v<c)
            printf("Case %d: Inside",i) ;
        else if(v>c)
            printf("Case %d: Outside",i) ;
        else
            printf("Case %d: OnCircle",i) ;
        printf("\n") ;
    }
    return 0 ;
}