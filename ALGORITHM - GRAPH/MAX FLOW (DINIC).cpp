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
//CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | POSITVE-WEIGHTED | NO-LOOP
//CAN IDENTIFY THE MAX-FLOW OF A GIVEN FLOW-NETWORK
//TIME COMPLEXITY: O(V*E*V)
class adjacent// A structure to represent a edge between two vertex
{
    public:
        ll vx ;// Vertex v of a directed edge u-v. vertex u can be obtained using index in adjacent array.
        ll flow ;// flow of data in edge
        ll capacity;// capacity
        ll revrse ; // To store index of reverse edge in adjacency list so that we can quickly find it.
};

void store(ll edge, vector<adjacent> graph[])
{
    for(ll i = 0; i < edge; i++) {
        ll ux, vx, capacity;
        cin >> ux >> vx >> capacity;
        adjacent a{ vx, 0, capacity, graph[vx].size() };// Forward edge : 0 flow and C capacity
        adjacent b{ ux, 0, 0, graph[ux].size() };// Back edge : 0 flow and 0 capacity
        graph[ux].push_back(a);
        graph[vx].push_back(b);// reverse edge
    }
}

bool BFS(ll s, ll t, vector<ll> &level, vector<adjacent> graph[])// Finds if more flow can be sent from s to t. Also assigns levels to nodes.
{
    fill(level.begin(), level.end(), -1);
    level[s] = 0; // Level of source vertex
    queue<ll> q;// Create a queue, enqueue source vertex and mark source vertex as visited. Here level[] array works as visited array also.
    q.push(s);
    while( !q.empty() ) {
        ll ux = q.front();
        q.pop();
        for(ll i = 0; i < graph[ux].size(); i++) {
            adjacent e = graph[ux][i];
            if(level[e.vx] < 0 && e.flow < e.capacity) {
                level[e.vx] = level[ux] + 1;// Level of current vertex is, level of parent + 1
                q.push(e.vx);
            }
        }
    }
    return level[t] >= 0 ; // if we can not reach to the sink we return false else true
}

ll sendFlow(ll ux, ll t, ll flow, vector<ll> level, vector<adjacent> graph[], vector<ll> &omg)// flow: Current flow send by parent function call | ux: Current vertex | t: Sink
{
    if(ux == t) {// Sink reached
        omg.push_back(ux);
        return flow;
    }
    for(ll i = 0; i < graph[ux].size(); i++) { // Traverse all adjacent edges one -by - one.
        adjacent &e = graph[ux][i];// Pick next edge from graphacency list of u
        if(level[e.vx] == level[ux]+1 && e.flow < e.capacity) {
            ll curr_flow = min(flow, e.capacity - e.flow);// find minimum flow from u to t
            ll temp_flow = sendFlow(e.vx, t, curr_flow, level, graph, omg);
            if(temp_flow > 0) { // flow is greater than zero
                e.flow += temp_flow;// add flow to current edge
                graph[e.vx][e.revrse].flow -= temp_flow;// subtract flow from reverse edge of current edge
                omg.push_back(ux);
                return temp_flow;
            }
        }
    }
    return 0;
}

ll Dinic(ll vertex, ll s, ll t, vector<adjacent> graph[], vector<pair<ll,vector<ll>>> &road)// Returns maximum flow in graph
{
    if(s == t)// Corner case
        return -1;
    ll total = 0; // Initialize result
    vector<ll> level(vertex);// stores level of a node
    while( BFS(s, t, level, graph) == true ) { // Augment the flow while there is path from source to sink
        vector<ll> omg;
        while ( ll flow = sendFlow(s, t, infp, level, graph, omg) ) { // while flow is not zero in graph from S to D
            total += flow;// Add path flow to overall flow
            road.push_back( make_pair(flow,omg) );
            omg.erase(omg.begin(), omg.end());
        }
    }
    return total;// return maximum flow
}

void print(vector<pair<ll,vector<ll>>> road)
{
    for(ll i = 0; i < road.size(); i++) {
        cout << road[i].first << " - ";
        vector<ll> omg = road[i].second;
        for(ll j = 0; j < omg.size(); j++) {
            cout << omg[j] << spc;
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
    vector<adjacent> graph[vertex];
    store(edge, graph);

    ll s, t;
    cin >> s >> t;
    vector<pair<ll,vector<ll>>> road;
    ll maxflow = Dinic(vertex, s, t, graph, road);// A DFS based function to send flow after BFS has figured out that there is a possible flow and constructed levels. This function called multiple times for a single call of BFS.
	cout << "The maximum possible flow is " << maxflow << lne;
	print(road);

	filecloseX
	return 0;
}

/*
6 10
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5

6 10
0 1 3
0 2 7
1 3 9
1 4 9
2 1 9
2 4 9
2 5 4
3 5 3
4 5 7
0 4 10
0 5

6 9
0 1 10
0 2 10
1 3 4
1 4 8
1 2 2
2 4 9
3 5 10
4 3 6
4 5 10
0 5
*/
