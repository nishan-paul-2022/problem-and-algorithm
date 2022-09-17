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

int main()
{
    inout

    ll n;
    cin>>n;

    ll a[n], b[4];
    fill(b, b+4, 0);

    for(ll i=0; i<n; i++) {
        cin>>a[i];
        b[a[i]]++;
    }

    ll team = min( min(b[1], b[2]), b[3] );
    ll p[4][team], c[4];
    fill(c, c+4, 0);

    for(ll i=0; i<n; i++) {
        ll x = a[i];
        if( c[x] < team ) {
            ll y = c[x];
            p[x][y] = i+1;
            c[x]++;
        }
    }

    cout<<team<<lne;
    for(ll i=0; i<team; i++) {
        cout<<p[1][i]<<spc<<p[2][i]<<spc<<p[3][i]<<lne;
    }

    return 0;
}