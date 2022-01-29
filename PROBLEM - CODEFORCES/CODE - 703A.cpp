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

int main()
{
    inout

    ll test;
    cin>>test;

    map<string,ll> m;
    m["Mishka"] = 0;
    m["Chris"] = 0;

    while(test--) {
        ll x,y;
        cin>>x>>y;
        
        if(x>y)
            m["Mishka"]++;
        else if(x<y)
            m["Chris"]++;
    }

    if( m["Mishka"]>m["Chris"] )
        cout<<"Mishka"<<lne;
    else if( m["Mishka"]<m["Chris"] )
        cout<<"Chris"<<lne;
    else
        cout<<"Friendship is magic!^^"<<lne;

    return 0;
}