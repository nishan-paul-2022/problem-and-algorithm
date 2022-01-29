#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll x,y;
    cin>>x>>y;
    double v1;
    v1=y*log(x)-x*log(y);
    if(v1==0) cout<<"="<<lne;
    else if(v1<0) cout<<"<"<<lne;
    else if(v1>0) cout<<">"<<lne;
    return 0;
}
