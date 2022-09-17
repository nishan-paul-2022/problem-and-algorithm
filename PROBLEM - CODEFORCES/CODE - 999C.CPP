#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    string s,t="";
    cin>>s;
    map<char,ll> m,p;
    map<char,ll>::iterator it;
    for(ll i=0; i<n; i++){
        m[s[i]]++;
        p[s[i]]++;
    }
    it=m.begin();
    while(k && it!=m.end()){
        if(k>=it->second){
            p[it->first]=0;
            k=k-it->second;
        }
        else{
            p[it->first]=(it->second)-k;
            k=0;
        }
        it++;
    }
    reverse(s.begin(),s.end());
    for(ll i=0; i<n; i++){
        if(p[s[i]]>0){
            t+=s[i];
            p[s[i]]--;
        }
    }
    reverse(t.begin(),t.end());
    cout<<t;
    return 0;
}
