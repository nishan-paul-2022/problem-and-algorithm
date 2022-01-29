///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll a,value,i,sum=1,add=12;
    scanf("%lld",&a);
    if(a==1)
        printf("%lld",sum);
    else
    {
        for(i=0; i<a-1; i++)
        {
            sum=sum+add;
            add=add+12;
        }
        printf("%lld",sum);
    }
    return 0;
}

