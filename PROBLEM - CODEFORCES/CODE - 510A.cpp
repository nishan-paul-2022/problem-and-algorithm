#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,m,i,j ;
    cin>>n>>m ;
    char a[n][m] ;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            a[i][j]='.' ;
    for(i=0; i<n; i=i+2)
        for(j=0; j<m; j++)
            a[i][j]='#' ;
    for(i=1; i<n; i=i+4)
        a[i][m-1]='#' ;
    for(i=3; i<n; i=i+4)
        a[i][0]='#' ;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cout<<a[i][j] ;
        cout<<endl ;
    }
    return 0 ;
}
