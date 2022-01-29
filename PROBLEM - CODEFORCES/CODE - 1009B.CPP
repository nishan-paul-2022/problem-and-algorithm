#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    map<char,ll> m;
    vector<ll> v;
    string s,t="";
    cin>>s;
    ll sze=s.length();
    ll idx=sze, zro=0;
    for(ll i=0; i<sze; i++){
        m[s[i]]++;
        if(s[i]=='2') v.push_back(i);
    }
    if(v.size()!=0){
        v.push_back(sze-1);
        for(ll i=0; i<v[0]; i++)
            if(s[i]=='0') t+="0";
        for(ll i=0; i<m['1']; i++)
            t+="1";
        for(ll i=1; i<v.size(); i++){
            t+="2";
            for(ll j=v[i-1]; j<=v[i]; j++)
                if(s[j]=='0') t+="0";
        }
    }
    else{
        for(ll i=0; i<m['0']; i++)
            t+="0";
        for(ll i=0; i<m['1']; i++)
            t+="1";
    }
    cout<<t;
    return 0;
}
