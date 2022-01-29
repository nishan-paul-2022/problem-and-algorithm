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
//CAN IDENTIFY THE BICONNECTED COMPONENTS OF THE GIVEN GRAPH
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

void _Articulation(ll node, vector<ll> &parent, vector<ll> &discovery, vector<ll> &low, vector<pair<ll,ll>> &omg, vector<vector<pair<ll,ll>>> &god, vector<ll> v[])
{
    ll child = 0;
    static ll flag = 0;
    discovery[node] = low[node] = flag++;
	for(ll i=0; i<v[node].size(); i++) {
		ll x = v[node][i];
        if( discovery[x]==-1 ) { // if x is not visited yet, then make it a child of node in DFS tree
            child++;
            parent[x] = node;
			omg.push_back( make_pair(node,x) );// omg to store visited edges
			_Articulation(x, parent, discovery, low, omg, god, v);
			low[node] = min(low[node], low[x]);// checks if the subtree rooted with x has a connection to one of the ancestors of node
			if ( ( parent[node]==-1 && child>1 ) || ( parent[node]!=-1 && discovery[node] <= low[x] ) ) { // If u is an articulation point, pop all edges from stack till u -- v
				vector<pair<ll,ll>> how;
				while ( omg.back().first != node || omg.back().second != x ) {
					how.push_back(omg.back());
					omg.pop_back();
				}
				how.push_back(omg.back());
				omg.pop_back();
				god.push_back(how);
			}
		}
		else if( discovery[x]>-1 && x!=parent[node] ) { // back-edge found, so updates low value of node
            low[node] = min(low[node], discovery[x]);
            if ( discovery[x] < discovery[node] )
				omg.push_back( make_pair(node,x) );
        }
	}
}

void Articulation(ll vertex, vector<vector<pair<ll,ll>>> &god, vector<ll> v[])// the function to do DFS traversal
{
    vector<pair<ll,ll>> omg;
    vector<ll> parent(vertex,-1);// stores parent vertices in DFS tree
    vector<ll> discovery(vertex,-1);// stores discovery times of visit vertices and keeps track of visit vertices
    vector<ll> low(vertex);
    for(ll i=0; i<vertex; i++) {
        if( discovery[i]==-1 ) {
            _Articulation(i, parent, discovery, low, omg, god, v);// calls the recursive helper function to find articulation points in DFS tree rooted with vertex 'i'
        }
        if( !omg.empty() ) {
            god.push_back(omg);
            omg.erase( omg.begin(), omg.end() );
        }
    }
}

void print(vector<vector<pair<ll,ll>>> god)
{
    cout << god.size() << lne;
    for(ll i=0; i<god.size(); i++) {
        for(ll j=0; j<god[i].size(); j++) {
            cout << god[i][j].first << "-" << god[i][j].second << spc;
        }
        cout << lne;
    }
}

int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<ll> v[vertex];
    store(edge, v);

    vector<vector<pair<ll,ll>>> god;
    Articulation(vertex, god, v);
	print(god);

	fileclose
	return 0;
}
/*
12 14
0 1
1 2
1 3
2 3
2 4
3 4
1 5
0 6
5 6
5 7
5 8
7 8
8 9
10 11

12 14
0 1
0 6
1 2
1 3
1 5
2 3
2 4
3 4
5 6
5 7
5 8
7 8
8 9
10 11
*/
