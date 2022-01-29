#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int x1,x2,x3,sum1,sum2,sum3,res ;
    cin>>x1>>x2>>x3 ;
    sum1 = abs(x1-x2)+abs(x1-x3) ;
    sum2 = abs(x2-x1)+abs(x2-x3) ;
    sum3 = abs(x3-x1)+abs(x3-x2) ;
    res = min(min(sum1,sum2),sum3) ;
    cout<<res ;
    return 0 ;
}

