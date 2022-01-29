#include<iostream>
using namespace std;
int main()
{
    long long int n,i,tem,a[100001],maxi=0,point[100001] ;
    cin>>n ;
    for(i=0; i<100001; i++)
        a[i]=0 ;
    for(i=0; i<n; i++)
    {
        cin>>tem ;
        a[tem]++ ;
        maxi=max(maxi,tem) ;
    }
    point[0]=0 ;
    point[1]=a[1] ;
    for(i=2; i<=maxi; i++)
    {
        point[i] = max( i*a[i]+point[i-2], point[i-1] ) ;
    }
    cout<<point[maxi] ;
    return 0 ;
}
