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
#define fileopenX fileopen ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX } fileclose
using namespace std;

class Box { public: ll h, w, d; };// h --> height, w --> width, d --> depth | for simplicity of solution, always keep w <= d

class compare { public: bool operator()(Box a,Box b) { return a.d*a.w > b.d*b.w; } };

ll mxStackHeight(Box omg[], ll n)// Returns the height of the tallest stack that can be formed with give type of boxes
{
    Box rot[3*n];// Create an omgay of all rotations of given boxes For example, for a box {1, 2, 3}, we consider three instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}}
    ll index = 0;
    for(ll i = 0; i < n; i++) {
        rot[index].h = omg[i].h;// Copy the original box
        rot[index].d = max(omg[i].d, omg[i].w);
        rot[index++].w = min(omg[i].d, omg[i].w);

        rot[index].h = omg[i].w;// First rotation of box
        rot[index].d = max(omg[i].h, omg[i].d);
        rot[index++].w = min(omg[i].h, omg[i].d);

        rot[index].h = omg[i].d;// Second rotation of box
        rot[index].d = max(omg[i].h, omg[i].w);
        rot[index++].w = min(omg[i].h, omg[i].w);
    }
    n = 3*n;// Now the number of boxes is 3n
    sort(rot, rot+n, compare());// Sort the omgay 'rot[]' in non-increasing order of base area
    ll msh[n];// Initialize msh values for all indexes msh[i] --> maximum possible Stack Height with box i on top
    for(ll i = 0; i < n; i++)
        msh[i] = rot[i].h;
    for(ll i = 1; i < n; i++)// Compute optimized msh values in bottom up manner
        for(ll j = 0; j < i; j++)
            if( rot[i].w < rot[j].w && rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h )
                msh[i] = msh[j] + rot[i].h;
    ll mx = -1;// Pick mximum of all msh values
    for(ll i = 0; i < n; i++ )
        mx = max(mx, msh[i]);
    return mx;
}

int main()// Dynamic Programming implementation of Box Stacking problem
{
//    inout
    fileopen

    ll n;
    cin >> n;
    Box omg[n];
    for(ll i = 0; i < n; i++)
        cin >> omg[i].h >> omg[i].w >> omg[i].d ;
    ll mx = mxStackHeight (omg, n);
    cout << "The maximum possible height of stack is " << mx << lne;

    fileclose
    return 0;
}
/*
3
4 6 7
1 2 3
4 5 6
10 12 32
*/
