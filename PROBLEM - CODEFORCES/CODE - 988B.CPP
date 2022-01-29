#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<string> v;
    multimap<ll,string> m;
    pair<ll,string> p;
    ll n,sze,tst=0;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        string s;
        cin>>s;
        p=make_pair(s.size(),s);
        m.insert(p);
    }
    multimap<ll,string>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
        v.push_back(it->second);
    sze=v.size();
    for(ll i=1; i<sze; i++)
        for(ll j=0; j<i; j++)
            if(v[i].find(v[j])==-1)
                tst++;
    if(tst)
        cout<<"NO";
    else{
        cout<<"YES"<<endl;
        multimap<ll,string>::iterator it;
        for(it=m.begin(); it!=m.end(); it++)
            cout<<it->second<<endl;
    }
    return 0;
}

