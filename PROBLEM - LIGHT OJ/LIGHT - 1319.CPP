///CUET-IRON-BAT
///"To Cut Down A Tree In Five Minutes, Spend Three Minutes Sharpening Your Axe"
///"A Master Has Failed More Times Than A Newbie Has Even Tried."
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvlit vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vulit vector<unsigned long long>::iterator
#define vdou vector<double>
#define vdouit vector<double>::iterator
#define vstr vector<string>
#define vstrit vector<string>::iterator
#define vbol vector<bool>
#define vbolit vector<bool>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vpllit vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsit vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpslit vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvpllit vector< vector< pair<long long,long long> > >::iterator
#define vomg vector<omg>
#define vomgit vector<omg>::iterator
#define vvomg vector< vector<omg> >
#define vvomgit vector< vector<omg> >::iterator
#define mll map<long long,long long>
#define mllit map<long long,long long>::iterator
#define msl map<string,long long>
#define mslit map<string,long long>::iterator
#define mls map<long long,string>
#define mlsit map<long long,string>::iterator
#define pushb push_back
#define pushf pop_front
#define popb pop_back
#define popf push_front
#define mpair make_pair
#define tostring to_string
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define mem(a,b) memset(a,b,sizeof(a))
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI acos(-1)
#define infp 9223372036854775807
#define infn -9223372036854775808
#define inf 18446744073709551615
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
///BINARY SEARCH (finding index, lower_bound, upper_bound for a given element)
template <class addrs, class T>
addrs binary(addrs first, addrs last, T val, ll &tst, ll &idx)///LOG(N)
{
    addrs it, bck=first;
    ll step, sze;
    step=sze=distance(first,last);
    while(step>0){
        it=first;
        step=step/2;
        advance(it,step);
        if(val>*it)
            first=it+1;
    }
    idx=distance(bck,first);
    if(idx==0 && *first!=val) tst=1;
    else if(idx==sze+1) tst=2;
    else if(*first==val) tst=3;
    else tst=4;
    return first;
}
///BISECTION METHOD (finding x for which the functional value of the given equation is y)
double fbisection(double mid){

}
double bisection(double x,double y,double gval){
    double mid, accuracy=0.00000001;
    while(y-x>accuracy){
        mid=(x+y)/2;
        double cval=fbisection(mid);
        if(cval<gval) x=mid;
        else if(cval>gval) y=mid;
        else if(cval==gval) break;
    }
    return mid;
}
///TERNARY SEARCH (finding x for which the functional value of the given equation is max/min)
double fternary(double mid){

}
double ternary(double x,double y){
    double m1,m2, accuracy=0.00000001;
    while(y-x>accuracy){
        m1=x+(y-x)/3;
        m2=x+2*(y-x)/3;
        double vm1=fternary(m1), vm2=fternary(m2);
        if(vm1<vm2) y=m2;
        else if(vm1>vm2) x=m1;
    }
    return y;
}
inline void sieve(ll range,vector<ll> &all,vector<ll> &prime){///N.LOG(LOG(N)) ///range>1
    ll lmt=1+sqrt(range);
    vector<ll> v(1+range,0);
    prime.push_back(2);
    for(ll i=3; i<=lmt; i+=2)
        if(v[i]==0)
            for(ll j=i*i; j<=range; j+=2*i)
                v[j]=1;
    all=v;
    for(ll i=3; i<=range; i+=2)
        if(all[i]==0)
            prime.push_back(i);
}
inline void bit_sieve(ll range,vector<ll> &all,vector<ll> &prime){///N.LOG(LOG(N)) ///range>1
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
                v[x] = v[x]|(1<<y);
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
inline void seg_sieve(ll a,ll b,vector<bool> &all,vector<ll> &prime){///(B-A).LOG(LOG(B-A)) ///a<=b && a>1 && b>1
    ll range=sqrt(b);
    vector<ll> all01, prime01;
    sieve(range,all01,prime01);
    vector<bool> v(b-a+1,true);
    ll sze=prime01.size();
    for(ll i=0; i<sze; i++){
        ll tem=a/prime01[i];
        if(a%prime01[i]!=0) tem++;
        if(tem==1) tem++;
        for(ll j=tem*prime01[i]; j<=b; j+=prime01[i])
            v[j-a]=false;
    }
    all=v;
    for(ll i=0; i<=b-a; i++)
        if(all[i]==true)
            prime.push_back(i+a);
}
inline void factor(ll value,vector< pair<ll,ll> > &v){/// N.LOG(LOG(N))
    ll i,index;
    index=1+sqrt(value);
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
bool pripat(ll n){/// SQRT(N)/6
    if(n==2 || n==3) return true;
    else if(n==1 || n%2==0 || n%3==0) return false;
    ll p=1+sqrt(n);
    for(ll i=5; i<=p; i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}
inline void totient(ll n,ll &cnt,vector<bool> &v){/// N.LOG(LOG(N))
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
inline vector<ll> serial_totient(ll n){/// N
    vector<ll> v;
    for(ll i=0; i<=n; i++)
        v.push_back(i);
    for(ll i=2; i<=n; i++)
        if(v[i]==i)
            for(ll j=i; j<=n; j+=i)
                v[j] = v[j]-v[j]/i;
    return v;
}
inline bool coprime(ll a,ll b){/// N.LOG(LOG(N))
    while(b){
        ll mid=a;
        a=b;
        b=mid%b;
    }
    return a==1;
}
inline ll pwr(ll base,ll n){/// LOG(N)
    if(n==0) return 1;
    ll x = pwr(base,n/2);
    ll y = x*x;
    if(n%2) y = y*base;
    return y;
}
inline ll modpwr(ll base,ll n,ll m=mod){/// LOG(N)
    if(n==0) return 1;
    ll x = modpwr(base,n/2,m);
    ll y = (x*x) % m;
    if(n%2) y = ( y * (base%m) ) % m;
    return y;
}
inline ll modinverse(ll b,ll m,ll flag){/// N.LOG(LOG(N))
    if(flag==0) return modpwr(b,m-2,m);
    else if( flag==1 || (flag==2 && coprime(b,m)==true) ){
        ll cnt;
        vector<bool> v;
        totient(m,cnt,v);
        return modpwr(b,cnt-1,m);
    }
    return -1; // 1/B MOD M does not exist
}
inline ll CRT(vector<ll> m,vector<ll> r,ll flag=2){/// k.N.LOG(LOG(N))
    ll sze=m.size(), mul=1, ans=0;
    for(ll i=0; i<sze; i++) mul*=m[i];
    for(ll i=0; i<sze; i++){
        ll x=mul/m[i];
        ll y=modinverse(x,m[i],flag);
        if(y<0) return -1; // ANSWER DOESN'T EXIST
        ans += (x*y*r[i]);
    }
    ans %= mul;
    return ans;
}
inline ll modn(ll a,ll m=mod) { return ((a%m)+m)%m; }
inline ll modmul(ll a,ll b,ll m=mod) { return (modn(a)*modn(b))%m; }
inline ll moddiv(ll a,ll b,ll m=mod) { return (modn(a)*modinverse(b,m,true))%m; }
inline vector<ll> single_divisor(ll n){/// SQRT(N)
    vector<ll> v;
    ll range=1+sqrt(n);
    for(ll i=1; i<=range; i++){
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    return v;
}
inline vector< vector<ll> > all_divisor(ll n){/// N.LOG(N)
    vector< vector<ll> > v(n+1);
    for(ll i=1; i<=n; i++)
        for(ll j=i; j<=n; j+=i)
            v[j].push_back(i);
    return v;
}
class omg{ public: ll x,y,z; omg(){} omg(ll a,ll b,ll c){ x=a,y=b,z=c;} };
inline vector< vector<omg> > prime_divisor(ll n){/// N.LOG(N)
    vector<ll> all,prime;
    sieve(n,all,prime);
    ll sze=prime.size();
    vector< vector<omg> > v(n+1);
    for(ll i=0; i<sze; i++)
        for(ll j=prime[i]; j<=n; j+=prime[i]){
            ll k, mul=1, jx=j;
            for(k=0; jx%prime[i]==0; k++){
                jx/=prime[i];
                mul*=prime[i];
            }
            omg D(prime[i],k,mul);
            v[j].push_back(D);
        }
    return v;
}
inline ll sumOFdivisor(vector< pair<ll,ll> > v){/// NUMBER OF DIVISOR
    ll sze=v.size(), ans=1;
    for(ll i=0; i<sze; i++){
        ll p=v[i].first, q=v[i].second;
        ans = modmul( ans, moddiv( modn( modpwr(p,q+1), -1 ), p-1 ) );
    }
    return ans;
}
inline ll gcd(ll a,ll b){ return b==0? a:gcd(b,a%b);}
inline ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
inline ll gcdx(vector<ll> v){/// N.LOG(min(A,B))
    ll sze=v.size();
    for(ll i=0; i<sze-1; i++)
        v[i+1] = gcd(v[i],v[i+1]);
    return v[sze-1];
}
inline ll lcmx(vector<ll> v){/// N.LOG(min(A,B))
    ll sze=v.size();
    for(ll i=0; i<sze-1; i++)
        v[i+1]=lcm(v[i],v[i+1]);
    return v[sze-1];
}
inline pair<ll,ll> euclid(ll a,ll b)                       /// ax + by = gcd(a,b)
{                                                          /// input:(a,b) output:(x,y)
    if(b==0)                                               /// ( x, y ) == ( x+b, y-a ) == ( x-b, y+a )
        return pair<ll,ll>(1,0);                           /// if a & b are co-prime, then
    pair<ll,ll> p=euclid(b,a%b);                           /// (positive x % b) is mod inverse of a with respect to b
    return pair<ll,ll>( p.second, p.first-p.second*(a/b) );/// (positive y % a) is mod inverse of b with respect to a
}
inline vector<ll> prefactorial(ll n){/// N
    vector<ll> v(1+n);
    v[0]=1;
    for(ll i=1; i<=n; i++)
        v[i]=i*v[i-1];
    return v;
}
inline bool isLeap(ll y){ return ((y%4==0 && y%100!=0) || y%400==0);}

inline ll top(ll x,ll y) { return x%y? 1+x/y:x/y;}
inline ll down(ll x,ll y){ return x/y;}

inline ll fndnbit(ll n,ll i){ return n&((1<<i)-1); }
inline ll fndbit(ll n,ll i) { return n&(1<<(i-1)); }
inline ll swcbit(ll n,ll i) { return n^(1<<(i-1)); }
inline ll sonbit(ll n,ll i) { return n|(1<<(i-1)); }
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll cs=1; cs<=tst; cs++){
        ll n,L=0, x,y;
        cin>>n;
        vl m,r;
        for(ll i=0; i<n; i++){
            cin>>x>>y;
            m.pushb(x), r.pushb(y);
        }
        cout<<"Case "<<cs<<": "<<CRT(m,r,0)<<lne;
    }
//    fileclose
    return 0;
}
