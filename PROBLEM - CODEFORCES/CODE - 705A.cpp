#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,tem,p=0 ;
    cin>>n ;
    tem=n ;
    while(tem>1)
    {
        if(p==0)
        {
            p=1 ;
            cout<<"I hate that " ;
        }
        else
        {
            p=0 ;
            cout<<"I love that " ;
        }
        tem-- ;
    }
    if(n%2==0)
        cout<<"I love it" ;
    else
        cout<<"I hate it" ;
    return 0 ;
}
