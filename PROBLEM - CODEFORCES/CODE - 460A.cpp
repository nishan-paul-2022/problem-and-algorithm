#include<bits/stdc++.h>
using namespace std ;
int f(int n,int m)
{
    int tem ;
    if(n<m)
        return 0 ;
    else
    {
        tem = n/m ;
        n = n/m + n%m ;
        return tem + f(n,m) ;
    }
}
int main()
{
    int n,m,result ;
    cin>>n>>m ;
    result = n + f(n,m) ;
    cout<<result ;
    return 0 ;
}
