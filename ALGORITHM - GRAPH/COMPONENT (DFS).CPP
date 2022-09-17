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
//CAN IDENTIFY THE COMPONENTS OF A GIVEN GRAPH
//TIME COMPLEXITY: O(V+E)

void store(ll edge, vector<ll> v[])
{
    for(ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(ll start, vector<ll> v[], vector<bool> &visit, vector<ll> &point, vector<pair<ll,ll>> &path)
{
    visit[start] = true;
    point.push_back(start);
    for(ll i = 0; i < v[start].size(); i++) {
        ll p = v[start][i];
        if( visit[p]==false ) {
            path.push_back( make_pair(start,p) );
            dfs(p, v, visit, point, path);
        }
    }
}

void component(ll vertex, ll edge, vector<ll> v[], vector<vector<ll>> &xpoint, vector< vector<pair<ll,ll>> > &xpath)
{
    vector<bool> visit(vertex,false);
    for(ll i = 0; i < vertex; i++) {
        if( visit[i]==false ) {
            vector<ll> point;
            vector<pair<ll,ll>> path;
            dfs(i, v, visit, point, path);
            xpoint.push_back(point);
            xpath.push_back(path);
        }
    }
}

void printPoint(vector<vector<ll>> xpoint)
{
    for(ll i=0; i<xpoint.size(); i++) {
        vector<ll> point = xpoint[i];
        for(ll j=0; j<point.size(); j++) {
            cout<<point[j]<<spc;
        }
        cout<<lne;
    }
    cout<<lne;
}

void printPath(vector<vector<pair<ll,ll>>> xpath)
{
    for(ll i = 0; i < xpath.size(); i++) {
        vector<pair<ll,ll>> path = xpath[i];
        for(ll j = 0; j < path.size(); j++)
            cout << path[j].first << "-" << path[j].second << spc;
        cout<<lne;
    }
    cout << lne;
}

int main()
{
//    inout
    fileopen

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<ll> v[vertex];
    store(edge, v);

    vector<vector<ll>> xpoint;
    vector<vector<pair<ll,ll>>> xpath;
    component(vertex, edge, v, xpoint, xpath);/*can not properly print the edge of a negative cycle for an undirected graph*/
    printPoint(xpoint);
    printPath(xpath);

    fileclose
    return 0;
}
/*
directed
7 7
0 1
1 2
2 0
3 4
4 5
5 3
5 6
ans: 0 1 2 | 3 4 5 6

undirected
5 3
1 0
2 3
3 4
ans: 0 1 | 2 3 4
*/
