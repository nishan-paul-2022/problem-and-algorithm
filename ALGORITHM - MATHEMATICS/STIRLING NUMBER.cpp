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

vector<ll> prefactorial(ll n)
{
    vector<ll> v(1+n);
    v[0]=1;
    for(ll i=1; i<=n; i++)
        v[i] = i*v[i-1];
    return v;
}

ll** initial(ll row,ll col)
{
    ll** mat;
    mat=new ll*[row];
    for(ll i=0; i<row; i++)
        *(mat+i)=new ll[col];
    for(ll i=0; i<row; i++)
        for(ll j=0; j<col; j++)
            mat[i][j]=0;
    return mat;
}

ll stirling1(ll** v,ll n,ll k,vector<ll> fact)// CYCLIC
{
    if(k==1){
        if(v[n][k]==0) {
            v[n][k] = fact[n-1];
        }
        return v[n][k];
    }
    else if(n==k) {
        return v[n][k]=1;
    }
    else{
        if(v[n-1][k-1]==0)
            v[n-1][k-1] = stirling1(v,n-1,k-1,fact);
        if(v[n-1][k]==0)
            v[n-1][k] = stirling1(v,n-1,k,fact);
        return v[n][k] = v[n-1][k-1]+(n-1)*v[n-1][k];
    }
}

ll stirling2(ll** v,ll n,ll k)// NON-CYCLIC
{
    if(k==1 || n==k) {
        return v[n][k]=1;
    }
    else{
        if(v[n-1][k-1]==0)
            v[n-1][k-1] = stirling2(v,n-1,k-1);
        if(v[n-1][k]==0)
            v[n-1][k] = stirling2(v,n-1,k);
        return v[n][k] = v[n-1][k-1]+k*v[n-1][k];
    }
}

int main()
{
//    inout
//    fileopen

    ll n,k;
    cin >> n >> k;
    
    vector<ll> fact = prefactorial(n);
    ll** v = initial(n+1,k+1);

    cout << stirling1(v,n,k,fact) << lne;
    cout << stirling2(v,n,k) << lne;

//    fileclose
    return 0;
}
