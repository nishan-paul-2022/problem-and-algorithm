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
        getchar();
        ll cnt=0;
        string s;
        getline(cin,s,lne);
        char c;
        cin>>c;
        ll sze=s.size();
        for(ll j=0; j<sze; j++){
            if(s[j]==c)
                cnt++;
        }
        if(cnt)
            cout<<"Occurrence of \'"<<c<<"\' in \'"<<s<<"\' = "<<cnt<<lne;
        else
            cout<<"\'"<<c<<"\' is not present"<<lne;
    }
//    fileclose
    return 0;
}

