///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define udouble unsigned double
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
#define mod 29996224275833
#define PI acos(-1)
#define inf  ULLONG_MAX
#define infp LLONG_MAX
#define infn LLONG_MIN
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

class p
{
    public:
        double x1,y1,x2,y2;
        double c1,c2;
        double a1,b1,a2,b2;
        void f(){
            c1=(x1+x2)/2;
            c2=(y1+y2)/2;
        }
        bool g(p t){
            a1=min(t.x1,t.x2), a2=max(t.x1,t.x2);
            b1=min(t.y1,t.y2), b2=max(t.y1,t.y2);
            if((a1<=c1 && c1<=a2) && (b1<=c2 && c2<=b2))
                return true;
            else
                return false;
        }
};
int main()
{
    ll n;
    cin>>n;
    p s[n];
    for(ll i=0; i<n; i++)
        cin>>s[i].x1>>s[i].y1>>s[i].x2>>s[i].y2;
    for(ll i=1; i<n; i++){
        s[i].f();
        if(s[i].g(s[i-1])==false){
            cout<<i;
            return 0;
        }
        cout<<s[i].c1<<spc<<s[i].c2<<spc<<s[i].a1<<spc<<s[i].a2<<spc<<s[i].b1<<spc<<s[i].b2<<lne;
    }
    cout<<n;
    return 0;
}
//7
//-9 -9 9 9
//-8 3 0 -5
//-16 -8 6 14
//14 -11 -6 9
//5 -5 1 -9
//-11 -21 13 3
//-10 5 10 -15

//-4 -1  -9 9 -9 9
//-5 3   -8 0 -5 3
//4 -1   -16 6 -8 14
//3 -7   -6 14 -11 9
//1 -9   1 5 -9 -5
//0 -5   -11 13 -21 3
//7
