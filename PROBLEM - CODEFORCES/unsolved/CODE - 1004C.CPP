#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,tst=0,sum=0;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    map<ll,ll> m,g,h;
    set<ll> s,t;
    for(ll i=0; i<n; i++){
        m[a[i]]++;
        if(m[a[i]]==1 && tst==0)
            s.insert(a[i]);

        else if(m[a[i]]!=1)
            tst=1;
        if(tst==1)
            t.insert(a[i]);
    }
    sum += (s.size())*(t.size());

    return 0;
}
