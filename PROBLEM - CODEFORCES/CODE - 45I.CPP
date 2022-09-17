///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n, pos=0, neg=0, zro=0, cnt=0;
    cin>>n;
    ll a[n];
    vector<ll> v;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(a[i]<0) neg++;
        else if(a[i]>0) pos++;
        else if(a[i]==0) zro++;
    }
    sort(a,a+n);
    if(pos==0 && neg==0)
        cout<<0;
    else if(pos==0 && neg==1 && zro==0)
        cout<<a[0];
    else if(pos==0 && neg==1 && zro>0)
        cout<<0;
    else{
        neg = neg%2==0? neg:neg-1;
        for(ll i=0; i<n; i++){
            if(a[i]<0) cnt++;
            if( a[i]>0 || (a[i]<0 && cnt<=neg) )
                v.push_back(a[i]);
        }
        ll sze=v.size();
        if(sze==0)
            cout<<0;
        else{
            for(ll i=0; i<v.size(); i++)
                cout<<v[i]<<spc;
        }
    }
    return 0;
}

