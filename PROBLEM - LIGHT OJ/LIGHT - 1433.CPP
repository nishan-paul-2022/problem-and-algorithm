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
        double a,b, x1,y1, x2,y2;
        cin>>a>>b>>x1>>y1>>x2>>y2;
        double r=sqrt( sqr((a-x1))+sqr((b-y1)) );
        double c=sqrt( sqr((x2-x1))+sqr((y2-y1)) );
        double s= r*acos(1-(sqr(c)/(2*r*r)));
        cout<<"Case "<<cs<<": "<<fixed<<setprecision(6)<<s<<lne;
    }
//    fileclose
    return 0;
}
