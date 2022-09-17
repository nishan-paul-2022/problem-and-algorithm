#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,t,i;
    cin>>n>>t;
    for(i=0; i<n; i++)
    {
        if(n==1 && t==10)
            cout<<-1;
        else if(i<n-1 && t==10)
            cout<<1;
        else if(i==n-1 && t==10)
            cout<<0;

        else
            cout<<t;
    }
    return 0 ;
}
