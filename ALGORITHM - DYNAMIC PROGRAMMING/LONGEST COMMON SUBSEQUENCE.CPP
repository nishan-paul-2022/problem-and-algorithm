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

ll LCS( string x, string y, string &sub )
{
    ll m = x.size();
    ll n = y.size();
    ll L[m+1][n+1];

    for(ll i=0; i<=m; i++) { // Following steps build L[m+1][n+1] in bottom up fashion. Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]

        for(ll j=0; j<=n; j++) {

            if(i == 0 || j == 0)
                L[i][j] = 0;

            else if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    ll i = m, j = n, index = L[m][n];
    char lcs[index]; 

    while(i > 0 && j > 0) { 

        if(x[i-1] == y[j-1]) { 
            lcs[index-1] = x[i-1];
            i--, j--, index--;
        }

        else if(L[i-1][j] > L[i][j-1]) 
            i--;

        else
            j--; 
    } 

    sub = lcs; 

    return L[m][n];
}

int main()
{
//    inout
//    fileopenX

    // string x = "AGGTAB", y = "GXTXAYB", sub = "";
    string x, y, sub;
    cin >> x >> y;
    
    ll n = LCS( x, y, sub );
    cout << n << spc << sub << lne;

//    fileclose
    return 0;
}

//AGGTAB, GXTXAYB