#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,cnt=0;
    cin>>n;
    ll a[n];
    map<ll,ll> m;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        m[a[i]]++;
    }
    if(n==1) cout<<1;
    else{
        for(ll i=0; i<n; i++){
            ll val=a[i], tst=0;
            ll start=floor(log(val)/log(2));
            ll two;
            for(ll i=start+1; i<=31; i++){
                two=abs(val-pow(2,i));
                if( (two==val && m[two]>1)||(two!=val && m[two]>0) )
                    tst++;
            }
            if(tst==0) cnt++;
        }
        cout<<cnt;
    }
    return 0;
}

