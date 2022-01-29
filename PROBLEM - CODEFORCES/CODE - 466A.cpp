#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int ride,sep,rate,one,i,j,mini,tem ;
    cin>>ride>>sep>>one>>rate ;
    int a[ride] ;
    for( i=1; i*sep<=ride; i++ )
    {

    }
    if(ride%sep==0) i-- ;
    mini = min( ride*one, i*rate ) ;
    for(j=1; j<i; j++)
    {
        tem=j*rate + (ride-(j*sep))*one ;
        mini=min(mini,tem) ;
    }
    cout<<mini ;
    return 0 ;
}
