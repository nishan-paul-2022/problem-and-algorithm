#include<stdio.h>
#include<string.h>
int main()
{
    int i=0 ;
    char w[100] ;
    gets(w) ;
    strlwr(w) ;
    while( w[i]!='\0' )
    {
        if( !(w[i]=='a' || w[i]=='e' || w[i]=='i' ||w[i]=='o' || w[i]=='u' || w[i]=='y') )
            printf(".%c",w[i]) ;
        i++ ;
    }
    return 0 ;
}
