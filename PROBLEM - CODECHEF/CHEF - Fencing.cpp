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
#define fileopenX ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX }
using namespace std;

int main()
{
//    inout
    fileopenX

    ll r, c, n;
    cin >> r >> c >> n;
//    vector<vector<bool>> v(r, vector<bool>(c,false));
    map<pair<ll,ll>,bool> v;
    vector<ll> omg;
    for(ll i = 0, j = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        v[ make_pair(x,y) ] = true;
        omg.push_back(x);
        omg.push_back(y);
    }
    ll ans = 0;
    n = n*2;
    for(ll i = 0; i < n; i+=2) {
        ll bx=omg[i], by=omg[i+1]+1, cx=omg[i], cy=omg[i+1]-1, dx=omg[i]+1, dy=omg[i+1], ex=omg[i]-1, ey=omg[i+1];
        if( (bx >= r || bx < 0) || (by >= c || by < 0) )
            ans++;
        else if( v[ make_pair(bx,by) ] == false )
            ans++;
        if( (cx >= r || cx < 0) || (cy >= c || cy < 0) )
            ans++;
        else if( v[ make_pair(cx,cy) ] == false )
            ans++;
        if( (dx >= r || dx < 0) || (dy >= c || dy < 0) )
            ans++;
        else if( v[ make_pair(dx,dy) ] == false )
            ans++;
        if( (ex >= r || ex < 0) || (ey >= c || ey < 0) )
            ans++;
        else if( v[ make_pair(ex,ey) ] == false )
            ans++;
    }
    cout << ans << lne;

    filecloseX
    return 0;
}

