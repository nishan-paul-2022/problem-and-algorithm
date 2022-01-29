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
        string s;
        cin>>s;
        ll sze=s.size(), num=0;
        for(ll j=0; j<sze; j++){
            ll x=s[j]-'0', digit=1;
            for(ll k=0; k<sze; k++)
                digit*=x;
            num+=digit;
        }
        string sx=to_string(num);
        if(s==sx)
            cout<<s<<" is an armstrong number!"<<lne;
        else if(s!=sx)
            cout<<s<<" is not an armstrong number!"<<lne;
    }
//    fileclose
    return 0;
}

