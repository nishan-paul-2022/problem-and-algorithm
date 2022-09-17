///CUET-IRON-BAT
///"To Cut Down A Tree In Five Minutes, Spend Three Minutes Sharpening Your Axe"
///"A Master Has Failed More Times Than A Newbie Has Even Tried."
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vlvl vector< vector<long long> >
#define vlvlit vector< vector<long long> >::iterator
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
#define tostr to_string
#define sqr(n) n*n
#define cube(n) n*n*
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
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
int main()
{
//    inout
//    fileopen
    string a="",b="";
    ll n,m;
    cin>>n>>m;
    ll x=m/9, y=m%9;
    ll z=y?x+1:x;
    if(z>n || (n>1 && m==0)){
        a+="-1";
        b+="-1";
    }
    else{
        for(ll i=0; i<x; i++)
            a+="9";
        if(y) a+=to_string(y);
        for(ll i=0; i<n-z; i++)
            a+="0";

        if(x==0){
            if(n==1) b+=to_string(y);
            else if(n==2) b+=to_string(1)+to_string(y-1);
            else{
                b+=to_string(1);
                for(ll i=0; i<n-2; i++)
                  b+="0";
                b+=to_string(y-1);
            }
        }
        else{
            for(ll i=0; i<x-1; i++)
                b+="9";
            ll p=n-x+1;
            if(p==1) b="9"+b;
            else if(p==2 && y!=0) b=to_string(y)+"9"+b;
            else if(p>1 && y==0){
                b="8"+b;
                for(ll i=0; i<p-2; i++)
                    b="0"+b;
                b="1"+b;
            }
            else if(p>2 && y!=0){
                b=to_string(y-1)+"9"+b;
                for(ll i=0; i<p-3; i++)
                    b="0"+b;
                b="1"+b;
            }
        }
    }
    cout<<b<<spc<<a;
//    fileclose
    return 0;
}
