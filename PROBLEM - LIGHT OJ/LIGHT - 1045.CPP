///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
vector<double> arr;
void f(){
    arr.push_back(0);
    for(ll i=1; i<=1000000; i++)
        arr.push_back(arr[i-1]+log(i));
}
int main()
{
    f();
    ll tst;
    scanf("%lld",&tst);
    for(ll i=1; i<=tst; i++){
        ll n,base,k;
        double ans;
        scanf("%lld %lld",&n,&base);
        ans=arr[n]/log(base);
        k=ans+1;
        printf("Case %lld: %lld\n",i,k);
    }
    return 0;
}

