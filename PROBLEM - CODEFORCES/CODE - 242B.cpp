#include<iostream>
#include<algorithm>
using namespace std ;
int main()
{
    int n, x, y, mx, my, i, result=1 ;
    cin>>n ;
    cin>>mx>>my ;
    for (i=2; i<=n; i++)
    {
        cin>>x>>y ;
        if (x<=mx && y>=my)
            result=i ;
        else if (x<mx || y>my)
            result=-1 ;
        mx = min(mx,x) ;
        my = max(my,y) ;
    }
    cout<<result ;
    return 0;
}

