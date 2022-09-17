#include<stdio.h>
int main()
{
    int a, b ;
    float s, e, SALARY ;
    scanf("%d",&a) ;
    scanf("%d",&b) ;
    scanf("%f",&s) ;
    SALARY = (float)b * s ;
    printf("NUMBER = %d\n",a) ;
    printf("SALARY = U$ %.2f\n",SALARY) ;
    return 0 ;
}
