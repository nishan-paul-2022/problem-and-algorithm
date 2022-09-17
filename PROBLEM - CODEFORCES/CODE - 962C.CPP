#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll n,ans=0;
    cin>>n;
    string s=to_string(n);
    vector<string> v;
    ll sze=s.length();
    ll num=1<<sze;
    for(ll i=1; i<=num-1; i++){
        string tem="";
        for(ll j=0; j<sze; j++)
            if( (i>>j)&1 !=0 )
                tem+=s[j];
        v.push_back(tem);
    }
    ll lgt=v.size();
    for(ll i=0; i<lgt; i++)
        if(v[i][0]!='0')
        {
            ll val=stoi(v[i]);
            ll sq=sqrt(val);
            if(sq*sq==val)
                if(ans<v[i].length())
                    ans=v[i].length();
        }
    if(ans==0)
        cout<<-1;
    else
        cout<<sze-ans;
    return 0;
}
