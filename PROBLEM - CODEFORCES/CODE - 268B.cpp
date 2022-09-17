#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, result, i, j;
    scanf("%lld",&n);
    result=n*(n+1)/2;
    j=n-2;
    for(i=1; i<=n-2; i++,j--)
    {
        result+=i*j;
    }
    printf("%lld",result);
    return 0;
}
