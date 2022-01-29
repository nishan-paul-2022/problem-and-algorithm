///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define ud unsigned double
#define vl vector<long long>
#define vd vector<double>
#define vs vector<string>
#define vb vector<bool>
#define vul vector<unsigned long long>
#define vud vector<unsigned double>
#define vvl vector< vector<long long> >
#define vvd vector< vector<double> >
#define vpll vector< pair<long long,long long> >
#define vpls vector< pair<long long,string> >
#define vpsl vector< pair<string,long long> >
#define vpdd vector< pair<double,double> >
#define vpds vector< pair<double,string> >
#define vpsd vector< pair<string,double> >
#define vvpll vector< vector< pair<long long,long long> > >
#define vvpdd vector< vector< pair<double,double> > >
#define mll map<long long,long long>
#define mls map<long long,string>
#define msl map<string,long long>
#define mdd map<double,double>
#define mds map<double,string>
#define msd map<string,double>
#define gll priority_queue< long long, compare >
#define gd priority_queue< double, vector<double>, compare >
#define gs priority_queue< string, vector<string>, compare >
#define gul priority_queue< unsigned long long, vector<unsigned long long>, compare >
#define gud priority_queue< unsigned double, vector<unsigned double>, compare >
#define gpll priority_queue< pair<long long,long long>, vector<pair<long long,long long>>, compare >
#define gpls priority_queue< pair<long long,string>, vector<pair<long long,string>>, compare >
#define gpsl priority_queue< pair<string,long long>, vector<pair<string,long long>>, compare >
#define gpdd priority_queue< pair<double,double>, vector<pair<double,double>>, compare >
#define gpds priority_queue< pair<double,string>, vector<pair<double,string>>, compare >
#define gpsd priority_queue< pair<string,double>, vector<pair<string,double>>, compare >
#define pll pair<long long,long long>
#define pls pair<long long,string>
#define psl pair<string,long long>
#define pdd pair<double,double>
#define pds pair<double,string>
#define psd pair<string,double>
#define vli vector<long long>::iterator
#define vdi vector<double>::iterator
#define vsi vector<string>::iterator
#define vbi vector<bool>::iterator
#define vuli vector<unsigned long long>::iterator
#define vudi vector<unsigned double>::iterator
#define vvli vector< vector<long long> >::iterator
#define vvdi vector< vector<double> >::iterator
#define vplli vector< pair<long long,long long> >::iterator
#define vplsi vector< pair<long long,string> >::iterator
#define vpsli vector< pair<string,long long> >::iterator
#define vpddi vector< pair<double,double> >::iterator
#define vpdsi vector< pair<double,string> >::iterator
#define vpsdi vector< pair<string,double> >::iterator
#define vvplli vector< vector< pair<long long,long long> > >::iterator
#define vvpddi vector< vector< pair<double,double> > >::iterator
#define mlli map<long long,long long>::iterator
#define mlsi map<long long,string>::iterator
#define msli map<string,long long>::iterator
#define mddi map<double,double>::iterator
#define msdi map<string,double>::iterator
#define mdsi map<double,string>::iterator
#define glli priority_queue< long long, compare >::iterator
#define gdi priority_queue< double, vector<double>, compare >::iterator
#define gsi priority_queue< string, vector<string>, compare >::iterator
#define guli priority_queue< unsigned long long, vector<unsigned long long>, compare >::iterator
#define gudi priority_queue< unsigned double, vector<unsigned double>, compare >::iterator
#define gplli priority_queue< pair<long long,long long>, vector<pair<long long,long long>>, compare >::iterator
#define gplsi priority_queue< pair<long long,string>, vector<pair<long long,string>>, compare >::iterator
#define gpsli priority_queue< pair<string,long long>, vector<pair<string,long long>>, compare >::iterator
#define gpddi priority_queue< pair<double,double>, vector<pair<double,double>>, compare >::iterator
#define gpdsi priority_queue< pair<double,string>, vector<pair<double,string>>, compare >::iterator
#define gpsdi priority_queue< pair<string,double>, vector<pair<string,double>>, compare >::iterator
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define mpair make_pair
#define tostring to_string
#define countbit(n) __builtin_popcount(n)
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI acos(-1)
#define infp 1000000000000000000
#define infn -1000000000000000000
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
int main()
{
//    inout
//    fileopenX

    ll n, k=0, S[2] = {0,0};
    cin >> n;
    vector<ll> v;
    for(ll i=0; i<n; i++) {
        ll value;
        cin >> value;
        v.pushb(value);
    }
    for(ll i=0; i<n; i++) {
        ll x = v.front();
        ll y = v.back();
        if(x>=y) {
            S[k] += x;
            v.erase(v.begin());
        }
        else if(x<y) {
            S[k] += y;
            v.erase(v.end()-1);
        }
        k = (k+1)%2;
    }
    cout << S[0] << spc << S[1];

//    filecloseX
//    return 0;
}
