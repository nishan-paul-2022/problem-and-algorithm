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
//CONNECTED | UNDIRECTED | NEGATIVE-WEIGHTED/POSITVE-WEIGHTED | NO-LOOP
//CAN IDENTIFY MINIMUM SPANNING TREE OF A GIVEN GRAPH
//TIME COMPLEXITY: O( E.LOG(V) )
class compare{ public: bool operator()(pll a,pll b) { return a.second < b.second; } };
class graph
{
    public:
        ll bro, weight;
        graph() {}
        graph(ll bro,ll weight) { this->bro=bro, this->weight=weight; }
};
void store(ll vertex,ll edge,vector<graph> v[])
{
    for(ll i=0; i<edge; i++){
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].push_back( graph(y,w) );
        v[y].push_back( graph(x,w) );
    }
}
class figure
{
    public:
        ll key, parent;
        bool inMST;
        figure() { key=infp, parent=-1, inMST=false; }
};
void primMST(ll vertex, vector<graph> v[], figure omg[])
{
	priority_queue< pair<ll,ll>, vector<pair<ll,ll>> , compare > pq;
	pq.push( make_pair(0,0) );
	omg[0].key = 0;
	while( !pq.empty() ) {
		ll u = pq.top().first;
		pq.pop();
		omg[u].inMST = true;
		vector<graph> node = v[u];
		for(ll i=0; i<node.size(); i++) {
			ll bro = node[i].bro;
			ll weight = node[i].weight;
			if(omg[bro].inMST == false && omg[bro].key > weight) {
				omg[bro].key = weight;
				omg[bro].parent = u;
				pq.push( make_pair(bro,omg[bro].key) );
			}
		}
	}
}
void print(ll vertex, figure omg[])
{
    for(ll i=1; i<vertex; i++) {
        cout<<i<<"-"<<omg[i].parent<<": "<<omg[i].key<<lne;
    }
}
int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin>>vertex>>edge;
    vector<graph> v[vertex];
    store(vertex,edge,v);

    figure omg[vertex];
	primMST(vertex, v, omg);
	print(vertex, omg);

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
*/
