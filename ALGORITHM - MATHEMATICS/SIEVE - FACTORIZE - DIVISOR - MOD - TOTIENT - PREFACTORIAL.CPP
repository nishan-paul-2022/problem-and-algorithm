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

class triple{ public: ll x,y,z; triple(){} triple(ll a,ll b,ll c){ x=a,y=b,z=c;} };

void sieve(ll range,vector<ll> &all,vector<ll> &prime) // N.LOG(LOG(N)) [range>1]
{
    ll lmt=1+sqrt(range);
    vector<ll> v(1+range,0);
    prime.push_back(2);
    for(ll i=3; i<=lmt; i+=2){
        if(v[i]==0){
            for(ll j=i*i; j<=range; j+=2*i){
                v[j]=1;
            }
        }
    }
    all=v;
    for(ll i=3; i<=range; i+=2){
        if(all[i]==0)
            prime.push_back(i);
    }
}

void bit_sieve(ll range,vector<ll> &all,vector<ll> &prime) // N.LOG(LOG(N)) [range>1]
{
    ll lmt=1+sqrt(range);
    vector<ll> v(1+range/32,0);
    prime.push_back(2);
    for(ll i=3; i<=lmt; i+=2){
        ll idx=i/32;
        ll n=i%32;
        if( (v[idx] & 1<<n)==0 ){
            for(ll j=i*i; j<=range; j+=2*i){
                ll x=j/32;
                ll y=j%32;
                v[x] = v[x] | 1<<y;
            }
        }
    }
    all=v;
    for(ll i=3; i<=range; i+=2){
        ll idx=i/32;
        ll n=i%32;
        if( (all[idx] & 1<<n)==0 )
            prime.push_back(i);
    }
}

void seg_sieve(ll a,ll b,vector<ll> &all,vector<ll> &prime)// (B-A).LOG(LOG(B-A)) [a<=b && a>1 && b>1]
{
    ll range=sqrt(b);
    vector<ll> v(b-a+1,0), all01, prime01;
    sieve(range,all01,prime01);
    ll sze=prime01.size();
    for(ll i=0; i<sze; i++) {
        ll tem=a/prime01[i];
        if(a%prime01[i]!=0) tem++;
        if(tem==1) tem++;
        for(ll j=tem*prime01[i]; j<=b; j+=prime01[i])
            v[j-a]=1;
    }
    all=v;
    for(ll i=0; i<=b-a; i++)
        if(all[i]==0)
            prime.push_back(i+a);
}

void factor(ll value,vector< pair<ll,ll> > &v)// N.LOG(LOG(N))
{
    ll index=1+sqrt(value);
    vector<ll> all,prime;
    sieve(index,all,prime);
    ll n=value, sze=prime.size();
    for (ll i=0; i<sze; i++){
        ll j, val=prime[i];
        for(j=0; n%val==0; j++)
            n=n/val;
        if(j) v.push_back( make_pair(val,j) );
    }
    if(n!=1) v.push_back( make_pair(n,1) );
}

void totient(ll n,ll &cnt,vector<bool> &v) // N.LOG(LOG(N))
{
    vector< pair<ll,ll> > p;
    factor(n,p);
    vector<bool> tem(1+n,true);
    ll sze=p.size();
    cnt=n;
    for(ll i=0; i<sze; i++){
        ll x=p[i].first;
        cnt = cnt-cnt/x;
        for(ll j=x; j<=n; j+=x)
            tem[j]=false;
    }
    v=tem;
}

vector<ll> serial_totient(ll n) // N
{
    vector<ll> v;
    for(ll i=0; i<=n; i++)
        v.push_back(i);
    for(ll i=2; i<=n; i++)
        if(v[i]==i)
            for(ll j=i; j<=n; j+=i)
                v[j] = v[j]-v[j]/i;
    return v;
}

bool coprime(ll a,ll b)
{
    while(b){
        ll mid=a;
        a=b;
        b=mid%b;
    }
    return a==1;
}

ll pwr(ll base,ll n) // LOG(N)
{
    if(n==0) return 1;
    ll x = pwr(base,n/2);
    ll y = x*x;
    if(n%2) y = y*base;
    return y;
}

ll modpwr(ll base,ll n,ll m=mod) // LOG(N)
{
    if(n==0) return 1;
    ll x = modpwr(base,n/2,m);
    ll y = (x*x) % m;
    if(n%2) y = (y*base) % m;
    return y;
}

ll modinverse(ll b,ll m,ll flag) // N.LOG(LOG(N))
{
    if(flag==0)
        return modpwr(b,m-2,m);
    else if( flag==1 || (flag==2 && coprime(b,m)==true) )
    {
        ll cnt;
        vector<bool> v;
        totient(m,cnt,v);
        return modpwr(b,cnt-1,m);
    }
    return -1; // 1/B MOD M does not exist
}

