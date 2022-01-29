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
//CONNECTED | DIRECTED-CYCLIC/DIRECTED-ACYCLIC/UNDIRECTED | POSITVE-WEIGHTED | NO-LOOP
//CAN IDENTIFY THE MAX-FLOW OF A GIVEN FLOW-NETWORK
//TIME COMPLEXITY: O(V*E*E)
void store(ll edge, vector<ll> adjacent[], vector<vector<ll>> &capacity)
{
    for(ll i = 0; i < edge; i++) {
        ll ux, vx, weight;
        cin >> ux >> vx >> weight;
        capacity[ux][vx] = weight;
        adjacent[ux].push_back(vx);
        adjacent[vx].push_back(ux);// reverse edge
    }
}

ll BFS(ll s, ll t, vector<ll> &parent, vector<ll> adjacent[], vector<vector<ll>> &capacity)
{
    fill(parent.begin(), parent.end(), -2);
    parent[s] = -1;
    queue< pair<ll,ll> > q;
    q.push( {s,infp} );
    while( !q.empty() ) {
        ll node = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for(ll i = 0; i < adjacent[node].size(); i++) {
            ll x = adjacent[node][i];
            if( parent[x] == -2 && capacity[node][x] ) {
                parent[x] = node;
                ll new_flow = min(flow, capacity[node][x]);
                if( x==t )
                    return new_flow;
                q.push( {x,new_flow} );
            }
        }
    }
    return 0;
}

ll EdmondKarp(ll s, ll t, ll vertex, vector<ll> adjacent[], vector<vector<ll>> &capacity, vector<pair<ll,vector<ll>>> &road)
{
    ll total = 0;
    vector<ll> parent(vertex);
    while( ll new_flow = BFS(s, t, parent, adjacent, capacity) ) {
        total += new_flow;
        ll current = t;
        vector<ll> omg;
        while(current != s) {
            omg.push_back(current);
            ll previous = parent[current];
            capacity[previous][current] -= new_flow;
            capacity[current][previous] += new_flow;
            current = previous;
        }
        omg.push_back(current);
        road.push_back( make_pair(new_flow,omg) );
    }
    return total;
}

void print(vector<pair<ll,vector<ll>>> road)
{
    for(ll i = 0; i < road.size(); i++) {
        cout << road[i].first << " - ";
        vector<ll> omg = road[i].second;
        for(ll j = 0; j < omg.size(); j++) {
            cout << omg[j] << spc;
        }
        cout << lne;
    }
}

int main()
{
//    inout
    fileopenX

    ll vertex, edge;
    cin >> vertex >> edge;
    vector<ll> adjacent[vertex];
    vector<vector<ll>> capacity(vertex, vector<ll>(vertex,0));
    store(edge, adjacent, capacity);

	ll s, t;
	cin >> s >> t;
	vector<pair<ll,vector<ll>>> road;
	ll maxflow = EdmondKarp(s, t, vertex, adjacent, capacity, road);
	cout << "The maximum possible flow is " << maxflow << lne;
	print(road);

    filecloseX
    return 0;
}
/*
6 10
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5

6 10
0 1 3
0 2 7
1 3 9
1 4 9
2 1 9
2 4 9
2 5 4
3 5 3
4 5 7
0 4 10
0 5

6 9
0 1 10
0 2 10
1 3 4
1 4 8
1 2 2
2 4 9
3 5 10
4 3 6
4 5 10
0 5
*/
