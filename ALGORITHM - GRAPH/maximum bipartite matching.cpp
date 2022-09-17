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

bool** allocate(ll M,ll N)
{
    bool **a = new bool*[M];
    for(ll i=0; i<M; i++) {
        *(a+i) = new bool[N];
        fill(a[i], a[i]+N, false);
    }
    return a;
}
bool** store(ll M, ll N, ll edge)
{
    bool **graph = allocate(M,N);
	for(ll i=0; i<edge; i++) {
        ll ux, vx;
        cin >> ux >> vx;
        graph[ux][vx] = true;
	}
	return graph;
}

bool bpm(ll N, bool **bpGraph, ll u, vector<bool> &seen, vector<ll> &matchR)// A DFS based recursive function that returns true if a matching for vertex u is possible
{
	for (ll v = 0; v < N; v++) { // Try every job one by one
		if( bpGraph[u][v] && !seen[v] ) { // If applicant u is llerested in job v and v is not visited
			seen[v] = true;// Mark v as visited
			// If job 'v' is not assigned to an applicant OR previously assigned applicant for job v (which is matchR[v]) has an alternate job available.
			// Since v is marked as visited in the above line, matchR[v] in the following recursive call will not get job 'v' again
			if( matchR[v] < 0 || bpm(N, bpGraph, matchR[v], seen, matchR) ) {
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

ll maxBPM(ll M, ll N, bool **bpGraph) // Returns maximum number of matching from M to N
{
	// An array to keep track of the applicants assigned to jobs.
	// The value of matchR[i] is the applicant number assigned to job i, the value -1 indicates nobody is assigned.
	vector<ll> matchR(N,-1);// Initially all jobs are available
	ll result = 0;// Count of jobs assigned to applicants
	for (ll u = 0; u < M; u++) {
		vector<bool> seen(N,false);// Mark all jobs as not seen for next applicant.
		if( bpm(N, bpGraph, u, seen, matchR) )// Find if the applicant 'u' can get a job
			result++;
	}
	return result;
}

int main()
{
//    inout
    fileopen

    ll M, N, edge;// M is number of applicants and N is number of jobs
    cin >> M >> N >> edge;
	bool **bpGraph = store(M, N, edge);// Let us create a bpGraph shown in the above example

	cout << "Maximum number of applicants that can get job is " << maxBPM(M, N, bpGraph);// A C++ program to find maximal Bipartite matching.

	fileclose
	return 0;
}
//6 6 8
//0 1
//0 2
//1 0
//1 3
//2 2
//3 2
//3 3
//5 5
