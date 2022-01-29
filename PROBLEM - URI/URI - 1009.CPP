#include<stdio.h>
int main()
{
    char name[100] ;
    gets(name) ;
    double salary, sell, TOTAL ;
    scanf("%lf",&salary) ;
    scanf("%lf",&sell) ;
    TOTAL = salary + ( sell* 0.15 ) ;
    printf("TOTAL = R$ %.2lf\n",TOTAL) ;
    return 0 ;
}
