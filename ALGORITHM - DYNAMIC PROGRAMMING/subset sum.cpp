///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vli vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvli vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vuli vector<unsigned long long>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vplli vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsi vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpsli vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvplli vector< vector< pair<long long,long long> > >::iterator
#define mll map<long long,long long>
#define mlli map<long long,long long>::iterator
#define msl map<string,long long>
#define msli map<string,long long>::iterator
#define mls map<long long,string>
#define mlsi map<long long,string>::iterator
#define ud unsigned double
#define vd vector<double>
#define vdi vector<double>::iterator
#define vvd vector< vector<double> >
#define vvdi vector< vector<double> >::iterator
#define vud vector<unsigned double>
#define vudi vector<unsigned double>::iterator
#define pdd pair<double,double>
#define vpdd vector< pair<double,double> >
#define vpddi vector< pair<double,double> >::iterator
#define pds pair<double,string>
#define vpds vector< pair<double,string> >
#define vpdsi vector< pair<double,string> >::iterator
#define psd pair<string,double>
#define vpsd vector< pair<string,double> >
#define vpsdi vector< pair<string,double> >::iterator
#define vvpdd vector< vector< pair<double,double> > >
#define vvpddi vector< vector< pair<double,double> > >::iterator
#define mdd map<double,double>
#define mddi map<double,double>::iterator
#define msd map<string,double>
#define msdi map<string,double>::iterator
#define mds map<double,string>
#define mdsi map<double,string>::iterator
#define vs vector<string>
#define vsi vector<string>::iterator
#define vb vector<bool>
#define vbi vector<bool>::iterator
#define vtrpl vector<trpl>
#define vtrpli vector<trpl>::iterator
#define vvtrpl vector< vector<trpl> >
#define vvtrpli vector< vector<trpl> >::iterator
#define pushb push_back
#define pushf pop_front
#define popb pop_back
#define popf push_front
#define mpair make_pair
#define tostring to_string
#define cntbit(n) __builtin_popcount(n)
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI acos(-1)
#define infp 1000000000000000000
#define infn -1000000000000000000
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define fileopen FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileopen system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
//#define fileopen system("filea.txt"); system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("filec.txt");
//#define fileclose fclose(my1); fclose(my2); system("filec.txt"); freopen("CON","w",stdout); string s1="filea.txt",s2="filec.txt"; char *name1=&s1[0], *name2=&s2[0]; FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");char c1(spc), c2(spc);if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; exit(0);} if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; exit(0);}ll ex=0, ey=0;while(c1!=EOF && c2!=EOF){c1=getc(f1); c2=getc(f2);if(c1==lne){ ex++; ey=0;}if(c1!=c2){cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;cout<<c1<<" INSTEAD of "<<c2<<lne;exit(0);}ey++;}fclose(f1); fclose(f2);cout<<"NO ERROR"<<lne;
using namespace std;
void print(vector<vector<ll>> ans){
    for(ll i=0; i<ans.size(); i++){
        vector<ll> v = ans[i];
        for(ll j=0; j<v.size(); j++)
            cout<<v[j]<<spc;
        cout<<lne;
	}
}
bool isSubsetSum(ll arr[], ll n, ll sum){
    if(sum == 0)
        return true;
    if(n == 0 && sum != 0)
        return false;
    bool x, y;
    x = isSubsetSum(arr, n-1, sum);
    if(arr[n-1] <= sum)
        bool y = isSubsetSum(arr, n-1, sum-arr[n-1]);
    return x || y;
}
void _allSubsetSum(ll arr[], ll i, ll sum, vector<ll> &p, bool **dp, vector<vector<ll>> &ans){// A recursive function to print all subsets with the help of dp[][]. Vector p[] stores current subset.
	if(i == 0 && sum != 0 && dp[0][sum]){// If we reached end and sum is non-zero.
		p.push_back(arr[i]);
		if(arr[0]==sum)// We print p[] only if arr[0] is equal to sun OR dp[0][sum] is true.
            ans.push_back(p);
		return;
	}
	if(i == 0 && sum == 0){// If sum becomes 0
		ans.push_back(p);
		return;
	}
	if(dp[i-1][sum]){// If given sum can be achieved after ignoring current element.
		vector<ll> b = p;// Create a new vector to store path
		_allSubsetSum(arr, i-1, sum, b, dp, ans);
	}
	if(sum >= arr[i] && dp[i-1][sum-arr[i]]){// If given sum can be achieved after considering current element.
		p.push_back(arr[i]);
		_allSubsetSum(arr, i-1, sum-arr[i], p, dp, ans);
	}
}
void allSubsetSum(ll arr[], ll n, ll sum, vector<vector<ll>> &ans){// prints all subsets of arr[0..n-1] with sum 0.
	if(n == 0 || sum < 0)
        return;
    bool** dp;// dp[i][j] is going to store true if sum j is possible with array elements from 0 to i.
	dp = new bool*[n];// Sum 0 can always be achieved with 0 elements
	for(ll i=0; i<n; ++i){
		dp[i] = new bool[sum + 1];
		dp[i][0] = true;
	}
	if(arr[0] <= sum)// Sum arr[0] can be achieved with single element
        dp[0][arr[0]] = true;
	for(ll i = 1; i < n; ++i){// Fill rest of the entries in dp[][]
		for(ll j = 0; j < sum + 1; ++j){
			dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || dp[i-1][j-arr[i]] : dp[i-1][j];
		}
	}
	if (dp[n-1][sum] == false){
		cout<<"There are no subsets with sum "<<sum<<lne;
		return;
	}
	vector<ll> p;// Now recursively traverse dp[][] to find all paths from dp[n-1][sum]
	_allSubsetSum(arr, n-1, sum, p, dp, ans);
}
int main()
{
//    inout
    fileopen

    ll n, sum;
    cin>>n>>sum;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    bool flag = isSubsetSum(arr, n, sum);
    cout<<flag<<lne;

    vector<vector<ll>> ans;
	allSubsetSum(arr, n, sum, ans);
	print(ans);

    fileclose
    return 0;
}
//6
//9
//3 34 4 12 5 2
//5
//10
//1 2 3 4 5
