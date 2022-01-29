///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll k,n,s,p,res,mul;
    cin>>k>>n>>s>>p;

    mul=n/s;
    if(n%s!=0) mul+=1;

    mul=mul*k;
    res=mul/p;
    if(mul%p!=0) res+=1;
    printf("%lld",res);
    return 0;
}
