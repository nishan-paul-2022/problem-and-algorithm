#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,n,j ;
    char a[1000], tem ;
    scanf("%d\n",&T) ;
    for(i=0; i<T; i++)
    {
        scanf("%[^\n]",&a) ;
        getchar() ;
        n = strlen(a) ;
        if(n%2==0)
        {
            for(j=0; j<n/2; j++)
            {
                tem = a[j] ;
                a[j] = a[n-1-j] ;
                a[n-1-j] = tem ;
            }
        }
        else
        {
            for(j=0; j<(n-1)/2; j++)
            {
                tem = a[j] ;
                a[j] = a[n-1-j] ;
                a[n-1-j] = tem ;
            }
        }
        printf("%s\n",a) ;
    }
}
