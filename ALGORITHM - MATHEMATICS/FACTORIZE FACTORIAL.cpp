#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define ud unsigned double
#define gcd __gcd
#define countbit __builtin_popcount
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 29996224275833
#define PI acos(-1)
#define inf ULLONG_MAX
#define infp LLONG_MAX
#define infn LLONG_MIN
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("filec.txt");
//#define fileopen system("filea.txt"); system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
//#define fileclose fclose(my1); fclose(my2); system("filec.txt"); freopen("CON","w",stdout); string s1="filea.txt",s2="filec.txt"; char *name1=&s1[0], *name2=&s2[0]; FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");char c1(spc), c2(spc);if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; exit(0);} if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; exit(0);}ll ex=0, ey=0;while(c1!=EOF && c2!=EOF){c1=getc(f1); c2=getc(f2);if(c1==lne){ ex++; ey=0;}if(c1!=c2){cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;cout<<c1<<" INSTEAD of "<<c2<<lne;exit(0);}ey++;}fclose(f1); fclose(f2);cout<<"NO ERROR"<<lne;
#define fileopenX fileopen ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX } fileclose
using namespace std;

void sieve ( ll range, vector<ll> &prime ) // N.LOG(LOG(N)) [range>1]
{
    ll lmt = 1 + sqrt( range );
    vector<ll> v( 1 + range, 0 );
    prime.push_back( 2 );
    for( ll i = 3; i <= lmt; i += 2 ) {
        if( v[i]==0 ) {
            for( ll j = i*i; j <= range; j += 2*i ) {
                v[j] = 1;
            }
        }
    }
    for( ll i = 3; i <= range; i += 2 ) {
        if( v[i]==0 ) {
            prime.push_back( i );
        }
    }
}

map<ll,ll> factfact ( ll n )
{
    vector<ll> p = {2};
    sieve( n, p );
    ll sze = p.size();
    map<ll,ll> m;
    for( ll i=0; i < sze; i++ ) {
        ll ans = 0, t = 1;
        while( ( t *= p[i] ) <= n ) {
            ans += n/t;
        }
        m[ p[i] ] = ans;
    }
    return m;
}

int main()
{
//    inout
//    fileopen

    ll n;
    cin >> n;
    map<ll,ll> m = factfact ( n );
    map<ll,ll>::iterator it;
    for( it=m.begin(); it != m.end(); it++ ) {
        cout << it->ff << " : " << it->ss << lne;
    }

    //fileclose
    return 0;
}

