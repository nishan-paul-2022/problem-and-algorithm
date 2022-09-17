///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define ud unsigned double
#define gcd __gcd
#define countbit __builtin_popcountll
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 29996224275833
#define PI acos(-1)
#define inf  ULLONG_MAX
#define infp LLONG_MAX
#define infn LLONG_MIN
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

ll f(ll n, ll a, ll b, ll c, ll *p) {
    if(n<0)
        return infn;
    else if(n==0)
        return 0;
    else if(p[n]!=-1)
        return p[n];
    else {
        ll x = 1 + f(n-a, a, b, c, p);
        ll y = 1 + f(n-b, a, b, c, p);
        ll z = 1 + f(n-c, a, b, c, p);
        p[n] = max( max(x,y), z );
        return p[n];
    }
}

int main()
{
    inout

    ll n, a, b, c;
    cin>>n>>a>>b>>c;

    ll p[n+1];
    for(ll i=0; i<=n; i++) {
        p[i] = -1;
    }

    cout<<f(n,a,b,c,p);

    return 0;
}


