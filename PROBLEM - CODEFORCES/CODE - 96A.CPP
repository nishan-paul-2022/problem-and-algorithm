#include<stdio.h>
#include<string.h>
int main()
{
    int j=0, k=0, m ;
    char w[100] ;
    gets(w) ;
    m = strlen(w) ;
    while(m--)
    {
        if( w[m]=='0' )
            j++, k=0 ;
        else if( w[m]=='1' )
            k++, j=0 ;
        if( j==7 || k==7 )
        {
            printf("YES") ;
            return 0 ;
        }
    }
    printf("NO") ;
    return 0 ;
}
