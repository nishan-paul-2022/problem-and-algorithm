///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define udouble unsigned double
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define mpair make_pair
#define tostring to_string
#define countbit(n) __builtin_popcount(n)
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

void store(ll vertex,ll edge, vector<pair<ll,ll>> v[])
{
    for(ll i=0; i<edge; i++) {
        ll ux, vx, weight;
        cin >> ux >> vx >> weight;
        v[vx].push_back( make_pair(ux,weight) );
    }
}

void dfs(ll ux, vector<pair<ll,ll>> v[], vector<bool> &color )
{
    color[ux] = true;
    for(ll i = 0; i < v[ux].size(); i++) {
        ll p = v[ux][i].first;
        if( color[p] == false )
            dfs(p, v, color);
    }
}

bool bellman(ll vertex, vector<pair<ll,ll>> v[], vector<ll> &distance)
{
    bool check = false;
    for(ll i = 0; i < vertex  && !check; i++) {
        bool flag = true;
        for(ll ux = 0; ux < vertex; ux++) {
            for(ll j = 0; j < v[ux].size(); j++) {
                ll vx = v[ux][j].first;
                ll weight = v[ux][j].second;
                if( distance[ux] + weight < distance[vx] ) {
                    distance[vx] = distance[ux] + weight;
                    flag = false;
                }
            }
        }
        check = flag;
    }
    return !check;
}

vector<bool> negative(ll vertex, vector<pair<ll,ll>> v[], bool &flag)
{
    vector<bool> color(vertex,false);
    vector<ll> distance(vertex,0);
    flag = bellman(vertex, v, distance);
    if( flag ) {
        for(ll ux = 0; ux < vertex; ux++) {
            for(ll j = 0; j < v[ux].size(); j++) {
                ll vx = v[ux][j].first;
                ll weight = v[ux][j].second;
                if( color[ux]==false && distance[ux] + weight < distance[vx] ) {
                    distance[vx] = distance[ux] + weight;
                    color[ux] = true;
                    dfs(ux, v, color);
                }
            }
        }
    }
	return color;
}

void print(ll cs, ll vertex, bool flag, vector<bool> color)
{
    if( !flag )
        cout << "Case " << cs << ": impossible" << lne;
    else {
        cout << "Case " << cs << ":";
        for(ll i = 0; i < vertex; i++) {
            if( color[i] )
                cout << spc << i;
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
    vector<pair<ll,ll>> v[vertex];
    store(vertex, edge, v);

    bool flag;
    vector<bool> color = negative(vertex, v, flag);// can not properly print the node of a negative cycle for an undirected graph
    print(cs, vertex, flag, color);

	filecloseX
	return 0;
}
//undirected
//8 9
//0 1 -1
//1 2 -2
//2 0 -3
//2 3 1
//3 4 2
//4 5 3
//5 6 -1
//6 7 -2
//7 5 -3
