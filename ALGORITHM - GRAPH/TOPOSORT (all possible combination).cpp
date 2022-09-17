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
//CONNECTED | DIRECTED-ACYCLIC | NEGATIVE-WEIGHTED/POSITVE-WEIGHTED/UNWEIGHTED
//CAN IDENTIFY TOPOSORT OF A GIVEN GRAPH
//TIME COMPLEXITY: O( N*V )
void store(ll vertex,ll edge,vector<ll> v[],vector<ll> &indegree)
{
    for(ll i=0; i<edge; i++) {
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }
}
void backtrack(ll vertex,vector<ll> v[],vector<ll> &indegree,vector<bool> &visit,vector<ll> &order,vector<vector<ll>> &collection)// Main recursive function to store all possible topological sorts
{
	bool flag = false;// To indicate whether all topological are found or not
	for(ll i=0; i<vertex; i++){
		if(indegree[i]==0 && !visit[i]) {// If indegree is 0 and not yet visited then only choose that vertex
			for(ll j=0; j<v[i].size(); j++) {
                indegree[ v[i][j] ]--;// reducing indegree of adjacent vertices
			}
			order.push_back(i);// including in result
			visit[i] = true;
			backtrack(vertex,v,indegree,visit,order,collection);
			visit[i] = false;// resetting visit, order and indegree for backtracking
			order.erase(order.end() - 1);
			for(ll j=0; j<v[i].size(); j++) {
                indegree[ v[i][j] ]++;
			}
			flag = true;
		}
	}
	if(!flag) {
        collection.push_back(order);// We reach here if all vertices are visited. So we store the solution here.
	}
}
vector<vector<ll>> xtoposort(ll vertex,vector<ll> v[],vector<ll> &indegree)
{
    vector<vector<ll>> collection;
	vector<bool> visit(vertex,false);// Mark all the vertices as not visited
	vector<ll> order;
	backtrack(vertex,v,indegree,visit,order,collection);
	return collection;
}
void print(vector<vector<ll>> collection)
{
    for(ll i=0; i<collection.size(); i++) {
        vector<ll> road = collection[i];
        for(ll j=0; j<road.size(); j++) {
            cout<<road[j]<<spc;
        }
        cout<<lne;
    }
    cout<<lne;
}
int main()
{
//    inout
    fileopen

    ll vertex,edge;
    cin>>vertex>>edge;
    vector<ll> v[vertex], indegree(vertex,0);
    store(vertex,edge,v,indegree);

    vector<vector<ll>> collection = xtoposort(vertex,v,indegree);
    print(collection);

    fileclose
    return 0;
}
/*
dag

6 6
5 2
5 0
4 0
4 1
2 3
3 1
ans:
    4 5 0 2 3 1
    4 5 2 0 3 1
    4 5 2 3 0 1
    4 5 2 3 1 0
    5 2 3 4 0 1
    5 2 3 4 1 0
    5 2 4 0 3 1
    5 2 4 3 0 1
    5 2 4 3 1 0
    5 4 0 2 3 1
    5 4 2 0 3 1
    5 4 2 3 0 1
    5 4 2 3 1 0
*/
