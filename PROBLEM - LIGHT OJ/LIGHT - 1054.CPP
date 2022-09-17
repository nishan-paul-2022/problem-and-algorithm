///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vul vector<unsigned long long>
#define vulit vector<unsigned long long>::iterator
#define vbol vector<bool>
#define vbolit vector<bool>::iterator
#define vstr vector<string>
#define vstrit vector<string>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vpllit vector< pair<long long,long long> >::iterator
#define pback push_back
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define mod 1000000007
#define PI 3.141592653589793
#define pos 9223372036854775807
#define neg -9223372036854775808
#define inf 18446744073709551615
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
#define sz 46340
using namespace std;
void sieve(vl &prime)
{
    vbol pre(1+sz,true);
    ll lmt=1+sqrt(sz);
    prime.pback(2);
    for(ll i=3; i<=lmt; i+=2)
        if(pre[i]==true)
            for(ll j=i*i; j<=sz; j+=2*i)
                pre[j]=false;
    for(ll i=3; i<=sz; i+=2)
        if(pre[i]==true)
            prime.pback(i);
}
void make_factor(ll n,ll m,ll sze,vl prime,vpll &fact)
{
    ll lmt=1+sqrt(n);
    for(ll i=0; i<sze && prime[i]<=lmt ; i++){
        ll j, val=prime[i];
        for(j=0; n%val==0; j++)
            n=n/val;
        if(j)
            fact.pback( make_pair(val,m*j) );
    }
    if(n!=1)
        fact.pback( make_pair(n,m) );
}
void totient(ll n,ll &cnt,vector<bool> &v)/// N.LOG(LOG(N))
{
//    vector< pair<ll,ll> > p;
//    make_factor(n,p);
//    vector<bool> tem(1+n,true);
//    ll sze=p.size();
//    cnt=n;
//    for(ll i=0; i<sze; i++){
//        ll x=p[i].first;
//        cnt = cnt-cnt/x;
//        for(ll j=x; j<=n; j+=x)
//            tem[j]=false;
//    }
//    v=tem;
}
bool coprime(ll a,ll b)
{
//    ll x=max(a,b), y=min(a,b), cnt;
//    vector<bool> v;
//    totient(x,cnt,v);
//    return v[y];
}
ll pwr(ll base,ll n)/// LOG(N)
{
    if(n==0) return 1;
    ll x = pwr(base,n/2);
    ll y = x*x;
    if(n%2) y = y*base;
    return y;
}
ll modpwr(ll base,ll n,ll m=mod)/// LOG(N)
{
    if(n==0) return 1;
    ll x = modpwr(base,n/2,m);
    ll y = (x*x) % m;
    if(n%2) y = ( y * (base%m) ) % m;
    return y;
}
ll modinverse(ll b,ll m,bool flag=false)/// N.LOG(LOG(N))
{
    if(flag==true)
        return modpwr(b,m-2,m);
    else{
        if(coprime(b,m)==false)//1/B MOD M does not exist
            return -1;
        else{
            ll cnt;
            vector<bool> v;
            totient(m,cnt,v);
            ll val=modpwr(b,cnt-1,m);
            return val;
        }
    }
}
ll modadd(ll a,ll b,ll m=mod)
{
    ll ans = (a%m + b%m) % m;
    return ans;
}
ll modsub(ll a,ll b,ll m=mod)
{
    ll ans = (a - b) % m;
    if(ans<0) ans+=m;
    return ans;
}
ll modmul(ll a,ll b,ll m=mod)
{
    ll x=a%m, y=b%m;
    ll ans=(x*y)%m;
    return ans;
}
ll moddiv(ll a,ll b,ll m=mod)
{
    ll x=a%m, y=modinverse(b,m,true);
    ll ans=(x*y)%mod;
    return ans;
}
ll sum_divisor(vector< pair<ll,ll> > v)
{
    ll sze=v.size(), ans=1;
    for(ll i=0; i<sze; i++){
        ll p=v[i].first, q=v[i].second;
        ans = modmul( ans, moddiv( modsub( modpwr(p,q+1), 1 ), p-1 ) );
    }
    return ans;
}
int main()
{
    vl prime;
	sieve(prime);
	ll sze=prime.size(), tst;
	cin>>tst;
	for (ll i=1; i<=tst; i++){
        ll n,m;
		cin>>n>>m;
		vpll fact;
		make_factor(n,m,sze,prime,fact);
		ll ans=1, lmt=fact.size();
		for (ll j=0; j<lmt; j++) {
			ll p=fact[j].first, e=fact[j].second;
			ans = modmul(ans,moddiv(modsub(modpwr(p,e+1),1),p-1));
		}
		cout<<"Case "<<i<<": "<<ans<<lne;
	}
}
