///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll x,y,tem,val,ans=1;
    cin>>x>>y;
    if(x<=2){
        tem=log(y)/log(2);
        if(tem>1) val=pow(2,tem);
        else val=2;
        ans*=val;
        x=3;
    }
    ll y1=1+sqrt(y);
    ll x1=1+sqrt(y1);
    vector<ll> v(y-x+1,true), v1(y1,true);
    for(ll i=3; i<=x1; i+=2){
        if(v1[i]==true){
            for(ll j=i*i; j<=y1; j+=2*i)
                v1[j]=false;
        }
    }
    for(ll i=3; i<=y1; i+=2){
        if(v1[i]==true){
            ll a=x/i;
            if(x%i) a++;
            if(a==1) a++;
            if((a*i)%2==0) a++;
            for(ll j=a*i; j<=y; j+=2*i)
                v[j-x]=false;
        }
    }
    ll a = x%2==0? x+1:x;
    for(ll i=a; i<=y; i+=2){
        if(v[i-x]==true){
            tem=log(y)/log(i);
            if(tem>1) val=pow(i,tem);
            else val=i;
            ans*=val;
        }
    }
    cout<<ans<<lne;
    return 0;
}

///CUET_IRON_BAT
//#include<bits/stdc++.h>
//#define ll long long
//#define lne '\n'
//#define spc ' '
//using namespace std;
//ll lcm(ll a,ll b){
//    ll c=a*b;
//    while(b){
//        ll tem=b;
//        b=a%b;
//        a=tem;
//    }
//    return c/a;
//}
//int main()
//{
//    ll x,y,val;
//    cin>>x>>y;
//    val=x;
//    for(ll i=x+1; i<=y; i++){
//        val=lcm(val,i);
//    }
//    cout<<val;
//    return 0;
//}
