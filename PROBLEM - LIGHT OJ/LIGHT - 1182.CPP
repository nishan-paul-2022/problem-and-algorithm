///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll T,i,bin,cnt;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>bin;
        cnt=0;
        while(bin)
        {
            if(bin%2==1)
                cnt++;
            bin=bin/2;
        }
        if(cnt%2==1)
            printf("Case %d: odd\n",i);
        else
            printf("Case %d: even\n",i);
    }
    return 0;
}

