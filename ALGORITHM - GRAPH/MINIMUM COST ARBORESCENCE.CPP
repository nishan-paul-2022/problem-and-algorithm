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

class graph { public: ll ux, vx, weight; };

vector<graph> store(ll edge)
{
    vector<graph> v;
    for(ll i=0; i<edge; i++) {
        graph g;
        cin >> g.ux >> g.vx >> g.weight;
        v.push_back(g);
    }
    return v;
}

ll _MCA(ll root, ll vertex, ll edge, vector<graph> v)
{
	ll cost = 0;
    vector<ll> parent(vertex);
	while(1) {
	    vector<ll> in(vertex,infp);
		for(ll i = 0; i < edge; i++) {
			ll ux = v[i].ux;
			ll vx = v[i].vx;
			ll weight = v[i].weight;
			if( ( weight < in[vx] ) && ux!=vx ) { //find the smallest edge, delete the ring
				in[vx] = weight;
				parent[vx] = ux;
			}
		}
		for(ll i = 0; i < vertex; i++) { //if there is no minimum entry, it means that the poll is not connected, the smallest tree does not fail
			if( i!=root && in[i]==infp )
                return -1;
		}
		ll cnt = 0;//record shrink polls
		vector<ll> id(vertex,-1);
		vector<ll> visit(vertex,-1);
		in[root] = 0;//tree root can not have edge
		for(ll i = 0; i < vertex; i++) {
			cost += in[i];
			ll node = i;
			while( visit[node]!=i && id[node]==-1 && node!=root ) { //find the ring
				visit[node] = i;
				node = parent[node];
			}
			if( node!=root && id[node]==-1 ) { //find the ring
				for(ll j=parent[node]; j!=node; j=parent[j]) {
                    id[j] = cnt;
				}
				id[node] = cnt++;
			}
		}
		if( cnt==0 ) break; //if there is no self-loop, said the smallest tree shape to succeed
		for(ll i = 0; i < vertex; i++) { //find those that are not self-looped and re-mark those polls
            if( id[i]==-1 )
                id[i] = cnt++;
		}
		for(ll i = 0; i < edge; i++) {
			ll node = v[i].vx;
			v[i].vx = id[ v[i].vx ];
			v[i].ux = id[ v[i].ux ];
			if( v[i].ux != v[i].vx )
                v[i].weight -= in[node];
		}
		vertex = cnt; //after the end of the poll, the number of polls on the side
		root = id[root];
	}
	return cost;
}

vector<pair<ll,ll>> MCA(ll vertex,ll edge,vector<graph> v)
{
    vector<pair<ll,ll>> path;
    for(ll i=0; i<vertex; i++) {
        ll cost = _MCA(i, vertex, edge, v);
        path.push_back( make_pair(i,cost) );
    }
    return path;
}

void print(vector<pair<ll,ll>> path)
{
    for(ll i=0; i<path.size(); i++){
        cout<<path[i].first<<": "<<path[i].second<<lne;
    }
}

