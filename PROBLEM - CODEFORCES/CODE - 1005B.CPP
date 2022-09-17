#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    ll i, sze = min(s.length(),t.length());
    ll lgt = s.length()+t.length();
    for(i=0; i<sze && s[i]==t[i]; i++){

    }
    cout<<(lgt-2*i);
    return 0;
}
