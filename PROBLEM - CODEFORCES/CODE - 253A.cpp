#include<iostream>
#include<string>
#include<cstdio>
using namespace std ;
int main()
{
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;

    int boy,girl,i ;
    scanf("%d %d",&boy,&girl) ;
    if(boy>=girl)
    {
        string s(boy+girl,'B') ;
        for(i=1; i<2*girl; i+=2)
            s[i]='G' ;
        const char *c = s.c_str() ;
        printf("%s",c) ;
    }
    else
    {
        string s(boy+girl,'G') ;
        for(i=1; i<2*boy; i+=2)
            s[i]='B' ;
        const char *c = s.c_str() ;
        printf("%s",c) ;
    }

    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}