int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<graph> v = store(edge);
    vector<pair<ll,ll>> path = MCA(vertex, edge, v);
    print(path);

    fileclose
    return 0;
}
/*
19
4 14
3 1 4
3 1 3
3 2 3
3 2 6
1 3 9
3 1 5
2 0 9
0 1 8
0 2 8
3 1 2
2 1 3
1 3 7
1 3 5
1 0 1
4 17
3 0 6
3 0 3
1 2 8
2 3 4
0 1 4
0 1 3
3 2 7
3 1 4
1 2 2
1 0 8
0 2 3
3 1 3
3 2 6
3 2 2
3 1 0
3 0 7
3 1 0
4 18
0 2 0
3 2 3
3 2 4
3 2 8
3 2 2
0 1 8
1 2 2
0 1 3
1 3 8
3 0 2
0 2 6
0 2 0
1 3 0
2 3 9
1 0 5
0 3 8
1 2 0
0 2 4
5 19
4 3 1
1 0 4
3 4 7
4 2 6
4 0 6
3 0 2
0 2 4
2 3 9
0 1 7
4 2 2
1 0 7
2 3 2
4 2 5
2 3 7
1 2 2
3 4 6
3 4 6
1 0 6
1 2 9
5 22
1 4 6
4 1 5
3 0 9
0 4 8
1 3 1
1 3 7
1 4 9
4 0 2
3 0 9
4 0 2
1 0 8
3 2 9
1 0 1
3 2 6
0 3 9
2 4 4
1 4 3
0 1 0
1 3 2
3 2 3
3 1 0
4 2 9
5 24
3 0 3
2 1 2
1 0 7
0 3 6
3 0 9
2 4 0
0 1 9
3 0 4
1 4 2
3 2 3
2 0 3
1 4 9
2 0 9
3 4 1
1 0 0
1 0 7
4 0 1
3 0 2
0 1 0
0 1 1
4 1 4
3 4 0
1 0 4
0 2 5
5 27
2 0 6
2 0 3
1 4 6
3 4 0
3 0 2
0 1 8
0 4 1
1 0 0
3 0 9
3 2 0
2 0 2
3 2 4
3 0 5
2 4 4
4 1 8
0 3 9
4 0 8
2 3 4
4 3 7
0 1 8
4 0 4
1 2 0
0 3 0
2 1 3
0 4 2
3 1 5
4 0 0
5 30
1 3 5
1 2 4
4 0 6
4 3 3
2 3 2
1 2 1
0 2 6
3 0 9
3 1 4
4 3 9
0 3 4
1 3 3
3 1 5
1 4 5
0 2 7
4 3 8
2 0 5
2 4 3
3 4 7
1 0 6
4 2 1
0 2 4
2 3 8
1 0 1
0 1 6
4 2 0
4 2 3
3 1 6
4 3 7
4 1 6
5 32
1 2 2
3 0 3
3 4 4
0 4 6
4 0 8
1 3 1
3 0 5
4 0 3
2 4 9
0 4 4
0 4 1
3 0 9
0 3 4
4 0 5
2 3 4
1 2 2
1 3 2
0 4 2
4 3 9
2 4 0
3 4 7
0 3 2
0 2 6
2 4 9
1 4 7
4 3 7
1 4 5
3 2 3
2 3 1
0 1 4
3 4 8
4 0 3
5 32
1 4 7
0 1 8
4 0 8
1 2 7
2 3 6
3 4 0
1 2 8
1 4 6
3 0 8
3 4 7
4 1 9
4 2 1
1 2 1
1 0 4
3 2 2
4 1 9
2 0 5
0 2 8
3 1 0
0 2 2
4 1 9
4 0 5
2 0 0
2 3 7
2 1 4
0 2 1
0 2 8
1 2 6
0 3 8
3 1 3
3 0 4
2 4 5
5 36
3 2 0
0 1 9
3 0 3
4 3 8
0 1 0
0 2 4
4 0 9
3 4 9
4 2 2
2 1 5
1 2 1
1 2 9
4 0 2
2 0 0
2 4 3
2 0 2
0 2 0
3 0 3
3 4 1
1 0 2
3 2 6
3 1 4
4 2 4
1 2 2
3 1 8
3 0 1
2 3 4
4 0 1
3 2 0
4 2 2
2 0 7
0 2 5
1 2 2
2 1 6
2 4 8
2 3 7
5 40
2 4 5
1 3 4
0 3 8
4 2 5
3 4 6
4 3 4
0 2 8
0 2 0
1 0 5
4 1 6
3 2 6
1 2 4
0 1 2
4 1 9
3 4 8
4 1 4
4 0 1
4 3 5
1 0 0
4 3 6
4 2 8
0 2 4
4 2 9
1 0 3
4 2 1
3 0 8
2 4 1
4 2 6
0 4 9
4 2 3
3 2 4
4 0 2
1 4 7
1 4 4
0 4 5
3 4 5
3 4 1
4 3 2
3 4 9
0 3 7
5 40
4 3 5
3 2 2
0 1 0
1 3 3
4 0 0
2 1 4
2 3 4
4 2 3
3 4 3
0 3 4
2 3 8
0 2 7
1 3 2
2 4 8
0 1 1
0 3 3
2 4 5
3 4 3
3 2 5
4 2 8
1 3 2
1 2 5
0 4 4
3 1 1
4 2 7
2 4 3
3 0 0
2 1 6
3 1 7
1 4 1
0 1 9
3 1 4
0 1 3
0 2 6
2 4 6
2 4 2
1 4 6
2 3 8
2 0 7
0 2 2
5 44
3 0 7
0 2 8
4 0 5
1 3 9
4 3 1
1 2 6
4 0 9
0 3 1
2 4 3
0 2 1
4 2 6
2 1 0
3 4 1
1 2 7
2 0 2
2 1 9
4 0 8
0 2 6
2 3 1
3 2 9
2 3 0
2 1 1
2 3 0
2 4 7
3 2 5
1 4 8
4 3 7
4 0 0
2 1 7
3 2 4
3 2 3
2 3 3
2 3 9
0 2 0
1 0 0
3 1 0
0 3 8
1 3 7
1 3 3
2 3 4
0 4 3
2 1 9
4 1 3
2 0 0
5 44
4 0 2
0 4 4
0 3 5
2 3 6
1 2 6
2 3 5
4 1 2
0 2 8
1 2 7
4 2 5
1 3 6
0 2 2
1 3 3
0 4 2
4 2 2
1 2 0
1 4 7
4 0 5
4 2 4
3 1 5
2 1 5
4 2 7
0 1 6
2 3 2
2 0 8
4 3 0
3 0 0
1 0 1
3 0 7
0 1 2
2 3 9
1 2 4
0 4 3
0 3 6
3 1 6
3 0 7
1 4 8
0 1 2
4 0 2
1 0 2
3 4 9
0 2 5
2 3 8
0 4 9
2 1
0 1 10
2 1
1 0 10
4 4
0 1 10
0 2 10
1 3 20
2 3 30
4 4
0 1 10
1 2 20
2 0 30
2 3 100
*/
