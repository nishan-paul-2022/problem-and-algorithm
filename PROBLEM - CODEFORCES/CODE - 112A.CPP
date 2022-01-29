#include<stdio.h>
#include<string.h>
int main()
{
    char a[100], b[100] ;
    gets(a) ;
    gets(b) ;
    int n = stricmp(a,b) ;
    printf("%d",n) ;
    return 0 ;
}
