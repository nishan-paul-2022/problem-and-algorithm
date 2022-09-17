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

//CONNECTED/CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | POSITVE-WEIGHTED | NO-LOOP
//CAN IDENTIFY THE SHORTEST PATH FROM THE STARTING NODE TO ALL OTHER REACHABLE NODES
//TIME COMPLEXITY: O( V.LOGV + E)
class compare{ public: bool operator()(pll a,pll b) { return a.second < b.second; } };
class graph
{
    public:
        ll bro, weight;
        graph() {}
        graph(ll u,ll w) { bro=u, weight=w; }
};
void store(ll vertex,ll edge,vector<graph> v[])
{
    for(ll i=0; i<edge; i++){
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].push_back( graph(y,w) );
//        v[y].push_back( graph(x,w) );//for undirected graph only
    }
}
void dijkstra(ll start,vector<graph> v[],vector<ll> &distance,vector<ll> &parent)
{
    parent[start]=start;
	priority_queue< pair<ll,ll>, vector <pair<ll,ll>> , compare > p; // Create a priority queue to store nodes that are being preprocessed
	p.push( make_pair(start,0) );// Insert source itself in priority queue and initialize its distance as 0
	distance[start] = 0;
	while( !p.empty() ) {// Looping till priority queue becomes empty (or all distances are finalized)
		ll omg = p.top().first;
		p.pop();
		vector<graph> adjacent = v[omg];
		for(ll i=0; i<adjacent.size(); i++) {// Get all adjacent of omg
			ll node = adjacent[i].bro;// Get node label and weight of current adjacent of omg
			ll weight = adjacent[i].weight;
			if(distance[node] > distance[omg] + weight){// If there is shorter path to node through omg
				parent[node] = omg;
				distance[node] = distance[omg] + weight;// Updating distance of node
				p.push( make_pair(node,distance[node]) );
			}
		}
	}
}
void roadmap(ll start,ll vertex,vector<ll> distance,vector<ll> parent)// prints shortest paths from starting node to all other nodes
{
    for(ll i=0; i < vertex; i++){
        if( distance[i] != infp && start != i ){
            cout << start << "-" << i << " distance: " << distance[i] << " and path: ";
            ll child = i;
            while( parent[child] != child ) {
                cout << child << spc;
                child = parent[child];
            }
            cout << start << lne;
        }
    }
}
int main()
{
//    inout
    fileopen

    ll vertex, edge, start;
    cin>>vertex>>edge;
    vector<graph> v[vertex];
    store(vertex,edge,v);

    cin>>start;
    vector<ll> distance(vertex,infp), parent(vertex);
    dijkstra(start,v,distance,parent);
    roadmap(start,vertex,distance,parent);

	fileclose
	return 0;
}
/*
undirected
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0
ans: 0 4 12 19 21 11 9 8 14

directed
7 11
0 1 1
0 2 5
0 3 4
1 2 2
1 2 1
2 6 20
2 3 3
5 3 6
4 5 9
3 6 7
6 2 8
0
ans: 0 1 2 4 x x 11
*/
