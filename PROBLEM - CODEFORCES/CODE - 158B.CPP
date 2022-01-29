#include<stdio.h>
#include<math.h>
int main()
{
    int Team, i=0, f=0, th=0, tw=0, o=0, on=0, sum ;
    scanf("%d",&Team) ;
    int a[Team] ;
    while(i<Team)
    {
        scanf("%d%*c",&a[i]) ;
        i++ ;
    }
    i=0 ;
    while(i<Team)
    {
        if( a[i]==4 ) f++ ;
        else if( a[i]==3 ) th++ ;
        else if( a[i]==2 ) tw++ ;
        else if( a[i]==1 ) o++ ;
        i++ ;
    }
    if( th!=0 && o!=0 )
    {
        if(th<=o) o = o - th ;
        else o = 0 ;
    }
    if( tw%2!=0 )
    {
        tw-- ;
        o = o + 2 ;
    }
    if( o%4!=0 )
    {
        on = 1 + (int) o/4 ;
    }
    else
        on = o/4 ;
    sum = f + th + tw/2 + on ;
    printf("%d",sum) ;
    return 0 ;
}
