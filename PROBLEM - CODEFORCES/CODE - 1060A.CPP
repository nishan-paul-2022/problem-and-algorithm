///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n, cnt=0, num;
    cin>>n;
    string s;
    cin>>s;
    for(ll i=0; i<n; i++)
        if(s[i]=='8')
            cnt++;
    num=n/11;
    ll ans=min(num,cnt);
    cout<<ans;
    return 0;
}

