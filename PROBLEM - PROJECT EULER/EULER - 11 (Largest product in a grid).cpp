///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    system("input.txt");
    freopen("input.txt","r",stdin);
    FILE *f=freopen("output.txt","w",stdout);

    ll arr[20][20], ans=0, tem;
    for(ll i=0; i<=19; i++)
        for(ll j=0; j<=19; j++)
            cin>>arr[i][j];
    for(ll i=0; i<=19; i++)
        for(ll j=0; j<=16; j++){
            tem=arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3];
            ans=max(ans,tem);
        }

    for(ll j=0; j<=19; j++)
        for(ll i=0; i<=16; i++){
            tem=arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j];
            ans=max(ans,tem);
        }

    for(ll i=0; i<=16; i++)
        for(ll j=0; j<=16; j++){
            tem=arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
            ans=max(ans,tem);
        }

    for(ll i=0; i<=16; i++)
        for(ll j=19; j>=3; j--){
            tem=arr[i][j]*arr[i+1][j-1]*arr[i+2][j-2]*arr[i+3][j-3];
            ans=max(ans,tem);
        }

    cout<<ans<<lne;
    fclose(f);
    system("output.txt");
    return 0;
}

