///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);

    ll n,m,k,i,j,test,fri=0;
    scanf("%lld %lld %lld",&n,&m,&k);
    ll a[m+1];
    for(i=0; i<m+1; i++)
        scanf("%lld",&a[i]);
    for(i=0; i<m; i++)
    {
        test=0;
        for(j=0; j<n; j++)
        {
            if( (a[i]>>j & 1) != (a[m]>>j & 1) )
                test++;
        }
        if(test<=k)
            fri++;
    }
    printf("%lld",fri);

//    fclose(f);
//    system("output.txt");
    return 0;
}
