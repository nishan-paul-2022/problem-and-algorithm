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
#define pls pair<ll,string>
#define vpls vector< pair<ll,string> >
#define vplsit vector< pair<ll,string> >::iterator
#define psl pair<string,ll>
#define vpsl vector< pair<string,ll> >
#define vpslit vector< pair<string,ll> >::iterator
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
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll cs=1; cs<=tst; cs++){
        ll n,m,k, p, val;
        cin>>n>>m>>k;
        vl v[1+n];
        for(ll i=1; i<=n; i++)
            for(ll j=0; j<k; j++){
                cin>>val;
                v[i].pushb(val);
            }
        vbol gift(1+m,false);
        cin>>p;
        for(ll i=0; i<p; i++){
            cin>>val;
            gift[val]=true;
        }
        string ans="Yes";
        for(ll i=1; i<=n; i++){
            bool flag=false;
            for(ll j=0; j<k; j++)
                if( (v[i][j]>0 && gift[v[i][j]]==true)||(v[i][j]<0 && gift[-v[i][j]]==false) )
                    flag=true;
            if(flag==false) ans="No";
        }
        cout<<"Case "<<cs<<": "<<ans<<lne;
    }
//    fileclose
    return 0;
}
