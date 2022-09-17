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

//CAN IDENTIFY KNIGHT'S MINIMUM STEPS FROM SOURCE TO DESTINATION
//TIME COMPLEXITY: O( N*N )
class store
{
    public:
        ll ux, vx, distance;
        store(){}
        store(ll ux, ll vx, ll distance) { this->ux = ux, this->vx = vx, this->distance = distance; }
};
bool isinside(store node, ll n)// returns true if (x, y) lies inside Board
{
    if( (node.ux>=0 && node.ux<n) && (node.vx>=0 && node.vx<n) )
        return true;
    return false;
}
ll knight(ll n, ll k[], ll t[])
{
	ll dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};// x and y direction, where a knight can move
	ll dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};
    bool visit[n][n];
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            visit[i][j]=false;// make all nodes unvisited
        }
    }
    visit[ k[0] ][ k[1] ]=true;// visit starting node
    store source(k[0], k[1], 0);
    queue<store> q;// queue for storing nodes of knight in board
    q.push(source);// push starting position of knight with 0 distance
    while( !q.empty() ) {// loop untill we have no element in queue
        store parent = q.front();
        q.pop();
        if(parent.ux==t[0] && parent.vx==t[1])// if current cell is equal to target cell, return its distance
            return parent.distance;
        for(ll i=0; i<8; i++) {// loop for all reachable nodes
            store node(parent.ux + dx[i], parent.vx + dy[i], parent.distance+1);
            if( isinside(node,n) && !visit[node.ux][node.vx] ) {// if reachable node is not yet visited and inside board, push that state llo queue
                visit[node.ux][node.vx]=true;
                q.push(node);
            }
        }
    }
}
int main()
{
//    inout
//    fileopen

    ll n;
    cin>>n;
    ll k[2], t[2];
    cin>>k[0]>>k[1]>>t[0]>>t[1];
    ll mn = knight(n,k,t);// to find minimum steps to reach to specific cell in minimum moves by Knight

    cout<<mn;
//    fileclose
    return 0;
}
