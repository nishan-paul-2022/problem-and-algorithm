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
//DISCONNECTED/CONNECTED | UNDIRECTED | NEGATIVE-WEIGHTED/POSITVE-WEIGHTED/UNWEIGHTED | SELF-LOOP/NO-LOOP
//CAN IDENTIFY THE COMPONENTS OF A GIVEN GRAPH
//TIME COMPLEXITY: O(V+E)
class graph { public: ll ux, vx; };
vector<graph> store(ll vertex,ll edge)
{
    vector<graph> v;
    for(ll i=0; i<edge; i++) {
        graph g;
        cin>>g.ux>>g.vx;
        v.push_back(g);
    }
    return v;
}
class subset { public: ll parent, order; };
void Union(subset sets[], ll x, ll y)// a function that does union of two sets of x and y (uses union by order)
{
	if(sets[x].order < sets[y].order)// attach smaller order tree under root of high order tree (Union by order)
		sets[x].parent = y;
	else if(sets[x].order > sets[y].order)
		sets[y].parent = x;
	else {// if orders are same, then make one as root and increment its order by one
		sets[y].parent = x;
		sets[x].order++;
	}
}
bool disjoint(ll vertex, ll edge, vector<graph> v, subset sets[])// a union-by-order based function to create disjoint sets of a graph
{
    bool flag=false;
	for(ll i=0; i<vertex; i++) {
		sets[i].parent = i;
		sets[i].order = 0;
	}
	for(ll i=0; i<edge; i++) {
		ll x = sets[ v[i].ux ].parent;// find sets of both vertices of every edge,
		ll y = sets[ v[i].vx ].parent;
		if(x==y) flag=true;// if sets are same, then there is cycle in graph.
		Union(sets, x, y);
	}
	return flag;
}
bool isSame(ll nodex, ll nodey, subset sets[])// checking if two different nodes are in the same component
{
    ll x = sets[nodex].parent;
    ll y = sets[nodey].parent;
    return x==y;
}
ll component(ll vertex, subset sets[])// to find out number of components in a graoh
{
    ll n=0;
    for(ll i=0; i<vertex; i++) {
		if(sets[i].order)
            n++;
	}
	return n;
}
int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin>>vertex>>edge;
    vector<graph> v = store(vertex,edge);

    subset sets[vertex];
    bool flag = disjoint(vertex, edge, v, sets);
    cout << component(vertex,sets) << lne;
    cout << boolalpha << flag << lne;
	ll nodex, nodey;
	cin>>nodex>>nodey;
	cout << isSame(nodex, nodey, sets) << lne;

    fileclose
	return 0;
}
/*
undirected

9 8
0 1
1 2
2 3
3 0
4 4
4 5
5 6
7 8
0 8

4 3
0 1
1 2
2 3
0 1
*/
