#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    int n,m,i,tem ;
    cin>>n>>m ;
    int a[n] ;
    vector<int> v(100001,0), v1(n+2,0) ;
    for(i=0; i<n; i++)
        cin>>a[i] ;
    for(i=n-1; i>=0; i--)
    {
        if( v[ a[i] ]==0 )
        {
            v1[i+1] = v1[i+2]+1 ;
            v[ a[i] ]++ ;
        }
        else
            v1[i+1] = v1[i+2] ;
    }
    for(i=0; i<m; i++)
    {
        cin>>tem ;
        cout<<v1[tem]<<endl ;
    }
    return 0 ;
}
