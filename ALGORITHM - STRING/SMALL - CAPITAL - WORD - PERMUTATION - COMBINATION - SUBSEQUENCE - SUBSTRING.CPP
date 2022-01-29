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

string small(string s)// LENGTH
{
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i]+=32;
    return s;
}
string capital(string s)// LENGTH
{
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='a' && s[i]<='z')
            s[i]-=32;
    return s;
}
map<string,ll> word(string s,ll &cnt)// LENGTH
{
    ll sze=s.size();
    map<string,ll> m;
    string t="";
    for(ll i=0; i<=sze; i++)
        if(i==sze || s[i]==32){
            m[t]++;
            cnt++;
            t="";
        }
        else
            t+=s[i];
    return m;
}
void __P(string s,vector<string> &v,ll *idx,bool *used,ll length,ll x)
{
    if(x==length){
        string t="";
        for(ll i=0; i<length; i++)
            t += s[idx[i]];
        v.push_back(t);
        return;
    }
    for(ll i=0; i<length; i++){
        if(!used[i]){
            used[i]=true;
            idx[x]=i;
            __P(s,v,idx,used,length,x+1);
            used[i]=false;
        }
    }
}
vector<string> permutation(string s)// LENGTH!.LENGTH
{
    ll length=s.size();
    bool used[length];
    ll idx[length];
    fill(used,used+length,false);
    vector<string> v;
    __P(s,v,idx,used,length,0);
    return v;
}
void __C(string s,vector<string> &v,char *data,ll idx,ll room,ll n,ll r)
{
	if(room==r){
        string t="";
		for(ll j=0; j<r; j++)
			t += data[j];
        v.push_back(t);
		return;
	}
	for(ll i=idx; n-i+room>=r; i++){
		data[room]=s[i];
		__C(s,v,data,i+1,room+1,n,r);
	}
}
vector<string> combination(string s, ll n, ll r)// nCr
{
    vector<string> v;
	char data[r];
	__C(s,v,data,0,0,n,r);
	return v;
}
void subsequence(string s, vector<string> &v, map<ll,vector<string>> &m)// LENGTH.(2^LENGTH)
{
    ll sze=s.length();
    ll num=1<<sze;
    for(ll i=1; i<=num-1; i++){
        string tem="";
        ll val=i, j=0;
        while(val){
            if(val%2) tem+=s[j];
            val/=2;
            j++;
        }
        v.push_back(tem);
    }
    sort(v.begin(),v.end());
    for(ll i=0; i<num-2; i++){
        ll length=v[i].size();
        m[length].push_back(v[i]);
    }
}
vector<string> substring(string s)// LENGTH*(1+LENGTH)/2
{
    vector<string> v;
    vector<string>::iterator it;
    ll sze=s.size(), k=1, ans=0;
    for(ll i=sze; i>=1; i--){
        for(ll j=0; j<k; j++){
            string tem=s.substr(j,i);
//            it=find(v.begin(),v.end(),tem);
//            if(it==v.end())
                v.push_back(tem);
        }
        k++;
    }
    return v;
}

int main()
{
//    inout
//    fileopen

//    fileclose
    return 0;
}
