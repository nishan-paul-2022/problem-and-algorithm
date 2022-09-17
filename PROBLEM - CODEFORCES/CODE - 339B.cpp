#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,m,i,current,last=1,tem ;
    long long int time=0 ;
    cin>>n>>m ;
    for(i=0; i<m; i++)
    {
        cin>>current ;
        tem=current-last ;
        if(tem<0) tem=tem+n ;
        time+=tem ;
        last=current ;
    }
    cout<<time ;
    return 0 ;
}
