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
#define mslit map<string,long long>::iterator
#define mls map<long long,string>
#define mlsit map<long long,string>::iterator
#define pushb push_back
#define pushf pop_front
#define popb pop_back
#define popf push_front
#define mpair make_pair
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
vstr word(string s)
{
    ll sze=s.size();
    vstr m;
    string t="";
    for(ll i=0; i<=sze; i++)
        if(i==sze || (s[i]==32 && s[i-1]!=',') || s[i]==','){
            m.pushb(t);
            t="";
        }
        else
            t+=s[i];
    return m;
}
bool isLeap(ll y){ return ((y%4==0 && y%100!=0) || y%400==0);}
ll top(ll x,ll y){ return x%y? 1+x/y:x/y;}
ll down(ll x,ll y){ return x/y;}
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    getchar();
    for(ll cs=1; cs<=tst; cs++){
        string s,t;
        getline(cin,s,lne);
        getline(cin,t,lne);
        vstr vs=word(s), vt=word(t);
        ll ys=stoi(vs[2]), yt=stoi(vt[2]), cnt;
        cnt = (yt/4-yt/100+yt/400)-(ys/4-ys/100+ys/400);
        if( isLeap(ys)==true && (vs[0]=="January" || vs[0]=="February") ) cnt++;
        if( isLeap(yt)==true && !(vt[0]!="January" && (vt[0]!="February" || (vt[0]=="February" && vt[1]=="29"))) ) cnt--;
        cout<<"Case "<<cs<<": "<<cnt<<lne;
    }
//    fileclose
    return 0;
}
