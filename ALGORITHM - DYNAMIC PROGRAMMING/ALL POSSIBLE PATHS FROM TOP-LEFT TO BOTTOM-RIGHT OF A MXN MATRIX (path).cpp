///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define udouble unsigned double
#define gcd __gcd
#define countbit(n) __builtin_popcount(n)
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 29996224275833
#define PI acos(-1)
#define inf ULLONG_MAX
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
/*
i, j: Current position of the robot (For the first call use 0,0)
x: Next index to be filed in path array
path[0..x-1]: The path traversed by robot till now (Array to hold the path need to have space for at least m+n elements)
*/
void row(vector<vector<ll>> matrix, vector<vector<ll>> &road, ll r, ll c, ll p, ll path[], ll x)
{
    vector<ll> omg;
    for(ll k = p; k < c; k++)
        path[x++] = matrix[r-1][k];
    for(ll m = 0; m < x; m++)
        omg.push_back( path[m] );
    road.push_back(omg);
}

void column(vector<vector<ll>> matrix, vector<vector<ll>> &road, ll r, ll c, ll p, ll path[], ll x)
{
    vector<ll> omg;
    for(ll k = p; k < r; k++)
        path[x++] = matrix[k][c-1];
    for(ll m = 0; m < x; m++)
        omg.push_back( path[m] );
    road.push_back(omg);
}

void _mapOfpaths(vector<vector<ll>> matrix, vector<vector<ll>> &road, ll i, ll j, ll r, ll c, ll path[], ll x)
{
	if(i == r - 1)// Reached the bottom of the matrix so we are left with only option to move right
        row(matrix, road, r, c, j, path, x);
	else if(j == c - 1)// Reached the right corner of the matrix we are left with only the downward movement.
		column(matrix, road, r, c, i, path, x);
	else {
        path[x] = matrix[i][j];// Add the current cell to the path being generated
        _mapOfpaths(matrix, road, i+1, j, r, c, path, x + 1);// print all the paths that are possible after moving down
        _mapOfpaths(matrix, road, i, j+1, r, c, path, x + 1);// print all the paths that are possible after moving right
//    	_mapOfpaths(matrix, road, i+1, j+1, r, c, path, x + 1);// print all the paths that are possible after moving diagonal
	}
	return;
}

vector<vector<ll>> mapOfpaths(ll r, ll c)// The main function that prints all paths from top left to bottom right in a matrixrix 'matrix' of size mXn
{
    ll path[r+c], n = 0;
	vector<vector<ll>> matrix( r, vector<ll>(c) ), road;
	for(ll i = 0; i < r; i++)
        for(ll j = 0; j < c; j++)
            matrix[i][j] = n++;
	_mapOfpaths(matrix, road, 0, 0, r, c, path, 0);
	return road;
}

void print(vector<vector<ll>> road)
{
    for(ll i = 0; i < road.size(); i++) {
        for(ll j = 0; j < road[i].size(); j++) {
            cout << road[i][j] << spc;
        }
        cout << lne;
    }
}

int main()// A program to print all possible paths from top left to bottom right of a mXn matrixrix
{
//    inout
    fileopen

    ll r, c;
    cin >> r >> c;
    vector<vector<ll>> road = mapOfpaths(r, c);
	print(road);

	fileclose
	return 0;
}
/*
3 3
0 1 2
3 4 5
6 7 8
*/
