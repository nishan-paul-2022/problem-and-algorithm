#include <stdio.h>
int main()
{
    int N,a,b,c,d,e;
    scanf("%d",&N);
    a=N/3600;
    b=N%3600;
    c=b/60;
    d=b%60;
    e=d/1;
    printf("%d:%d:%d\n",a,c,e);
    return 0;
}
