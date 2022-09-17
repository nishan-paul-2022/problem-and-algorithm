///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,L,brk, cnt=0;
    cin>>n>>L>>brk;
    ll t=0;
    for(ll i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        cnt = cnt + (x-t)/brk;
        t=x+y;
        if(i==n-1)
            cnt+=(L-t)/brk;
    }
    if(n==0)
        cnt=L/brk;
    cout<<cnt;
//    fclose(f);
//    system("output.txt");
    return 0;
}

