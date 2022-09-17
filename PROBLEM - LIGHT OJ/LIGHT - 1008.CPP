#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll T,i,tem,value,x,y,mid;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>value;
        x=ceil(sqrt(value));
        mid =x*(x-1)+1;
        y=x-abs(mid-value);
        if( x%2==0 && (mid-value)<0  || x%2==1 && (mid-value)>0 )
        {
            tem=x;
            x=y;
            y=tem;
        }
        cout<<"Case "<<i<<": "<<y<<' '<<x<<'\n';
    }
    return 0;
}
