#include<bits/stdc++.h>
#define pi 3.14159265
using namespace std;
int main()
{
    int T,i,n;
    double r,R;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>R>>n;
        r = R*sin(pi/n) / ( 1+sin(pi/n) );
        printf("Case %d: %.7lf\n",i,r);
    }
    return 0;
}

