#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,m,i,tem,sum=0 ;
    cin>>n>>m ;
    for(i=0; i<n; i++)
    {
        cin>>tem ;
        if(tem>m)
            sum+=2 ;
        else
            sum+=1 ;
    }
    cout<<sum ;
    return 0 ;
}

