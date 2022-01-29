#define ONLINE_JUDGE 1
#include<stdio.h>
int main()
{
    int p, n, a, i, s, x, y ;
    double d ;
    while(scanf("%d %d",&p,&n)!=EOF)
    {
        s = 0 ;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a) ;
            s = s + a ;
        }
        if(s>=p)
            printf("Project will finish within 1 day.\n") ;
        else
        {
            x = p%s ;
            d = (float) p/s ;
            if(x==0)
            {
                y = (int) d ;
                printf("Project will finish within %d days.\n",y) ;
            }
            else
            {
                y =(int) d+1 ;
                printf("Project will finish within %d days.\n",y) ;
            }
        }
    }
    return 0 ;
}