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

//TIME COMPLEXITY: N^3

template<typename T>

class matrix
{
    public:
        T** allocate(ll row,ll col) {
            T** mat;
            mat=new T*[row];
            for(ll i=0; i<row; i++) {
                *(mat+i)=new T[col];
            }
            return mat;
        }
        T** input(ll row,ll col) {
            T** mat=allocate(row,col);
            for(ll i=0; i<row; i++) {
                for(ll j=0; j<col; j++) {
                    cin>>mat[i][j];
                }
            }
            return mat;
        }
        void swapRow(T** mat,ll col,ll x,ll y) {
            for(ll i=0; i<col; i++) {
                swap(mat[x][i], mat[y][i]);
            }
        }
        void swapCol(T** mat,ll row,ll x,ll y) {
            for(ll i=0; i<row; i++) {
                swap(mat[i][x], mat[i][y]);
            }
        }
        void print(T** mat,ll row,ll col) {
            for(ll i=0; i<row; i++) {
                for(ll j=0; j<col; j++) {
                    cout<<mat[i][j]<<spc;
                }
                cout<<lne;
            }
        }
};

void create(double** mat,ll N)
{
    for(ll i=0; i<N; i++) {
        matrix<double> m;
        ll row=i;
        double value = abs(mat[i][i]);
        for(ll j=i+1; j<N; j++) {
            if(abs(mat[j][i]) > value) {
                value=abs(mat[j][i]);
                row=j;
            }
        }
        if(row!=i) {
            m.swapRow(mat,N+1,i,row);
        }
        for(ll j=i+1; j<N; j++) {
            double fact= mat[j][i]/mat[i][i];
            for(ll k=i+1; k<=N; k++) {
                mat[j][k] -= (mat[i][k]*mat[j][i])/mat[i][i];
            }
            mat[j][i] = 0;
        }
    }
}

vector<double> root(double** mat,ll N)
{
    vector<double> v(N);
    for(ll i=N-1; i>=0; i--) {
        double sum=0;
        for(ll j=N-1; j>=i; j--) {
            if(j==i)
                v[i] = (mat[i][N]-sum)/mat[i][i];
            else
                sum += v[j]*mat[i][j];
        }
    }
    return v;
}

vector<double> gaussElim(double** mat,ll N)
{
    create(mat,N);
    vector<double> v=root(mat,N);
    return v;
}

int main()
{
//    inout
    // fileopen

    ll N;
    cin >> N;

    matrix<double> m;

    double** mat = m.input(N,N+1);
    vector<double> v = gaussElim(mat,N);

    for(ll i=0; i<N; i++) {
        cout << v[i] << spc;
    }

    // fileclose
    return 0;
}
