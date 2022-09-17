#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll i;
    string s;
    cin>>s;
    for(i=0; s.length()>1; i++){
        ll sze=s.length();
        ll sum=0;
        for(ll j=0; j<sze; j++)
            sum+=(s[j]-'0');
        s=to_string(sum);
    }
    cout<<i<<lne;
    return 0;
}
