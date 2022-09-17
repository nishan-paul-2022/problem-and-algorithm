#include <stdio.h>
int main()
{
    int N,y,w,m,n,d;
    scanf("%d",&N);
    y=N/365;
    w=N%365;
    m=w/30;
    n=w%30;
    d=n/1;
    printf("%d ano(s)\n",y);
    printf("%d mes(es)\n",m);
    printf("%d dia(s)\n",d);
    return 0;
}
