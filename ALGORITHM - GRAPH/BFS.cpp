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

//CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | UNWEIGHTED | NO-LOOP
//CAN IDENTIFY THE SHORTEST PATH FROM THE STARTING NODE TO ALL OTHER REACHABLE NODES
//TIME COMPLEXITY: O(V+E)
void store(ll edge, vector<ll> v[])
{
    for(ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);//for undirected graph only
    }
}

void bfs(ll start, vector<ll> v[], vector<ll> &distance, vector<ll> &parent)
{
    queue<ll> q;
    q.push(start);
    parent[start] = start;
    distance[start] = 0;
    while( q.empty()==false ) {
        ll node = q.front();
        q.pop();
        for(ll i = 0; i < v[node].size(); i++) {
            ll p = v[node][i];
            if( distance[p]==-1 ) {
                distance[p] = distance[node]+1;
                parent[p] = node;
                q.push(p);
            }
        }
    }
}

void path(ll start, ll destination, vector<ll> parent)
{
    if(start==destination)
        return;
    path(start, parent[destination], parent);
    cout << parent[destination] << "-" << destination << spc;
}

void roadmap(ll start, ll vertex, vector<ll> distance, vector<ll> parent)
{
    for(ll i = 0; i < vertex; i++) {
        if(i != start) {
            if(distance[i] != -1) {
                cout << start << "-" << i << ": distance " << distance[i] << " and road ";
                path(start, i, parent);
            }
            else
                cout << start << "-" << i << ": no way!";
            cout << lne;
        }
    }
}

int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<ll> distance(vertex,-1), parent(vertex,-1), v[vertex];
    store(edge, v);

    ll start;
    cin >> start;
    bfs(start, v, distance, parent);
    roadmap(start, vertex, distance, parent);

    fileclose
    return 0;
}
/*
directed
6 7
0 1
0 4
4 5
1 2
2 3
2 5
3 0
0

undirected
10 13
0 1
0 3
0 2
1 5
3 6
2 6
2 7
5 9
6 8
9 8
7 4
9 4
6 7
0
*/
