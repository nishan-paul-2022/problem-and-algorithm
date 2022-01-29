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
using namespace std;;
//CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | POSITVE-WEIGHTED | NO-LOOP
//CAN IDENTIFY THE SHORTEST PATH FROM ANY NODE TO EVERY OTHER NODE
//TIME COMPLEXITY: O( V*V*V )
ll** allocate(ll n)
{
    ll **v=new ll*[n];
    for(ll i=0; i<n; i++) {
        *(v+i)=new ll[n];
    }
    return v;
}
ll** store(ll vertex,ll edge,map<pair<ll,ll>,ll> &m)
{
    ll **v = allocate(vertex);
    for(ll i=0; i<vertex; i++) {
        for(ll j=0; j<vertex; j++) {
            v[i][j]=-1;
        }
        v[i][i]=0;
    }
    for(ll i=0; i<edge; i++) {
        ll ux,vx,weight;
        cin>>ux>>vx>>weight;
        v[ux][vx]=weight;
        m[ make_pair(ux,vx) ] = vx;
        v[vx][ux]=weight;//for undirected graph only
        m[ make_pair(vx,ux) ] = ux;//for undirected graph only
    }
    return v;
}
void floyd(ll vertex,ll **v,map<pair<ll,ll>,ll> &m)
{
    for(ll k=0; k<vertex; k++) {
        for(ll i=0; i<vertex; i++) {
            for(ll j=0; j<vertex; j++) {
                if( v[i][j]>0 && v[i][k]>0 && v[k][j]>0 ) {
                    if( v[i][j] > v[i][k]+v[k][j] ) {
                        v[i][j] = v[i][k]+v[k][j];
                        m[ make_pair(i,j) ] = m[ make_pair(i,k) ];
                    }
                }
                else if( v[i][j]==-1 && (v[i][k]>0 && v[k][j]>0) ) {
                    v[i][j] = v[i][k]+v[k][j];
                    m[ make_pair(i,j) ] = m[ make_pair(i,k) ];
                }
            }
        }
    }
}
vector<ll> road(ll x,ll y,map<pair<ll,ll>,ll> m)
{
    vector<ll> store;
    store.push_back(x);
    while(x!=y){
        x = m[ make_pair(x,y) ];
        store.push_back(x);
    }
    return store;
}
map<pair<ll,ll>,vector<ll>> roadmap(ll vertex,ll **v,map<pair<ll,ll>,ll> m)
{
    map<pair<ll,ll>,vector<ll>> path;
    for(ll i=0; i<vertex; i++){
        for(ll j=0; j<vertex; j++){
            if(v[i][j]>0){
                vector<ll> store = road(i,j,m);
                path[ make_pair(i,j) ] = store;
            }
        }
    }
    return path;
}
void print(ll vertex,ll **v,map<pair<ll,ll>,vector<ll>> path)
{
    cout<<'.'; for(ll i=0; i<vertex; i++) { cout<<setw(5)<<i; } cout<<lne;//making row indexing
    for(ll i=0; i<vertex; i++) {
        cout<<i<<spc;//making column indexing
        for(ll j=0; j<vertex; j++) {
            cout<<setw(4)<<v[i][j]<<spc;
        }
        cout<<lne;
    }
    for(ll i=0; i<vertex; i++) {
        for(ll j=0; j<vertex; j++) {
            if(v[i][j]>0) {
                vector<ll> store = path[ make_pair(i,j) ];
                cout<<"("<<i<<","<<j<<"):";
                for(ll k=0; k<store.size(); k++) {
                    cout<<spc<<store[k];
                }
                cout<<lne;
            }
        }
    }
}
int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin>>vertex>>edge;
    map<pair<ll,ll>,ll> m;
    ll **v = store(vertex,edge,m);

    floyd(vertex,v,m);
    map<pair<ll,ll>,vector<ll>> path = roadmap(vertex,v,m);
    print(vertex,v,path);

    fileclose
    return 0;
}
/*
directed
4 4
0 1 5
0 3 10
1 2 3
2 3 1
 0  5  8  9
-1  0  3  4
-1 -1  0  1
-1 -1 -1  0

undirected
4 4
0 1 5
0 3 10
1 2 3
2 3 1
0 5 8 9
5 0 3 4
8 3 0 1
9 4 1 0
*/
