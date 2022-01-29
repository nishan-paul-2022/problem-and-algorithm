#include<stdio.h>
#include<string.h>
int main()
{
    char s[100], tem ;
    gets(s) ;
    int i, j, k ;
    i = strlen(s) ;
    for(j=0; j<i; j=j+2)
    {
        for(k=j+2; k<i; k=k+2)
        {
            if( s[j]>s[k] )
            {
                tem = s[j] ;
                s[j] = s[k] ;
                s[k] = tem ;
            }
        }
    }
    printf("%s",s) ;
    return 0 ;
}
