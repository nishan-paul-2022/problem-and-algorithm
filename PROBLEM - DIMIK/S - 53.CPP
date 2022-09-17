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
    ll cnt[26];
    memset(cnt,0,sizeof(cnt));
    ll tst;
    cin>>tst;
    getchar();
    for(ll i=1; i<=tst; i++){
        string s;
        getline(cin,s,lne);
        ll sze=s.size();
        for(ll j=0; j<sze; j++){
            if(s[j]!=spc){
                ll idx=s[j]-'a';
                cnt[idx]++;
            }
        }
        for(ll j=0; j<26; j++){
            if(cnt[j]){
                char c='a'+j;
                cout<<c<<" = "<<cnt[j]<<lne;
                cnt[j]=0;
            }
        }
    }
//    fileclose
    return 0;
}

