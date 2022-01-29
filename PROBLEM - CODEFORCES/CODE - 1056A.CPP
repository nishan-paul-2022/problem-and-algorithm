///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vli vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvli vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vuli vector<unsigned long long>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vplli vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsi vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpsli vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvplli vector< vector< pair<long long,long long> > >::iterator
#define mll map<long long,long long>
#define mlli map<long long,long long>::iterator
#define msl map<string,long long>
#define msli map<string,long long>::iterator
#define mls map<long long,string>
#define mlsi map<long long,string>::iterator
#define ud unsigned double
#define vd vector<double>
#define vdi vector<double>::iterator
#define vvd vector< vector<double> >
#define vvdi vector< vector<double> >::iterator
#define vud vector<unsigned double>
#define vudi vector<unsigned double>::iterator
#define pdd pair<double,double>
#define vpdd vector< pair<double,double> >
#define vpddi vector< pair<double,double> >::iterator
#define pds pair<double,string>
#define vpds vector< pair<double,string> >
#define vpdsi vector< pair<double,string> >::iterator
#define psd pair<string,double>
#define vpsd vector< pair<string,double> >
#define vpsdi vector< pair<string,double> >::iterator
#define vvpdd vector< vector< pair<double,double> > >
#define vvpddi vector< vector< pair<double,double> > >::iterator
#define mdd map<double,double>
#define mddi map<double,double>::iterator
#define msd map<string,double>
#define msdi map<string,double>::iterator
#define mds map<double,string>
#define mdsi map<double,string>::iterator
#define vs vector<string>
#define vsi vector<string>::iterator
#define vb vector<bool>
#define vbi vector<bool>::iterator
#define vtrpl vector<trpl>
#define vtrpli vector<trpl>::iterator
#define vvtrpl vector< vector<trpl> >
#define vvtrpli vector< vector<trpl> >::iterator
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
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("accurate.txt"); system("input.txt"); FILE *my1=freopen("input.txt","r",stdin); FILE *my2=freopen("output.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("output.txt"); freopen("CON","w",stdout); checker();
using namespace std;
class trpl{ public: ll x,y,z; trpl(){} trpl(ll a,ll b,ll c){ x=a,y=b,z=c;} };
void checker(string s1="accurate.txt",string s2="output.txt"){
    char *name1=&s1[0], *name2=&s2[0];
    FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");
    char c1(spc), c2(spc);
    if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; return;}
    if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; return;}
    ll ex=0, ey=0;
    while(c1!=EOF && c2!=EOF){
        c1=getc(f1); c2=getc(f2);
        if(c1==lne){ ex++; ey=0;}
        if(c1!=c2){
            cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;
            cout<<c1<<" INSTEAD of "<<c2<<lne;
            return;
        }
        ey++;
    }
    fclose(f1); fclose(f2);
    cout<<"NO ERROR"<<lne;
}
int main()
{
    inout
//    fileopen
    ll mark[101];
    mem(mark,0);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++){
        ll p;
        cin>>p;
        while(p--){
            ll idx;
            cin>>idx;
            mark[idx]++;
        }
    }
    for(ll i=1; i<=100; i++)
        if(mark[i]==n)
            cout<<i<<spc;
//    fileclose
    return 0;
}
