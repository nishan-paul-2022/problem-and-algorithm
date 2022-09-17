///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define udouble unsigned double
#define gcd __gcd
#define countbit(n) __builtin_popcount(n)
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 29996224275833
#define PI acos(-1)
#define inf ULLONG_MAX
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
#define fileopenX ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX }
using namespace std;

int main()
{
//    inout
    fileopenX

    ll n;
    cin >> n;
    vector<vector<ll>> v, ans;
    ll who = n-1;
    for(ll i = 0; i < 2*n-1; i++) {
        vector<ll> omg, how;
        who = i<n? i+1 : --who;
        for(ll j = 0; j < who; j++) {
            ll value;
            cin >> value;
            omg.push_back(value);
            how.push_back(0);
        }
        v.push_back(omg);
        ans.push_back(how);
    }
    ans[0][0] = v[0][0];
    who = n-1;
    for(ll i = 0; i < 2*n-2; i++) {
        who = i<n? i+1 : --who;
        for(ll j = 0; j < who; j++) {
            if( i<n-1 ) {
                ans[i+1][j] = max( ans[i+1][j], ans[i][j] + v[i+1][j] );
                ans[i+1][j+1] = max( ans[i+1][j+1], ans[i][j] + v[i+1][j+1] );
            }
            else {
                if( j < ans[i+1].size() )
                    ans[i+1][j] = max( ans[i+1][j], ans[i][j] + v[i+1][j] );
                if( j>0 )
                    ans[i+1][j-1] = max( ans[i+1][j-1], ans[i][j] + v[i+1][j-1] );
            }
        }

    }
    cout << "Case " << cs << ": " << ans[2*n-2][0] << lne;

    filecloseX
    return 0;
}

