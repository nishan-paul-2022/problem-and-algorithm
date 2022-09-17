///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
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
        string s,t="";
        getline(cin,s,lne);
        ll sze=s.size();
        reverse(s.begin(),s.end());
        stack<string> x;
        for(ll j=0; j<=sze; j++){
            if(j<sze && s[j]!=spc)
                t+=s[j];
            else{
                x.push(t);
                t="";
            }
        }
        ll lmt=x.size();
        for(ll j=0; j<lmt; j++){
            cout<<x.top();
            if(j<lmt-1) cout<<spc;
            x.pop();
        }
        cout<<lne;
    }
//    fileclose
    return 0;
}
