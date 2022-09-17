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
//#define fileopen system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
//#define fileclose fclose(my1); fclose(my2); system("filec.txt");
#define fileopen system("filea.txt"); system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("filec.txt"); freopen("CON","w",stdout); string s1="filea.txt",s2="filec.txt"; char *name1=&s1[0], *name2=&s2[0]; FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");char c1(spc), c2(spc);if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; exit(0);} if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; exit(0);}ll ex=0, ey=0;while(c1!=EOF && c2!=EOF){c1=getc(f1); c2=getc(f2);if(c1==lne){ ex++; ey=0;}if(c1!=c2){cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;cout<<c1<<" INSTEAD of "<<c2<<lne;exit(0);}ey++;}fclose(f1); fclose(f2);cout<<"NO ERROR"<<lne;
#define fileopenX fileopen ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX } fileclose
using namespace std;

ll** allocate(ll n,ll r)
{
    ll** dp = new ll*[n];
    for(ll i=0; i<n; i++)
        *(dp+i) = new ll[r];
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<r; j++) {
            dp[i][j] = 0;
        }
    }
    return dp;
}

ll nCr(ll n,ll r,ll **dp)
{
    if(n==r)
        return dp[n][r]=1;
    else if(r==1)
        return dp[n][r]=n;
    else{
        if(dp[n][r]==0){
            ll x = dp[n-1][r] ? dp[n-1][r] : nCr(n-1,r,dp);
            ll y = dp[n-1][r-1] ? dp[n-1][r-1] : nCr(n-1,r-1,dp);
            dp[n][r] = x+y;
        }
        return dp[n][r];
    }
}

int main()
{
//    inout
    fileopenX

    ll n, k, ans;
    cin >> n >> k;
    if( k==0 )
        ans = 1;
    else if( k>n )
        ans = 0;
    else {
        ll** dp = allocate ( n+1, k+1 );
        ans = nCr( n, k, dp );
        for(ll i = 0; i < k; i++)
            ans = ans*(n--);
    }
    cout << "Case " << cs << ": " << ans << lne;

    filecloseX
    return 0;
}
