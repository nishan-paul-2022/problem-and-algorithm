#include<stdio.h>
int main()
{
    int code1, code2, unit1, unit2 ;
    float value1, value2, total ;
    scanf("%d %d %f",&code1,&unit1,&value1) ;
    scanf("%d %d %f",&code2,&unit2,&value2) ;
    printf("VALOR A PAGAR: R$ %.2f\n",(float)unit1*value1 + (float)unit2*value2) ;
    return 0 ;
}
