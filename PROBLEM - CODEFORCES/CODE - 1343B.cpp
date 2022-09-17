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
    while(test--) {
        ll n;
        cin>>n;
        ll m = n/2;
        if(m % 2) {
            cout<<"NO";
        }
        else {
            cout<<"YES"<<lne;
            for(ll i=2; i<=n; i+=2) {
                cout<<i<<spc;
            }
            for(ll i=1; i<n; i+=2) {
                if(i==n-1)
                    cout<<i+m<<spc;
                else
                    cout<<i<<spc;
            }
        }
        cout<<lne;
    }

    return 0;
}

