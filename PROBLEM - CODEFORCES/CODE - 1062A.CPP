///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvlit vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vulit vector<unsigned long long>::iterator
#define vdou vector<double>
#define vdouit vector<double>::iterator
#define vstr vector<string>
#define vstrit vector<string>::iterator
#define vbol vector<bool>
#define vbolit vector<bool>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vpllit vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsit vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpslit vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvpllit vector< vector< pair<long long,long long> > >::iterator
#define vomg vector<omg>
#define vomgit vector<omg>::iterator
#define vvomg vector< vector<omg> >
#define vvomgit vector< vector<omg> >::iterator
#define mll map<long long,long long>
#define mllit map<long long,long long>::iterator
#define msl map<string,long long>
#define mslit map<string,long long>::iterator
#define mls map<long long,string>
#define mlsit map<long long,string>::iterator
#define pushb push_back
#define pushf pop_front
#define popb pop_back
#define popf push_front
#define mpair make_pair
#define tostring to_string
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define mem(a,b) memset(a,b,sizeof(a))
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI acos(-1)
#define infp 9223372036854775807
#define infn -9223372036854775808
#define inf 18446744073709551615
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("accurate.txt"); system("input.txt"); FILE *my1=freopen("input.txt","r",stdin); FILE *my2=freopen("output.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("output.txt"); freopen("CON","w",stdout); checker();
using namespace std;
void checker(string s1="accurate.txt",string s2="output.txt"){
    char *name1=&s1[0], *name2=&s2[0];
    FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");
    char c1(spc), c2(spc);
    if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; return;}
    if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; return;}
    ll ex=0, ey=0;
    while(c1!=EOF && c2!=EOF){
        c1=getc(f1); c2=getc(f2);
        if(c1==lne){ ex++; ey=0;}
        if(c1!=c2){
            cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;
            cout<<c1<<" INSTEAD of "<<c2<<lne;
            return;
        }
        ey++;
    }
    fclose(f1); fclose(f2);
    cout<<"NO ERROR"<<lne;
}
int main()
{
//    inout
//    fileopen
    ll n;
    cin>>n;
    ll a[n], mx=0,cnt=1;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    if(n==1000)
        mx=n;
    else{
        for(ll i=1; i<=n; i++){
            if(i!=n && a[i]-a[i-1]==1)
                cnt++;
            else if(i==n || a[i]-a[i-1]!=1){
                mx=max(mx,cnt);
                cnt=1;
            }
        }
        if( mx==1 || (a[0]==1 && a[mx-1]==mx) || (a[n-1]==1000 && a[n-mx]==1001-mx) )
            mx--;
        else
            mx-=2;
    }
    cout<<mx;
//    fileclose
    return 0;
}
