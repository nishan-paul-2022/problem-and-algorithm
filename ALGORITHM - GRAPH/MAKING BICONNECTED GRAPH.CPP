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

//DISCONNECTED/CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | NEGATIVE-WEIGHTED/POSITVE-WEIGHTED/UNWEIGHTED | SELF-LOOP/NO-LOOP
//CAN IDENTIFY THE NUMBER OF EXTRA-EDGES TO MAKE THE GIVEN GRAPH, A BICONNECTED GRAPH
//TIME COMPLEXITY: O(V+E)
void store(ll edge, vector<ll> v[])
{
    for(ll i=0; i<edge; i++) {
        ll ux, vx;
        cin >> ux >> vx;
        v[ux].push_back(vx);
        v[vx].push_back(ux);
    }
}

void _Articulation(ll node, vector<ll> &parent, vector<ll> &discovery, vector<ll> &low, vector<pair<ll,ll>> &bridge, vector<ll> v[])
{
    ll child = 0;
    static ll flag = 0;
    discovery[node] = low[node] = flag++;
    for(ll i=0; i<v[node].size(); i++) {
        ll x = v[node][i];
        if( discovery[x]==-1 ) { // if x is not visited yet, then make it a child of node in DFS tree
            child++;
            parent[x] = node;
            _Articulation(x, parent, discovery, low, bridge, v);
            low[node] = min(low[node], low[x]);// checks if the subtree rooted with x has a connection to one of the ancestors of node
            if( discovery[node] < low[x] ) {
                bridge.push_back( make_pair(node,x) );

            }
        }
        else if( discovery[x]>-1 && x!=parent[node] ) { // back-edge found, so updates low value of node
            low[node] = min(low[node], discovery[x]);
        }
    }
}

void Articulation(ll vertex, vector<pair<ll,ll>> &bridge, vector<ll> v[])// the function to do DFS traversal
{
    vector<ll> parent(vertex,-1);// stores parent vertices in DFS tree
    vector<ll> discovery(vertex,-1);// stores discovery times of visit vertices
    vector<ll> low(vertex);
    vector<bool> visit(vertex,false);// keeps track of visit vertices
    for(ll i=0; i<vertex; i++) {
        if( discovery[i]==-1 ) {
            _Articulation(i, parent, discovery, low, bridge, v);// calls the recursive helper function to find articulation points in DFS tree rooted with vertex 'i'
        }
    }
}

void eBridge(ll vertex, vector<pair<ll,ll>> bridge, vector<ll> v[], vector<ll> u[])
{
    for(ll i=0; i<vertex; i++) {
        u[i] = v[i];
    }
    for(ll i=0; i<bridge.size(); i++) {
        pair<ll,ll> p = bridge[i];
        u[p.first].erase( find(u[p.first].begin(), u[p.first].end(), p.second) );
        u[p.second].erase( find(u[p.second].begin(), u[p.second].end(), p.first) );
    }
}

vector<vector<pair<ll,ll>>> Discrete(ll vertex, vector<ll> u[], vector<ll> &mark)
{
    vector<vector<pair<ll,ll>>> component;
    vector<bool> visit(vertex,false);
    ll cont = 0;
    for(ll i=0; i<vertex; i++) {
        if( visit[i]==false ) {
            vector<pair<ll,ll>> omg;
            queue<ll> q;
            q.push(i);
            while( !q.empty() ) {
                ll x = q.front();
                q.pop();
                visit[x]=true;
                mark[x] = cont;
                for(ll j=0; j<u[x].size(); j++) {
                    if( visit[ u[x][j] ]==false ) {
                        q.push( u[x][j] );
                        omg.push_back( make_pair(x,u[x][j]) );
                    }
                }
            }
            if( !omg.empty() )
                component.push_back(omg);
            else {
                omg.push_back( make_pair(i,i) );
                component.push_back(omg);
            }
            cont++;
        }
    }
    return component;
}

ll ExtraEdge(ll n, vector<ll> mark, vector<pair<ll,ll>> bridge)
{
    ll ans=0;
    vector<ll> leaf(n,0);
    for(ll i=0; i<bridge.size(); i++) { //calculates the degree of every component
        pair<ll,ll> p = bridge[i];
        leaf[ mark[p.first] ]++;
        leaf[ mark[p.second] ]++;
    }
    for(ll i=0; i<n; i++) {
        if( leaf[i]==1 )// 0 degree: biconnected component | 1 degree: leaf component | >1 degree: ordinary component
            ans++;
    }
    return ans%2 ? (ans+1)/2 : ans/2;
}

void print(vector<vector<pair<ll,ll>>> component)
{
    for(ll i=0; i<component.size(); i++) {
        vector<pair<ll,ll>> omg = component[i];
        for(ll j=0; j<omg.size(); j++) {
            pair<ll,ll> p = omg[j];
            if(p.first != p.second)
                cout << p.first << "-" << p.second << spc;
            else
                cout << p.first << spc;
        }
        cout << lne;
    }
}

int main()
{
//    inout
    fileopenX

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<ll> v[vertex];
    store(edge, v);

    vector<pair<ll,ll>> bridge;// stores articulation bridges
    Articulation(vertex, bridge, v);

    vector<ll> u[vertex];
    eBridge(vertex, bridge, v, u);// excludes articulation bridges from the given graph

    vector<ll> mark(vertex);
    vector<vector<pair<ll,ll>>> component = Discrete(vertex, u, mark);// ExtraEdgects the components from the graph u
    print(component);

    ll ans = ExtraEdge(component.size(), mark, bridge);// calculates the number of extra-edges to make the given graph, a biconnected graph
    cout << "extra-edge " << ans << lne;

    filecloseX
    return 0;
}
/*
19

4 3
1 2
2 3
2 0

4 3
1 2
2 3
0 1

5 4
0 1
0 2
0 3
0 4

10 10
0 1
0 2
1 2
2 3
1 4
4 5
5 6
4 7
7 8
8 9

10 11
0 1
0 2
1 2
2 3
1 4
4 5
5 6
4 7
7 8
8 7
8 9

10 13
0 1
0 4
1 2
2 3
1 3
4 5
4 6
5 6
5 7
7 8
5 8
6 9
8 9

7 9
0 1
1 2
0 2
0 3
0 4
3 4
0 5
0 6
5 6

7 6
0 1
0 2
0 3
0 4
0 5
0 6

4 3
1 2
2 3
2 0

3 3
1 2
2 0
0 1

13 17
8 0
9 6
8 6
3 10
10 11
11 3
2 4
4 5
5 2
1 6
6 7
1 7
0 1
1 2
2 3
3 0
3 12

5 4
0 1
1 2
2 3
3 4

4 4
0 1
0 2
1 2
2 3

7 6
0 1
0 2
0 3
0 4
4 5
4 6

6 5
0 1
1 2
1 3
2 4
3 5

10 9
0 1
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9

8 10
3 1
1 7
7 4
4 6
1 5
5 0
3 2
7 6
4 1
4 3

6 7
1 0
1 3
3 4
0 2
4 5
4 1
3 0

10 10
9 8
8 1
9 5
5 4
5 0
0 3
4 6
8 7
6 2
0 8
*/

