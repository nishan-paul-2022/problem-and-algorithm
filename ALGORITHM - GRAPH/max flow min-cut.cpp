///CUET-IRON-BAT
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

ll** allocate(ll n)
{
    ll **a = new ll*[n];
    for(ll i=0; i<n; i++) {
        *(a+i) = new ll[n];
        fill(a[i], a[i]+n, 0);
    }
    return a;
}
ll** store(ll vertex, ll edge)
{
    ll **graph = allocate(vertex);
	for(ll i=0; i<edge; i++) {
        ll ux, vx, weight;
        cin >> ux >> vx >> weight;
        graph[ux][vx] = weight;
	}
	return graph;
}

/* Returns true if there is a path from source 's' to sink 't' in residual graph. Also fills parent[] to store the path */
bool bfs(ll vertex, ll **rGraph, ll s, ll t, vector<ll> &parent)// Returns true if there is a path from source 's' to sink 't' in residual graph. Also fills parent[] to store the path
{
	vector<bool> visit(vertex,false);// Create a visit array and mark all vertices as not visit
	queue <ll> q;// Create a queue, enqueue source vertex and mark source vertex as visit
	q.push(s);
	visit[s] = true;
	parent[s] = -1;
	while ( !q.empty() ) { // Standard BFS Loop
		ll u = q.front();
		q.pop();
		for (ll v=0; v<vertex; v++) {
			if (visit[v]==false && rGraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visit[v] = true;
			}
		}
	}
	return visit[t] == true;// If we reached sink in BFS starting from source, then return true, else false
}

void dfs(ll **rGraph, ll vertex, ll s, vector<bool> &visit)// A DFS based function to find all reachable vertices from s. The function marks visit[i] as true if i is reachable from s. The initial values in visit[] must be false. We can also use BFS to find reachable vertices
{
	visit[s] = true;
	for (ll i = 0; i < vertex; i++) {
        if( visit[i]==false && rGraph[s][i] )
            dfs(rGraph, vertex, i, visit);
	}
}

ll minCut(ll **graph, ll vertex, int s, int t)// Prints the minimum s-t cut
{
	ll u, v;
	// Create a residual graph and fill the residual graph with given capacities in the original graph as residual capacities in residual graph
	ll **rGraph = allocate(vertex); // Residual graph where rGraph[i][j] indicates residual capacity of edge from i to j (if there is an edge. If rGraph[i][j] is 0, then there is not)
	for (ll i = 0; i < vertex; i++)
		for (ll j = 0; j < vertex; j++)
			rGraph[i][j] = graph[i][j];
	ll max_flow = 0; // There is no flow initially
	vector<ll> parent(vertex); // This array is filled by BFS and to store path
	while ( bfs(vertex, rGraph, s, t, parent) ) { // Augment the flow while tere is path from source to sink
		ll path_flow = infp;// Find minimum residual capacity of the edges along the path filled by BFS. Or we can say find the maximum flow through the path found.
		for (ll v=t; v!=s; v=parent[v]) {
			ll u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		for (ll v=t; v != s; v=parent[v]) { // update residual capacities of the edges and reverse edges along the path
			ll u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;// Add path flow to overall flow
	}
	vector<bool> visit(vertex,false);// Flow is maximum now, find vertices reachable from s
	dfs(rGraph, vertex, s, visit);
	for (ll i = 0; i < vertex; i++) {// Print all edges that are from a reachable vertex to non-reachable vertex in the original graph
        for (ll j = 0; j < vertex; j++) {
            if( visit[i]==true && visit[j]==false && graph[i][j] )
                cout << i << "-" << j << lne;
        }
	}
	return max_flow;
}

int main()// C++ program for finding minimum cut using Ford-Fulkerson
{
//    inout
    fileopenX

    ll vertex, edge;
    cin >> vertex >> edge;
	ll **graph = store(vertex, edge);

	ll s, t;
	cin >> s >> t;
	cout << minCut(graph, vertex, s, t) << lne;

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

6 7
0 1 2
1 4 1
4 5 4
0 2 5
2 3 3
3 5 4
1 3 3
0 5
*/

