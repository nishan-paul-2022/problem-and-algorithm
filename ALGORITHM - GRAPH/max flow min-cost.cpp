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

class pipe { public: ll from, to, capacity, cost; };

vector<pipe> store(ll edge)
{
    vector<pipe> graph;
    for(ll i=0; i<edge; i++) {
        pipe p;
        cin >> p.from >> p.to >> p.capacity >> p.cost;
        graph.push_back(p);
    }
    return graph;
}

void shortest_paths(ll vertex, ll x, vector<ll> &d, vector<ll> &p, vector<ll> adjacent[], vector<vector<ll>> &cost, vector<vector<ll>> &capacity) {
    d[x] = 0;
    vector<ll> m(vertex, 2);
    deque<ll> q;
    q.push_back(x);
    while (!q.empty()) {
        ll u = q.front();
        q.pop_front();
        m[u] = 0;
        for(ll v : adjacent[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (m[v] == 2 || m[v] == 0) {
                    m[v] = 1;
                    q.push_back(v);
                }
            }
        }
    }
}

ll min_cost_flow(ll vertex, vector<pipe> graph, ll s, ll t, ll K)
{
    vector<ll> adjacent[vertex];
    vector<vector<ll>> cost(vertex,vector<ll>(vertex,0));
    vector<vector<ll>> capacity(vertex,vector<ll>(vertex,0));
    for( ll i=0; i<graph.size(); i++ ) {
        pipe p = graph[i];
        adjacent[p.from].push_back(p.to);
        adjacent[p.to].push_back(p.from);
        cost[p.from][p.to] = p.cost;
        cost[p.to][p.from] = -p.cost;
        capacity[p.from][p.to] = p.capacity;
    }
    ll flow = 0, costx = 0;
    while( flow < K ) {
        vector<ll> d(vertex, infp);
        vector<ll> p(vertex, -1);
        shortest_paths(vertex, s, d, p, adjacent, cost, capacity);
        if( d[t] == infp )
            break;
        ll f = K - flow;// find max flow on that path
        ll cur = t;
        while( cur != s ) {
            f = min(f, capacity[ p[cur] ][cur]);
            cur = p[cur];
        }
        flow += f;// apply flow
        costx += f * d[t];
        cur = t;
        while( cur != s ) {
            capacity[ p[cur] ][cur] -= f;
            capacity[cur][ p[cur] ] += f;
            cur = p[cur];
        }
    }
    return flow<K ? -1 : costx;
}
int main()
{
//    inout
    fileopenX

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<pipe> graph = store(edge);

    ll s, t, K;
    cin >> s >> t >> K;
    cout << min_cost_flow(vertex, graph, s, t, K) << lne;

    filecloseX
    return 0;
}
/*
6 10
0 1 16 5
0 2 13 10
1 2 10 15
1 3 12 3
2 1 4 6
2 4 14 8
3 2 9 11
3 5 20 13
4 3 7 14
4 5 4 17
0 5
5

6 7
0 1 2 2
1 4 1 1
4 5 4 4
0 2 5 5
2 3 3 3
3 5 4 4
1 3 3 3
0 5
5
*/

