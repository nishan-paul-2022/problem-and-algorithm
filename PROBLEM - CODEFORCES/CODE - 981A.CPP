#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll sze=s.length();
    if(sze==1) cout<<0;
    else
    {
        ll tst=0, pal=0;
        for(ll i=0; i<sze-1; i++)
            if(s[i]!=s[i+1]) tst++;
        if(tst==0) cout<<0;
        else{
            for(ll i=0; i<sze/2; i++)
                if(s[i]!=s[sze-1-i])
                    pal++;
            if(pal==0) cout<<sze-1;
            else cout<<sze;
        }
    }
    return 0;
}
