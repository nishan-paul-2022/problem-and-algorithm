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
#define fileopenX ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX }
using namespace std;

void store(ll edge, map<string,vector<string>> &v, map<string,ll> &distance)
{
    for(ll i=0; i<edge; i++) {
        string a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        distance[a]=-1;
        distance[b]=-1;
    }
}

ll bfs(string start, string destination, map<string,vector<string>> v, map<string,ll> &distance, map<string,string> &parent)
{
    queue<string> q;
    q.push(start);
    distance[start] = 0;
    while( q.empty()==false ) {
        string node = q.front();
        q.pop();
        if( node==destination )
            return distance[node];
        ll sze = v[node].size();
        for(ll i = 0; i < sze; i++) {
            string p = v[node][i];
            if( distance[p]==-1 ) {
                distance[p] = distance[node]+1;
                parent[p] = node;
                q.push(p);
            }
        }
    }
    return -1;
}

void path(string start, string destination, map<string,string> parent)
{
    if(start==destination)
        return;
    path(start, parent[destination], parent);
    cout << parent[destination] << spc << destination << lne;
}

int main()
{
//  inout

    bool flag = false;
    ll edge;
    while( scanf("%lld", &edge) != EOF ) {
        map<string,vector<string>> v;
        map<string,ll> distance;
        store(edge, v, distance);

        string start, destination;
        cin >> start >> destination;
        map<string,string> parent;
        if(flag)
            cout << lne;
        flag = true;
        if( bfs(start, destination, v, distance, parent) != -1 )
            path(start, destination, parent);
        else
            cout << "No route" << lne;
    }

    return 0;
}

/*
3
JV PT
KA PT
KA HP
JV HP

2
JV PT
KA HP
JV HP

4
a b
b c
c d
d e
a f
*/
