///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n, sum=0;
    cin>>n;
    map<ll,ll> m;
    for(ll i=0; i<n; i++){
        ll tem;
        cin>>tem;
        m[tem]++;
    }
    if(m.size()<=2)
        cout<<0;
    else{
        map<ll,ll>::iterator it=m.begin(), jt=m.end();
        it++, jt--;
        while(it!=jt){
            sum+=it->second;
            it++;
        }
        cout<<sum;
    }
    return 0;
}

