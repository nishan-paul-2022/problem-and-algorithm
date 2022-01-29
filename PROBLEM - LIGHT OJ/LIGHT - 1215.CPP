///CUET-IRON-BAT
///"To Cut Down A Tree In Five Minutes, Spend Three Minutes Sharpening Your Axe"
///"A Master Has Failed More Times Than A Newbie Has Even Tried."
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vlvl vector< vector<long long> >
#define vlvlit vector< vector<long long> >::iterator
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
#define mll map<long long,long long>
#define mllit map<long long,long long>::iterator
#define msl map<string,long long>
#define msl map<string,long long>::iterator
#define mls map<long long,string>
#define mls map<long long,string>::iterator
#define pback push_back
#define mpair make_pair
#define sqr(n) n*n
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define coutt(t) cout<<"Case "<<t<<":"
#define coutw(m) cout<<fixed<<setw(m)
#define coutp(n) cout<<fixed<<setprecision(n)
#define couts(m,n) cout<<fixed<<setw(m)<<setprecision(n)
#define forl(i,x,y,z) for(i=x; i<y; i+=z)
#define forg(i,x,y,z) for(i=x; i>y; i-=z)
#define forit(it,m) for(it=m.begin(); it!=m.end(); it++)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI 3.141592653589793
#define pos 9223372036854775807
#define neg -9223372036854775808
#define inf 18446744073709551615
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
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
inline void make_factor(ll value,vector< pair<ll,ll> > &v){/// N.LOG(LOG(N))
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
inline void remainder(string s,ll n,string &t,ll &r){///FIND_REMAINDER_FOR_A_NUMBER (and also quotient)
    t="", r=0;
    ll sze=s.size();
    for(ll i=0; i<sze; i++){
        ll a=10*r+(s[i]-'0');
        ll b=a/n;
        r=a%n;
        if(b) t+=to_string(b);
    }
}
inline void totient(ll n,ll &cnt,vector<bool> &v){/// N.LOG(LOG(N))
    vector< pair<ll,ll> > p;
    make_factor(n,p);
    vector<bool> tem(1+n,true);
    ll sze=p.size();
    cnt=n;
    for(ll i=0; i<sze; i++){
        ll x=p[i].ff;
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
    ll x=max(a,b), y=min(a,b), cnt;
    vector<bool> v;
    totient(x,cnt,v);
    return v[y];
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
inline ll modinverse(ll b,ll m,bool flag=false){/// N.LOG(LOG(N))
    if(flag==true) return modpwr(b,m-2,m);
    else{
        if(coprime(b,m)==false) return -1; //1/B MOD M does not exist
        else{
            ll cnt;
            vector<bool> v;
            totient(m,cnt,v);
            ll val=modpwr(b,cnt-1,m);
            return val;
        }
    }
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
inline vector< vector<ll> > prime_divisor(ll n){/// N.LOG(N)
    vector<ll> all,prime;
    sieve(n/2,all,prime);
    ll sze=prime.size();
    vector< vector<ll> > v(n+1);
    v[0].push_back(0), v[1].push_back(1);
    for(ll i=0; i<sze; i++)
        for(ll j=prime[i]; j<=n; j+=prime[i])
            v[j].push_back(prime[i]);
    return v;
}
inline ll sum_divisor(vector< pair<ll,ll> > v){
    ll sze=v.size(), ans=1;
    for(ll i=0; i<sze; i++){
        ll p=v[i].ff, q=v[i].ss;
        ans = modmul( ans, moddiv( modn( modpwr(p,q+1), -1 ), p-1 ) );
    }
    return ans;
}
inline ll gcd(ll a,ll b){/// LOG(min(A,B))
    if(b==0) return a;
    else return gcd(b,a%b);
}
inline ll gcdx(vector<ll> v){/// N.LOG(min(A,B))
    ll len=v.size();
    for(ll i=0; i<len-1; i++)
        v[i+1] = gcd(v[i],v[i+1]);
    return v[len-1];
}
inline ll lcm(ll a,ll b){/// LOG(min(A,B))
    ll x=gcd(a,b);
    ll y=(a*b)/x;
    return y;
}
inline ll lcmx(vector<ll> v){/// N.LOG(min(A,B))
    ll len=v.size();
    for(ll i=0; i<len-1; i++)
        v[i+1]=lcm(v[i],v[i+1]);
    return v[len-1];
}
inline pair<ll,ll> euclid(ll a,ll b)                       /// ax + by = gcd(a,b)
{                                                          /// input:(a,b) output:(x,y)
    if(b==0)                                               /// ( x, y ) == ( x+b, y-a ) == ( x-b, y+a )
        return pair<ll,ll>(1,0);                           /// if a & b are co-prime, then
    pair<ll,ll> p=euclid(b,a%b);                           /// (positive x % b) is mod inverse of a with respect to b
    return pair<ll,ll>( p.ss, p.ff-p.ss*(a/b) );        /// (positive y % a) is mod inverse of b with respect to a
}
inline vector<ll> prefactorial(ll n){
    vector<ll> v(1+n);
    v[0]=1;
    for(ll i=1; i<=n; i++)
        v[i]=i*v[i-1];
    return v;
}
inline string small(string s){
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='A' && s[i]<='B')
            s[i]+=32;
    return s;
}
inline string capital(string s){
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='a' && s[i]<='b')
            s[i]-=32;
    return s;
}
inline map<string,ll> word(string s,ll &cnt){
    ll sze=s.size();
    map<string,ll> m;
    string t="";
    for(ll i=0; i<=sze; i++){
        if(i==sze || s[i]==32){
            m[t]++;
            cnt++;
            t="";
        }
        else t+=s[i];
    }
    return m;
}
inline vector<string> permu(string s){/// N!.N.LOG(N)
    ll sze=s.size(), ans[sze+1], x,y,z;
    ans[0]=1;
    for(ll i=1; i<=sze; i++)
        ans[i]=i*ans[i-1];
    map<char,ll> m;
    for(ll i=0; i<sze; i++)
        m[s[i]]++;
    for(map<char,ll>::iterator it=m.begin(); it!=m.end(); it++)
        if(it->ss>1) ans[sze]/=it->ss;
    vector<string> v;
    sort(s.begin(),s.end());
    v.push_back(s);
    for(ll i=1; i<ans[sze]; i++){
        ll j,idx=-1;
        for(j=sze-2; j>=0; j--){
            if(s[j]<s[j+1])
                break;
        }
        for(ll k=j+1; k<sze; k++){
            if(s[j]<s[k]){
                if(idx==-1) idx=k;
                else idx= s[k]<s[idx]?k:idx;
            }
        }
        swap(s[j],s[idx]);
        sort(s.begin()+j+1,s.end());
        v.push_back(s);
    }
    return v;
}
inline void subsequence(string s, vector<string> &v, map<ll,vector<string>> &m){/// LENGTH.(2^LENGTH)
    ll sze=s.length();
    ll num=1<<sze;
    for(ll i=1; i<=num-1; i++){
        string tem="";
        ll val=i, j=0;
        while(val){
            if(val%2 != 0) tem+=s[j];
            val/=2;
            j++;
        }
        v.push_back(tem);
    }
    sort(v.begin(),v.end());
    for(auto i:v)
        m[i.length()].push_back(i);
}
inline vector<string> substring(string s){/// N^2
    vector<string> v;
    vector<string>::iterator it;
    ll sze=s.size(), k=1, ans=0;
    for(ll i=sze; i>=1; i--){
        for(ll j=0; j<k; j++){
            string tem=s.substr(j,i);
//            it=find(v.begin(),v.end(),tem);
//            if(it==v.end())
                v.push_back(tem);
        }
        k++;
    }
    return v;
}
inline bool pripat(ll n){
    if(n==2 || n==3) return true;
    else if(n==1 || n%2==0 || n%3==0) return false;
    ll p=1+sqrt(n);
    for(ll i=5; i<=p; i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}
inline ll fndnbit(ll n,ll i){ return n&((1<<i)-1); }
inline ll fndbit(ll n,ll i) { return n&(1<<(i-1)); }
inline ll swcbit(ll n,ll i) { return n^(1<<(i-1)); }
inline ll sonbit(ll n,ll i) { return n|(1<<(i-1)); }
int main()
{
//    inout
//    fileopen
    ll range=1000000;
    vl all,prime;
    sieve(range,all,prime);
    ll sze=prime.size();

    ll tst, t;
    cin>>tst;
    forl(t,1,tst+1,1){
        ll a,b,L, ans=1;
        cin>>a>>b>>L;
        if(L%a || L%b)
            coutt(t)<<spc<<"impossible"<<lne;
        else{
            ll lmt=sqrt(L);
            for(ll i=0; i<sze && prime[i]<=lmt; i++){
                ll ca=0, cb=0, cL=0, j;
                while(L%prime[i]==0){
                    cL++;
                    L/=prime[i];
                }
                while(a%prime[i]==0){
                    ca++;
                    a/=prime[i];
                }
                while(b%prime[i]==0){
                    cb++;
                    b/=prime[i];
                }
                if(max(ca,cb)<cL)
                    forl(j,0,cL,1)
                        ans*=prime[i];
            }
            if(L!=1 && a%L && b%L)
                ans*=L;
            coutt(t)<<spc<<ans<<lne;
        }
    }
//    fileclose
    return 0;
}
