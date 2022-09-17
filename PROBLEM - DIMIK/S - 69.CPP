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
    getchar();
    for(ll i=1; i<=tst; i++){
        ll cnt=0;
        string s;
        getline(cin,s,lne);
        ll sze=s.size();
        for(ll j=0; j<sze; j++)
            if( s[j]==spc || ( (s[j]=='.' || s[j]==',' || s[j]==';' || s[j]=='?' || s[j]=='!') && (j+1==sze || s[j+1]!=spc) ) )
                cnt++;
            else if(j==sze-1)
                cnt++;
        cout<<"Count = "<<cnt<<lne;
    }
//    fileclose
    return 0;
}

