#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
vector<ll> sieve(ll n){
    vector<ll> prime, v(n+1,0);
    prime.push_back(2);
    ll a=1+sqrt(n);
    for(ll i=3; i<=a; i+=2){
        if(v[i]==0){
            for(ll j=3*i; j<=n; j=j+2*i){
                v[j]++;
            }
        }
    }
    for(ll i=3; i<=n; i+=2){
        if(v[i]==0){
//            cout<<i<<lne;
            prime.push_back(i);
        }
    }
    return prime;
}
int main()
{
    ll n,cnt=0;
    cin>>n;
    if(n<=3)
        cout<<1<<lne<<0;
    else{
        map<ll,ll> m;
        ll a=1+sqrt(n);
        vector<ll> v=sieve(a);
        ll sze=v.size(), cnt=0, ans=1;
        for(ll i=0; i<sze && cnt<2; i++){
            while(n%v[i]==0 && cnt<2){
                cnt++;
                n=n/v[i];
                ans*=v[i];
            }
        }
//        cout<<n<<spc<<cnt<<lne;
        if(cnt==0)
            cout<<1<<lne<<0;
        else{
            if(n!=1)
                cnt++;
            if(cnt==2)
                cout<<2;
            else if(cnt==3)
                cout<<1<<lne<<ans;
        }
    }
    return 0;
}
