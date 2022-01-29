///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    double v, ans=0, sum=0, rat=0, cat, bat;
    ll n;
    cin>>n>>v;
    ll a[n], b[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
        rat+=a[i];
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
        sum+=b[i];
    }
    sum=min(sum,v);
//    cout<<sum<<lne;
    bat=sum/rat;
//    cout<<bat<<lne;
    for(ll i=0; i<n; i++){
        double d=a[i]*bat;
        if(d>b[i]){
            cat=(double)b[i]/a[i];
            bat=min(bat,cat);
//            cout<<bat<<lne;
        }
    }
    for(ll i=0; i<n; i++){
        ans+=(a[i]*bat);
    }
    cout<<setprecision(15)<<ans;
    return 0;
}

