#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
gcd_calcu(ll a1,ll b1)/// LOG(A+B)
{
    ll a,b;
    a=max(a1,b1);
    b=min(a1,b1);
    if(b==0) return a;
    else gcd_calcu(b,a%b);
}
int main()
{
    ll l,r,x,y,sum=0;
    cin>>l>>r>>x>>y;
    ll mul=x*y;
    vector< pair<ll,ll> > v;
    if(y%x!=0)
        cout<<0;
    else if(y==x){
        if(x>=l && x<=r) cout<<1;
        else cout<<0;
    }
    else if(y%x==0){
        for(ll i=1; i*i<=y/x; i++)
            if((y/x)%i==0)
                v.push_back( make_pair(i*x,y/i) );
        for(auto i:v)
            if( i.first>=l && i.second<=r && gcd_calcu(i.first,i.second)==x )
                sum++;
        cout<<2*sum;
    }
    return 0;
}
