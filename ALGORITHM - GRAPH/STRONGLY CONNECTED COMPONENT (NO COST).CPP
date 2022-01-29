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
//DISCONNECTED/CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | UNWEIGHTED | SELF-LOOP/NO-LOOP
//CAN IDENTIFY STRONGLY CONNECTED COMPONENTS OF A GIVEN GRAPH
//TIME COMPLEXITY: O(V+E)

class compare { public: bool operator()(pair<ll,ll> a,pair<ll,ll> b) { return a.second == b.first; } };

void store(ll vertex, ll edge, vector<ll> v[])
{
    for(ll i=0; i<edge; i++) {
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
//        v[b].push_back(a);// for undirected graph only
    }
}

void transpose(ll vertex, vector<ll> v[], vector<ll> u[])
{
    for(ll i = 0; i < vertex; i++) {
        for(ll j = 0; j < v[i].size(); j++) {
            u[ v[i][j] ].push_back( i );
        }
    }
}

void dfsPoint(ll start, vector<ll> v[], vector<bool> &visit, vector<ll> &omg)
{
    visit[start] = true;
    omg.push_back( start );
    for(ll i = 0; i < v[start].size(); i++) {
        ll p = v[start][i];
        if( visit[p] == false ) {
            dfsPoint( p, v, visit, omg );
        }
    }
}

void dfsEdge(ll start, vector<ll> v[], vector<bool> &visit, vector<pair<ll,ll>> &omg)
{
    visit[start] = true;
    for(ll i = 0; i < v[start].size(); i++) {
        ll p = v[start][i];
        if( visit[p] == false ) {
            omg.push_back( make_pair(p,start) );
            dfsEdge( p, v, visit, omg );
        }
    }
}

vector<ll> Point(ll start, vector<ll> v[], vector<bool> &visit)
{
    vector<ll> omg;
    dfsPoint( start, v, visit, omg );
    return omg;
}

vector<pair<ll,ll>> Edge(ll start, vector<ll> v[], vector<bool> &visit)
{
    vector<pair<ll,ll>> omg;
    dfsEdge( start, v, visit, omg );
    if( omg.size() > 1 ) {
        sort( omg.begin(), omg.end(), compare() );
        omg.push_back( make_pair( omg[ omg.size()-1 ].second, omg[0].first ) );// for directed graph only
    }
    return omg;
}

void SCC(ll vertex, vector<ll> v[], vector<vector<ll>> &sccPoint, vector<vector<pair<ll,ll>>> &sccEdge)
{
    vector<ll> omg;
    vector<bool> visit(vertex,false);
    for(ll i = 0; i < vertex; i++) {
        if( visit[i] == false )
            dfsPoint( i, v, visit, omg );
    }
    vector<ll> u[vertex];
    transpose( vertex, v, u );
    vector<bool> visitEdge(vertex,false);
    vector<bool> visitPoint(vertex,false);
    for(ll i = 0; i < omg.size(); i++) {
        if( visitPoint[ omg[i] ] == false ) {
            vector<ll> omgPoint = Point( omg[i], u, visitPoint );
            sccPoint.push_back(omgPoint);
        }
        if( visitEdge[ omg[i] ] == false ) {
            vector<pair<ll,ll>> omgEdge = Edge( omg[i], u, visitEdge );
            if( omgEdge.empty() )
                omgEdge.push_back( make_pair(omg[i],omg[i]) );
            sccEdge.push_back(omgEdge);
        }
    }
}

void printPoint(vector<vector<ll>> scc)
{
    for(ll i = 0; i < scc.size(); i++) {
        vector<ll> road = scc[i];
        for(ll j = 0; j < road.size(); j++) {
            cout << road[j] << spc;
        }
        cout<<lne;
    }
    cout<<lne;
}

void printEdge(vector<vector<pair<ll,ll>>> scc)
{
    for(ll i = 0; i < scc.size(); i++) {
        vector<pair<ll,ll>> road = scc[i];
        if( road.size()==1 && road[0].first==road[0].second )
            cout << road[0].first;
        else {
            for(ll j = 0; j < road.size(); j++)
                cout << road[j].first << "-" << road[j].second << spc;
        }
        cout << lne;
    }
    cout << lne;
}

int main()
{
//    inout
    fileopen

    ll vertex,edge;
    cin >> vertex >> edge;
    vector<ll> v[vertex];
    store(vertex, edge, v);

    vector<vector<ll>> sccPoint;
    vector<vector<pair<ll,ll>>> sccEdge;
    SCC( vertex, v, sccPoint,sccEdge ); /*can not properly print the edge of a negative cycle for an undirected graph*/
    printPoint(sccPoint);
    printEdge(sccEdge);

    fileclose
	return 0;
}
/*
directed
14 17
0 1
1 2
2 4
4 5
5 1
2 3
3 6
6 9
9 3
6 10
10 7
7 8
8 10
3 3
11 12
12 13
13 11
ans: 0 | 1 5 4 2 | 3 9 6 | 10 8 7 | 11 13 12

undirected
7 7
0 1 -1
1 2 -2
2 0 -3
0 3 1
3 4 2
1 6 1
2 5 10
ans: 0 1 2 5 6 3 4
*/
