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
int main()
{
//    inout
//    fileopen
    ll n,s;
    bool flag=true;
    cin>>n>>s;
    ll a[1+n], b[1+n], j;
    for(ll i=1; i<=n; i++)
        cin>>a[i];
    for(ll i=1; i<=n; i++)
        cin>>b[i];
    if(a[1]==1){
        if(a[s]==1 || b[s]==1){
            if(a[s]==0){
                for(j=s+1; (a[j]==0 || b[j]==0) && j<=n; j++);
                if(j>n) flag=false;
            }
        }
        else flag=false;
    }
    else flag=false;
    cout<<(flag?"YES":"NO");
//    fileclose
    return 0;
}
