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
//TIME COMPLEXITY: O( E.LOG(E) ) and O( E.E.LOG(E) )
class subset { public: ll parent, order; };
class graph { public: ll ux,vx,weight; graph() { ux = vx = weight = 0; } };
class compare { public: bool operator()(graph a,graph b) { return a.weight < b.weight; } };
class xcompare { public: bool operator()(pair<vector<graph>,ll> a,pair<vector<graph>,ll> b) { return a.second > b.second; } };

vector<graph> store(ll vertex,ll edge)
{
    vector<graph> v;
    for(ll i=0; i<edge; i++){
        graph g;
        cin>>g.ux>>g.vx>>g.weight;
        v.push_back(g);
    }
    return v;
}

void Union(subset sets[], ll x, ll y)
{
	if(sets[x].order < sets[y].order)
		sets[x].parent = y;
	else if(sets[x].order > sets[y].order)
		sets[y].parent = x;
	else {
		sets[y].parent = x;
		sets[x].order++;
	}
}

ll KruskalMST(ll vertex, ll edge, vector<graph> v,vector<graph> &omg, graph g=graph())
{
    ll sum = 0;
	subset sets[vertex];
	for(ll i=0; i<vertex; i++) {
		sets[i].parent = i;
		sets[i].order = 0;
	}
	for(ll i=0; i<edge; i++) {
        if( g.ux==g.vx || v[i].ux!=g.ux || v[i].vx!=g.vx) {
            ll x = sets[ v[i].ux ].parent;
            ll y = sets[ v[i].vx ].parent;
            if (x != y) {
                omg.push_back(v[i]);
                sum += v[i].weight;
            }
            Union(sets, x, y);
        }
	}
	return sum;
}

void MST(vector<graph> omg, ll sum, ll vertex, ll edge, vector<graph> v, priority_queue< pair<vector<graph>,ll>, vector<pair<vector<graph>,ll>>, xcompare > &mst)
{
    mst.push( make_pair(omg,sum) );
    for(ll i=0; i<omg.size(); i++){
        vector<graph> how;
        ll sum = KruskalMST(vertex, edge, v, how, omg[i]);
        if( how.size()==vertex-1 ) {
            mst.push( make_pair(how,sum) );
        }
    }
}

void print(priority_queue< pair<vector<graph>,ll>, vector<pair<vector<graph>,ll>>, xcompare > mst)
{
    while( !mst.empty() ) {
        vector<graph> omg = mst.top().first;
        for(ll j=0; j<omg.size(); j++) {
            cout<<omg[j].ux<<"-"<<omg[j].vx<<"("<<omg[j].weight<<") ";
        }
        cout<<": "<<mst.top().second<<lne;
        mst.pop();
    }
}

int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin>>vertex>>edge;
    vector<graph> v = store(vertex,edge);

    sort( v.begin(), v.end(), compare() );
    vector<graph> omg;
    ll sum = KruskalMST(vertex, edge, v, omg);

    priority_queue< pair<vector<graph>,ll>, vector<pair<vector<graph>,ll>>, xcompare > mst;
    MST(omg, sum, vertex, edge, v, mst);
    print(mst);

    fileclose
    return 0;
}
/*
undirected

8 11
0 1 1
0 2 2
0 3 3
1 4 4
1 6 8
2 4 10
2 6 9
3 4 6
3 5 5
3 7 11
4 5 7

5 8
0 2 75
2 3 51
1 3 19
2 1 95
1 4 42
4 3 31
0 1 9
2 4 66
*/
