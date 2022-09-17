#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    string d,tail;
    cin>>d>>tail;
    string s="qwertyuiopasdfghjkl;zxcvbnm,./";
    ll lgt=s.length();
    map<char,char> lft,rht;
    for(ll i=1; i<lgt-1; i++){
        lft[s[i]]=s[i+1];
        rht[s[i]]=s[i-1];
    }
    lft[s[0]]=s[1];
    rht[s[lgt-1]]=s[lgt-2];
    lgt=tail.length();
    for(ll i=0; i<lgt; i++){
        if(d=="L")
            cout<<lft[tail[i]];
        else
            cout<<rht[tail[i]];
    }
    return 0;
}
