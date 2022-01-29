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
double fbisection(double mid,double L){
    double p=sqr(L)+4*sqr(mid);
    double q=4*mid;
    double r=(L*q)/p;
    double v=(p*asin(r))/q;
    return v;
}
double bisection(double x,double y,double gval,double L){
    double mid, accuracy=0.00000001;
    while(y-x>accuracy){
        mid=(x+y)/2;
        double cval=fbisection(mid,L);
        if(cval<gval) x=mid;
        else if(cval>gval) y=mid;
        else if(cval==gval) break;
    }
    return mid;
}
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll t=1; t<=tst; t++){
        double L,n,C;
        cin>>L>>n>>C;
        double gval=L+(L*n*C);
        double h=bisection(0,L,gval,L);
        cout<<"Case "<<t<<": "<<fixed<<setprecision(7)<<h<<lne;
    }
//    fileclose
    return 0;
}
