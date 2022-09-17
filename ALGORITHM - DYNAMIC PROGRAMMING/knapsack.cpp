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

class item{
    public:
        double weight;
        double price;
};
bool compare(item a,item b){
    double ax = a.price / a.weight;
    double bx = b.price / b.weight;
    return ax > bx;
}
double fknapsack(ll n,double W,item store[]){
    sort(store,store+n,compare);
    double finalprice=0, curWeight=0;
    for(ll i=0; i<n; i++){
        if( curWeight+store[i].weight <= W ){ //If adding item won't overflow, add it completely
            curWeight += store[i].weight;
            finalprice += store[i].price;
        }
        else if(curWeight+store[i].weight > W){ //If we can't add current item, add fractional part of it
            double remain = W - curWeight;
            finalprice += remain * (store[i].price/store[i].weight);
            break;
        }
    }
    return finalprice; // Returning final price
}
double knapsack(ll n,double W,item store[]){
    if(n == 0 || W == 0)// Base Case
       return 0;
    if (store[n-1].weight > W)// If weight of the nth item is more than knapsack capacity W, then this item cannot be included in the optimal solution
       return knapsack(n-1, W, store);
    else if(store[n-1].weight <= W){// Return the maximum of two cases: (1) nth item included (2) not included
        ll x = store[n-1].price + knapsack(n-1, W-store[n-1].weight, store);
        ll y = knapsack(n-1, W, store);
        return max(x,y); // Returning final price
    }
}
int main()
{
    fileopen
    ll n;
    double W;
    cin>>n>>W;
    item store[n];
    for(ll i=0; i<n; i++){
        double weight,price;
        cin>>weight>>price;
        store[i].weight=weight;
        store[i].price=price;
    }
    double k = knapsack(n, W, store);
    double f = fknapsack(n, W, store);
    cout<<k<<spc<<f;
    fileclose
    return 0;
}
//3 50
//10 60
//20 100
//30 120

