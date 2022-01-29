///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vbool vector<bool>
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
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        string s,t;
        cin>>s>>t;
        ll sze=s.size();
        ll idx=s.find(t);
        if(idx<sze)
            cout<<idx<<lne;
    }
//    fileclose
    return 0;
}
