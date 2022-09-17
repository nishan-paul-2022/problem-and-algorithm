#define ONLINE_JUDGE 1
#include<stdio.h>
#include<math.h>
int main()
{
    int T, i ;
    double x,y,z,d,e ;
    scanf("%d",&T) ;
    for(i=0; i<T; i++)
    {
        scanf("%lf %lf %lf",&x,&y,&z) ;
        d = x*x + y*y + z*z ;
        e = sqrt(d) ;
        printf("%.2lf\n",e) ;
    }
    return 0 ;
}