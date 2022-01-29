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

//TIME COMPLEXITY FOR FINDING nTH FIBONACCI: LOG2(N)

template<typename T>

class matrix
{
    public:
        T** allocate(ll row,ll col){
            T** mat;
            mat=new T*[row];
            for(ll i=0; i<row; i++)
                *(mat+i)=new T[col];
            return mat;
        }
        T** input(ll row,ll col){
            T** mat=allocate(row,col);
            for(ll i=0; i<row; i++)
                for(ll j=0; j<col; j++)
                    cin>>mat[i][j];
            return mat;
        }
        void print(T** mat,ll row,ll col){
            for(ll i=0; i<row; i++){
                for(ll j=0; j<col; j++)
                    cout<<mat[i][j]<<spc;
                cout<<lne;
            }
        }
};

template<typename T>
void IM ( T** mat, ll row, ll col )
{
    for(ll i=0; i<row; i++) {
        for(ll j=0; j<col; j++) {
            if(i==j)
                mat[i][j]=1;
            else
                mat[i][j]=0;
        }
    }
}

template<typename T>
T** matmul ( T** x, T** y, ll row, ll mid, ll col, bool flag=false, ll m=mod )
{
    matrix<T> mx;
    T** mat = mx.allocate( row, col );
    for(ll i=0; i<row; i++) {
        for(ll j=0; j<col; j++) {
            T sum = 0;
            for(ll k=0; k<mid; k++) {
                if(flag==false)
                    sum = sum + x[i][k]*y[k][j];
                else if(flag==true)
                    sum = ( sum + (x[i][k]*y[k][j])%m )%m;
            }
            mat[i][j] = sum;
        }
    }
    return mat;
}

template<typename T>
T** matpwr ( T** base, ll N, ll n, bool flag=false, ll m=mod )
{
    if(n==0) {
        matrix<T> mx;
        T** i = mx.allocate(N,N);
        IM( i, N, N );
        return i;
    }
    if(flag==false) {
        T** x = matpwr( base, N, n/2 );
        T** y = matmul( x, x, N, N, N );
        if( n%2 ) y = matmul( y, base, N, N, N );
        return y;
    }
    else if(flag==true) {
        T** x = matpwr( base, N, n/2, true, m );
        T** y = matmul( x, x, N, N, N, true, m );
        if( n%2 ) y = matmul( y, base, N, N, N, true, m );
        return y;
    }
}

int main()
{
    // inout
    // fileopen

    ll N=2, n;
    cin >> n;

    matrix<ll> mx;

    ll** base = mx.input( N, N );
    ll** omg = mx.input( N, N-1 );
    ll** x = matpwr( base, N, n );
    ll** ans = matmul( x, omg, N, N, N-1 );

    cout << n << "TH :" << ans[0][0] << lne;
    cout << n-1 << "TH :" << ans[1][0] <<lne;

    // fileclose
    return 0;
}
