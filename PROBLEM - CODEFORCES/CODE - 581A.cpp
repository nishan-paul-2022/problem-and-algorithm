#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int a,b,sum, mx, mi ;
    cin>>a>>b ;
    mx = max(a,b) ;
    mi = min(a,b) ;
    cout<<mi<<" "<<(int)((mx-mi)*0.5) ;
    return 0 ;
}
