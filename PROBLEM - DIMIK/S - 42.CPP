///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vul vector<unsigned long long>
#define vulit vector<unsigned long long>::iterator
#define vbol vector<bool>
#define vbolit vector<bool>::iterator
#define vstr vector<string>
#define vstrit vector<string>::iterator
#define all(v) v.begin(),v.end()
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define PI 3.141592653589793
#define pos 9223372036854775807
#define neg -9223372036854775808
#define inf 18446744073709551615
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
vstr substring(string s) /// N^2
{
    vstr v;
    vstrit it;
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
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        string s,t;
        cin>>s>>t;
        vstr v=substring(s);
        ll x=count(all(v),t);
        cout<<x<<lne;
    }
//    fileclose
    return 0;
}
