#include<stdio.h>
int main()
{
    double a, b, MEDIA ;
    scanf("%lf",&a) ;
    scanf("%lf",&b) ;
    if(a<=10 && b<=10)
    {
        MEDIA = (a*3.5+b*7.5)/11 ;
        printf("MEDIA = %.5lf\n",MEDIA) ;
        return 0 ;
    }
    else
        return 0 ;
}
