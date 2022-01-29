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

double** allocate (ll n)///IT CREATES A nxn MATRIX
{
    double **m = new double*[n];

    for(ll i=0; i<n; i++) {

        *(m+i) = new double[n];
    }
    return m;
}

double** input (ll n)///IT TAKES INPUT FOR THAT nxn MATRIX
{
    double **m = allocate (n);

    for(ll i=0; i<n; i++) {

        for(ll j=0; j<n; j++) {

            cin >> m[i][j];
        }
    }
    return m;
}

void output (double **m,ll n)///IT PRINTS THAT nxn MATRIX
{
    for(ll i=0; i<n; i++)  {

        for(ll j=0; j<n; j++) {

            cout << setw(5) << m[i][j];
        }
        cout << lne;
    }
}

double** add (double **A, double **B, ll n)///IT ADDS TWO nxn MATRIX
{
    double **C = allocate(n);

    for(ll i=0; i<n; i++) {

        for(ll j=0; j<n; j++) {

            C[i][j] = A[i][j]+B[i][j];
        }
    }

    return C;
}

double** sub (double **A, double **B, ll n)///IT SUBTRACTS TWO nxn MATRIX
{
    double **C = allocate(n);

    for(ll i=0; i<n; i++) {

        for(ll j=0; j<n; j++) {

            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

double** separate (double **G, ll x, ll y, ll n)
{
    double **g = allocate(n);

    for(ll i=x, ip=0; i<x+n; i++, ip++) {

        for(ll j=y,jp=0; j<y+n; j++, jp++) {

            g[ip][jp] = G[i][j];
        }
    }
    return g;
}

void separate_x (double **G, double ***g, ll n)
{
    g[0] = separate (G, 0, 0, n);
    g[1] = separate (G, 0, n, n);
    g[2] = separate (G, n, 0, n);
    g[3] = separate (G, n, n, n);
}

void mix (double **G, double **g, ll x, ll y, ll n)
{
    for(ll i=0, ip=x; i<n; i++, ip++) {

        for(ll j=0, jp=y; j<n; j++, jp++) {

            G[ip][jp] = g[i][j];
        }
    }
}

void mix_x (double **G, double ***g, ll n)
{
    mix (G, g[0], 0, 0, n);
    mix (G, g[1], 0, n, n);
    mix (G, g[2], n, 0, n);
    mix (G, g[3], n, n, n);
}

void calculate (double ***g, double ***p, ll n)
{
    g[0] = add ( sub( add(p[0], p[3], n ), p[4], n ), p[6], n );
    g[1] = add ( p[2], p[4], n );
    g[2] = add ( p[1], p[3], n );
    g[3] = add ( sub( add (p[0], p[2], n), p[1], n ), p[5], n );
}

double** multiplie(double **A, double **B, ll n)///IT MULTIPLIES TWO nxn MATRIX
{
    double **C = allocate(n);

    if(n==1) {

        C[0][0] = A[0][0]*B[0][0];
    }
    else {

        n/=2;

        double **aq[4], **bq[4], **cq[4], **p[7];

        separate_x (A, aq, n);
        separate_x (B, bq, n);

        p[0] = multiplie ( add(aq[0], aq[3], n), add(bq[0], bq[3], n), n );
        p[1] = multiplie ( add(aq[2], aq[3], n), bq[0], n );
        p[2] = multiplie ( aq[0], sub(bq[1], bq[3], n), n );
        p[3] = multiplie ( aq[3], sub(bq[2], bq[0], n), n );
        p[4] = multiplie ( add(aq[0], aq[1], n), bq[3], n );
        p[5] = multiplie ( sub(aq[2], aq[0], n), add(bq[0], bq[1], n), n );
        p[6] = multiplie ( sub(aq[1], aq[3], n), add(bq[2], bq[3], n), n );

        calculate (cq, p, n);

        mix_x (C, cq, n);
    }

    return C;
}

int main()
{
    fileopen

    ll n;
    cin >> n;

    double **A = input (n);
    double **B = input (n);

    double **C = multiplie (A, B, n);

    output (C, n);

    fileclose

    return 0;
}
//456	420	384	348	312	276	240	204
//548	504	460	416	372	328	284	240
//640	588	536	484	432	380	328	276
//732	672	612	552	492	432	372	312
//824	756	688	620	552	484	416	348
//916	840	764	688	612	536	460	384
//1008	924	840	756	672	588	504	420
//1100	1008	916	824	732	640	548	456
