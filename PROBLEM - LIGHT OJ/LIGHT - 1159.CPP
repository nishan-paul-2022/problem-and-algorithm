#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define ud unsigned double
#define gcd __gcd
#define countbit __builtin_popcount
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

ll LCS( string x, string y, string z )
{
    ll m = x.size();
    ll n = y.size();
    ll p = z.size();
    ll L[m+1][n+1][p+1];

    for(ll i=0; i<=m; i++) {

        for(ll j=0; j<=n; j++) {

            for(ll k=0; k<=p; k++) {

                if(i == 0 || j == 0 || k == 0)
                    L[i][j][k] = 0;

                else if(x[i-1] == y[j-1] && y[j-1] == z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;

                else {
                    int sx = max( L[i-1][j][k], L[i][j-1][k] );
                    int sy = L[i][j][k-1];
                    L[i][j][k] = max(sx, sy);
                }
            }
        }
    }

    return L[m][n][p];
}

ll lcs( string x, string y, string z, ll m, ll n, ll p )
{
    if( m==0 || n==0 || p==0 )
        return 0;

    else if( x[m-1]==y[n-1] && y[n-1]==z[p-1] )
        return 1 + lcs(x,y,z,--m,--n,--p);
    else 
        return max( max( lcs(x,y,z,--m,n,p), lcs(x,y,z,m,--n,p) ), lcs(x,y,z,m,n,--p) );
}

int main()
{
    ll test;
    cin >> test;

    for(ll i=1; i<=test; i++) {
        string x, y, z;
        cin >> x >> y >> z;
        
        ll result = LCS(x,y,z);

        cout<< "Case " << i << ": " << result << lne;
    }

    return 0;
}