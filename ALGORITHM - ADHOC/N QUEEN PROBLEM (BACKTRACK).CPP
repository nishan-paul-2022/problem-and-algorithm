///CUET-IRON-BAT
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

ll** allocate(ll n)
{
    ll **a = new ll*[n];
    for(ll i=0; i<n; i++){
        *(a+i) = new ll[n];
    }
    return a;
}

void print(ll **a, ll n)
{
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<rsw(3)<<a[i][j];
        }
        cout<<lne;
    }
}

void design (ll **a, ll n)
{
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if( a[i][j] != i )
                a[i][j] = -1;
        }
    }
}

void mark (ll **a, ll n, ll row, ll i, bool &omg)
{
    omg = true;
    ll x = 1;
    a[row][i] = row;
    for(ll j = row+1; j < n; j++) {
        if( a[j][i] == n+1 )
            a[j][i] = row;
        if( i+x < n && a[j][i+x] == n+1 )
            a[j][i+x] = row;
        if( i-x >= 0 && a[j][i-x] == n+1 )
            a[j][i-x] = row;
        x++;
    }
}
void unmark (ll **a, ll n, ll row, ll i, bool &omg)
{
    omg = false;
    ll x = 1;
    a[row][i] = n+1;
    for(ll j = row+1; j < n; j++) {
        if( a[j][i] == row )
            a[j][i] = n+1;
        if( i+x < n && a[j][i+x] == row )
            a[j][i+x] = n+1;
        if( i-x >= 0 && a[j][i-x] == row )
            a[j][i-x] = n+1;
        x++;
    }
}

bool board (ll **a, ll n, ll row, bool &check)
{
    if( row>=n ) {
        check = true;
        return true;
    }
    bool omg = false;
    for(ll i = 0; i < n && !check; i++) {
        if( a[row][i] == n+1 ) {
            mark (a, n, row, i, omg);
            ll flag = board (a, n, row+1, check);
            if( !flag ) {
                unmark (a, n, row, i, omg);
            }
        }
    }
    if( !omg )
        return false;
    else
        return true;
}

int main()
{
//    inout
//    fileopen

    ll n;
    cin >> n;
    ll **a = allocate(n);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            a[i][j] = n+1;
        }
    }
    ll row = 0;
    bool check = false;
    board(a, n, row, check);
    design(a, n);
    print(a, n);

//    fileclose
    return 0;
}
