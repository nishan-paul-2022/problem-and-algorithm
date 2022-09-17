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

void input(ll N, vector<ll> human[])
{
    ll no;
    for(ll i=0; i<N; i++) {
        for(ll j=0; j<N; j++) {
            cin >> no;
            human[i].push_back(no);
        }
    }
}
bool priority(ll N, vector<ll> woman[], ll w, ll m, ll m1)// this function returns true if woman 'w' prefers man 'm' over man 'm1'
{
	for (ll i = 0; i < N; i++) { // check if 'w' prefers 'm' over her current engagment 'm1'
		if( woman[w][i] == m )// if 'm' comes before 'm1' in w's list, then free her current engagement and engage her with 'm'
			return true;
		if( woman[w][i] == m1 )// if 'm1' comes before 'm' in lisr of 'w', then 'w' prefers her cirrent engagement, don't do anything
            return false;
	}
}
vector<ll> stableMarriage(ll N, vector<ll> man[], vector<ll> woman[])// calculates stable matching for N boys and N girls. Boys & Girls are numbered as 0 to N-1
{
	vector<ll> wPartner(N,-1);// stores partner of women. The value of wPartner[i] indicates the partner assigned to woman i. The value -1 indicates that i'th woman is free
	vector<bool> mFree(N,false);// an array to store availability of men. If mFree[i] is false, then man 'i' is free, otherwise engaged
	ll freeCount = 0;
	while (freeCount < N) { // While there are free men
		ll m;// Pick the first free man
		for (m = 0; m<N && mFree[m]; m++);
		for (ll i = 0; i < N && mFree[m] == false; i++) { // One by one go to all women according to m's preferences. Here m is the picked free man
			ll w = man[m][i]; // m's prefered woman
			ll m1 = wPartner[w]; // current engagement of that woman
			if (m1 == -1) { // if the woman of preference is free, w and m become partners (Note that the partnership maybe changed later)
				wPartner[w] = m;
				mFree[m] = true;
				freeCount++;
			}
			else { // if the woman of preference is not free,
				if( priority(N, woman, w, m, m1) == true ) { // If w prefers m over her current engagement m1, then break the engagement between w and m1 and engage m with w.
					wPartner[w] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			}
		}
	}
	return wPartner;
}
void print(ll N, vector<ll> wPartner)// prints the solution
{
	cout << "Woman Man" << lne;
	for (ll i = 0; i < N; i++) {
        cout << " " << i << "\t" << wPartner[i] << lne;
	}
}

int main()
{
//    inout
    fileopen

    ll N, no;
    cin >> N;
    vector<ll> man[N], woman[N];
    input(N, man);
    input(N, woman);
	vector<ll> wPartner = stableMarriage(N, man, woman);
	print(N, wPartner);

	fileclose
	return 0;
}
/*
4
3 1 2 0
1 0 2 3
0 1 2 3
0 1 2 3

0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
Woman Man
 4	2
 5	1
 6	3
 7	0
*/
