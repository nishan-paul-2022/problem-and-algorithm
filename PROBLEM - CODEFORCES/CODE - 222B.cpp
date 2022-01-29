#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std ;
int main()
{
    int row,col,duty,i,j ;
    scanf("%d %d %d",&row,&col,&duty) ;
    int a[row], b[col], c[row][col] ;
    for(i=0; i<row; i++)
        a[i]=i ;
    for(i=0; i<col; i++)
        b[i]=i ;
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            scanf("%d",&c[i][j]) ;
    while(duty--)
    {
        char s[2] ;
        int x, y ;
        scanf("%s %d %d",&s,&x,&y) ;
        x--, y-- ;
        switch (s[0])
        {
            case 'r' :
                swap(a[x],a[y]) ; break ;
            case 'c' :
                swap(b[x],b[y]) ; break ;
            case 'g' :
                printf("%d\n",c[a[x]][b[y]]) ; break ;
        }
    }
    return 0;
}