ll CRT(vector<ll> m,vector<ll> r,ll flag=2) // k.N.LOG(LOG(N))
{
    ll sze=m.size(), mul=1, ans=0;
    for(ll i=0; i<sze; i++)
        mul *= m[i];
    for(ll i=0; i<sze; i++){
        ll x = mul/m[i];
        ll y = modinverse(x,m[i],flag);
        if(y<0)
            return -1; // ANSWER DOESN'T EXIST
        ans += (x*y*r[i]);
    }
    ans %= mul;
    return ans;
}

ll modn(ll a,ll m=mod)
{
    ll ans=a%m;
    if(ans<0) ans+=m;
    return ans;
}

ll modmul(ll a,ll b,ll m=mod)
{
    ll x=modn(a), y=modn(b);
    ll ans=(x*y)%m;
    return ans;
}

ll moddiv(ll a,ll b,ll m=mod)
{
    ll x=modn(a);
    ll y=modinverse(b,m,true);
    ll z=(x*y)%m;
    return z;
}

vector<ll> divisor(ll n)// SQRT(N)
{
    vector<ll> v;
    ll range = n==2? 1:sqrt(n);
    for(ll i=1; i<=range; i++){
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    return v;
}

vector< vector<ll> > serial_divisor(ll n)// N.LOG(N)
{
    vector< vector<ll> > v(n+1);
    for(ll i=1; i<=n; i++)
        for(ll j=i; j<=n; j+=i)
            v[j].push_back(i);
    return v;
}

inline vector< vector<triple> > prime_divisor(ll n)// N.LOG(N)
{
    vector<ll> all,prime;
    sieve(n,all,prime);
    ll sze=prime.size();
    vector< vector<triple> > v(n+1);
    for(ll i=0; i<sze; i++)
    {
        for(ll j=prime[i]; j<=n; j+=prime[i])
        {
            ll k, mul=1, jx=j;
            for(k=0; jx%prime[i]==0; k++)
            {
                jx/=prime[i];
                mul*=prime[i];
            }
            triple D(prime[i],k,mul);
            v[j].push_back(D);
        }
    }
    return v;
}

ll sumOFdivisor(vector< pair<ll,ll> > v)// NUMBER OF DIVISOR
{
    ll sze=v.size(), ans=1;
    for(ll i=0; i<sze; i++){
        ll p=v[i].first, q=v[i].second;
        ans = modmul( ans, moddiv( modn( modpwr(p,q+1), -1 ), p-1 ) );
    }
    return ans;
}

vector<ll> prefactorial(ll n)// N
{
    vector<ll> v(1+n);
    v[0]=1;
    for(ll i=1; i<=n; i++)
        v[i] = i*v[i-1];
    return v;
}

int main()
{
//    inout
//    fileopen

//    fileclose
    return 0;
}
/*
NUMBER
	n = (p1^a1)* (p2^a2)
		number of divisor = (a1+1)*(a2+1)
		sum of divisor = (p1^0 + p1^1 + p1^2 +. . . + p1^a1) * (p2^0 + p2^1 + p2^2 +. . . + p2^a2)
	a+(a+r)+(a+2*r)+(a+3*r)+. . . .+p
		sum = n/2 * (a+p)
	1 + r + r^2 + r^3 + r^4 + . . . . . + r^n
		sum = (r^(n+1) – 1 ) / (r-1)

TOTIENT
	• if x & y have no common divisor except 1, they’re called coprime.
	• if x==y then they are not coprime at all.
	• 1 is coprime of every single natural number including itself.
	• Ø(n) means number of coprimes of natural number n from 1 to n
		n = p1^a1 * p2^a2 * p3^a3
		∴ Ø(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)
	• if p is prime, then Ø( p ) == p-1 and Ø( p^n ) == p^n – p^(n-1)
	• if x & y are coprime, x^( Ø(y) ) == 1 mod y

INVERSE MOD
		b mod m (done)
		b^n mod m (done)
		1/b mod m (WTF?)
	for example, (a/b) mod m == (a mod m) * (1/b mod m)
	let, 1/b mod m == x
	the significance of this line is that, bx mod m == 1
	here, b & m must be coprime (if not then x does not exist)
	as we all know, if b & m are coprime then, b^Ø(m) == 1 mod m
	let Ø(m) == n
	∴ b^n == 1 mod m
	∴ b^(n-1) == 1/b mod m
    so we just have to determine b^(n-1) mod m
*/
