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

ll gcdx(vector<ll> v) // N.LOG(min(A,B))
{
    ll sze=v.size();
    for(ll i=0; i<sze-1; i++)
        v[i+1] = gcd(v[i],v[i+1]);
    return v[sze-1];
}

ll lcm(ll a,ll b) // LOG(min(A,B))
{
    ll x=gcd(a,b);
    ll y=(a*b)/x;
    return y;
}

ll lcmx(vector<ll> v) // N.LOG(min(A,B))
{
    ll sze=v.size();
    for(ll i=0; i<sze-1; i++)
        v[i+1]=lcm(v[i],v[i+1]);
    return v[sze-1];
}

pair<ll,ll> euclid(ll a,ll b)                            // ax + by = gcd(a,b)
{                                                        // input:(a,b) output:(x,y)
    if(b==0)                                             // ( x, y ) == ( x+b, y-a ) == ( x-b, y+a )
        return pair<ll,ll>(1,0);                         // if a & b are co-prime, then
    pair<ll,ll> p=euclid(b,a%b);                         // (positive x % b) is mod inverse of 'a' with respect to b
    return pair<ll,ll>(p.second, p.first-p.second*(a/b));// (positive y % a) is mod inverse of 'b' with respect to a
}

int main()
{
//    inout
//    fileopen

    vector<ll> v = {15, 34, 45, 65, 12};
    cout << lcmx(v) << lne;

//    fileclose
    return 0;
}
