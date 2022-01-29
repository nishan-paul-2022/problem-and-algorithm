///CUET_IRON_BAT
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
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define coutw(m) cout<<fixed<<setw(m)
#define coutp(n) cout<<fixed<<setprecision(n)
#define couts(m,n) cout<<fixed<<setw(m)<<setprecision(n)
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
using namespace std;
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll t=1; t<=tst; t++){
        ll n,p,q;
        cin>>n>>p>>q;
        ll a[1+n]={0}, i;
        for(i=1; i<=n; i++)
            cin>>a[i];
        ll sum=0;
        for(i=1; i<=n && i<=p && (sum+=a[i])<=q; i++);
        if(i<=n+1) i--;
        cout<<"Case "<<t<<": "<<i<<lne;
    }
//    fileclose
    return 0;
}
