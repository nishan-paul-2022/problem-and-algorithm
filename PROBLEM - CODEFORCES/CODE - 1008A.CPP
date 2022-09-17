#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll tst=0;
    string s;
    cin>>s;
    ll n=s.length();
    for(ll i=0; i<n; i++){
        if(i==n-1 && s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='n')
            tst=1;
        else if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='n')
            if(s[i+1]=='a'|| s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u');
            else tst=1;
    }
    if(tst==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
