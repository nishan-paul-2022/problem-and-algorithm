#include<iostream>
#include<algorithm>
using namespace std ;
int main()
{
    int n,m,p,v ;
    cin>>n>>m ;
    v = n<=m?n:m ;
    p = n+m-1-v ;
    cout<<p<<" "<<v ;
    return 0 ;
}

