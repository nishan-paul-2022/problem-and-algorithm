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

void store(ll edge, vector<ll> adjacent[])
{
    for(ll i=0; i<edge; i++) {
        ll ux, vx;
        cin >> ux >> vx;
        adjacent[ux].push_back(vx);
    }
}

bool bfs(ll m, vector<ll> pairU, vector<ll> pairV, vector<ll> &distance, vector<ll> adjacent[])// Returns true if there is an augmenting path, else returns false
{
	queue<ll> Q; //an lleger queue
	for( ll u=0; u < m; u++ ) { // First layer of vertices (set distanceance as 0)
		if( pairU[u]==0 ) { // If this is a free vertex, add it to queue
			distance[u] = 0;// u is not matched
			Q.push(u);
		}
		else
            distance[u] = infp;// Else set distanceance as infpinite so that this vertex is considered next time
	}
	distance[0] = infp;// Initialize distanceance to 0 as infinite
	while ( !Q.empty() ) { // Q is going to contain vertices of left side only.
		ll u = Q.front();
		Q.pop();
		if( distance[u] < distance[0] )	{ // If this node is not 0 and can provide a shorter path to 0
			for( ll i = 0; i < adjacent[u].size(); i++ ) { // Get all adjacentacent vertices of the dequeued vertex u
				ll v = adjacent[u][i];
				if( distance[ pairV[v] ] == infp ) { // If pair of v is not considered so far (v, pairV[V]) is not yet explored edge.
					distance[ pairV[v] ] = distance[u] + 1;// Consider the pair and add it to queue
					Q.push(pairV[v]);
				}
			}
		}
	}
	return distance[0] != infp;// If we could come back to 0 using alternating path of distinct vertices then there is an augmenting path
}

bool dfs(ll u, vector<ll> &pairU, vector<ll> pairV, vector<ll> &distance, vector<ll> adjacent[])// Returns true if there is an augmenting path beginning with free vertex u
{
	if( u != 0) {
		for( ll i = 0; i < adjacent[u].size(); i++ ) {
			ll v = adjacent[u][i];
			if( distance[ pairV[v] ] == distance[u] + 1 ) { // Follow the distanceances set by BFS
				if( dfs(pairV[v], pairU, pairV, distance, adjacent)==true ) { // If dfs for pair of v also returns true
					pairV[v] = u;
					pairU[u] = v;
					return true;
				}
			}
		}
		distance[u] = infp;// If there is no augmenting path beginning with u.
		return false;
	}
	return true;
}

ll hopcroftKarp(ll m, ll n, vector<ll> adjacent[])// Returns size of maximum matching
{
	vector<ll> pairU(m,0);// pairU[u] stores pair of u in matching where u is a vertex on left side of Bipartite Graph. If u doesn't have any pair, then pairU[u] is 0
	vector<ll> pairV(n,0);// pairV[v] stores pair of v in matching. If v doesn't have any pair, then pairU[v] is 0
	vector<ll> distance(m);// distance[u] stores distanceance of left side vertices. distance[u] is one more than distance[v] if u is next to v in augmenting path
	ll result = 0;// Initialize result
	while( bfs(m, pairU, pairV, distance, adjacent) ) { // Keep updating the result while there is an augmenting path.
		for( ll u=0; u < m; u++ ) { // Find a free vertex
			if( pairU[u]==0 && dfs(u, pairU, pairV, distance, adjacent) )// If current vertex is free and there is an augmenting path from current vertex
				result++;
		}
	}
	return result;
}

int main()
{
//    inout
    fileopen

    ll m, n, edge;// m and n are number of vertices on left and right sides of Bipartite Graph
    cin >> m >> n >> edge;
    vector<ll> adjacent[m];// adjacent[u] stores adjacentacents of left side vertex 'u'. The value of u ranges from 1 to m. 0 is used for dummy vertex
    store(edge, adjacent);

	cout << "Size of maximum matching is " << hopcroftKarp(m, n, adjacent);// C++ implementation of Hopcroft Karp algorithm for maximum matching

	fileclose
	return 0;
}
/*
4 4 6
0 1
0 2
1 0
2 1
3 1
3 3
*/
