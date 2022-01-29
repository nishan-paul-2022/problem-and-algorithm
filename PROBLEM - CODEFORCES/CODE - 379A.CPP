#include<stdio.h>
#include<math.h>
int main()
{
    long int a,b,sum,tem ;
    scanf("%ld %ld",&a,&b) ;
    sum = a ;
    while(a>=b)
    {
        tem = (long int) a/b ;
        sum = sum+tem ;
        a = tem + a%b ;
    }
    printf("%d",sum) ;
    return 0 ;
}

