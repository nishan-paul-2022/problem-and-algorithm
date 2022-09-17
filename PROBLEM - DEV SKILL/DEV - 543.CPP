#define ONLINE_JUDGE 1
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll T;
    cin>>T;
    while(T--){
        map<char,ll> m;
        ll n,cnt=0;
        string s;
        cin>>s>>n;
        ll lg=s.length();
        for(ll i=0; i<lg; i++){
            m[s[i]]++;
        }
        map<char,ll>::iterator it;
        for(it=m.begin(); it!=m.end(); it++){
            cnt+=it->second-1;
        }
        if(n>=cnt)
            cout<<"YES"<<lne;
        else if(n<cnt)
            cout<<"NO"<<lne;
    }
    return 0;
}
