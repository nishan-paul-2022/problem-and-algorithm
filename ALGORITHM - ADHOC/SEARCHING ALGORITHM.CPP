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

//BINARY SEARCH: index / lower_bound / upper_bound for a given element
template <class addrs, class T>
addrs binary(addrs first, addrs last, T val, ll &tst, ll &idx)///LOG(N)
{
    addrs it, bck=first;
    ll step, sze;
    step=sze=distance(first,last);
    while(step>0){
        it=first;
        step=step/2;
        advance(it,step);
        if(val>*it)
            first=it+1;
    }
    idx=distance(bck,first);
    if(idx==0 && *first!=val) tst=1;
    else if(idx==sze+1) tst=2;
    else if(*first==val) tst=3;
    else tst=4;
    return first;
}

//FBISECTION & FTERNARY, BOTH FUNCTIONS ARE CONTINUOUS AND ONE-ONE
//THE SLOPE OF FBISECTION FUNCTION IS POSITIVE ALWAYS
//BISECTION METHOD (finding x for which the functional value of the given equation is y)
double fbisection(double mid){

}
double bisection(double x,double y,double gval){
    double mid, accuracy=0.00000001;
    while(y-x>accuracy){
        mid=(x+y)/2;
        double cval=fbisection(mid);
        if(cval<gval) x=mid;
        else if(cval>gval) y=mid;
        else if(cval==gval) break;
    }
    return mid;
}
//TERNARY SEARCH (finding x for which the functional value of the given equation is max/min)
double fternary(double mid){

}
double ternary(double x,double y){
    double m1,m2, accuracy=0.00000001;
    while(y-x>accuracy){
        m1=x+(y-x)/3;
        m2=x+2*(y-x)/3;
        double vm1=fternary(m1), vm2=fternary(m2);
        if(vm1<vm2) y=m2;
        else if(vm1>vm2) x=m1;
    }
    return y;
}

int main()
{
//    inout
//    fileopen

//    fileclose
    return 0;
}
