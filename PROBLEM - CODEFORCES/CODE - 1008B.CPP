#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,x,y,mx,mn,tst=0;
    cin>>n;
    pair<ll,ll> p[n];
    for(ll i=0; i<n; i++){
        cin>>x>>y;
        p[i]=make_pair(x,y);
    }
    vector<ll> v;
    for(ll i=0; i<n; i++){
        if(i==0)
            v.push_back( max(p[i].first,p[i].second) );
        else{
            if( v[i-1]<min(p[i].first,p[i].second) ){
                tst=1;
                break;
            }
            else if( v[i-1]>=max(p[i].first,p[i].second) )
                v.push_back( max(p[i].first,p[i].second) );
            else
                v.push_back( min(p[i].first,p[i].second) );
        }
    }
    if(tst==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
