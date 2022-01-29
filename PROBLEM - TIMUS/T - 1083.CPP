///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll k=s.size(), ans=n;
    while( (n-k)>0 ){
        ans*=(n-k);
        n-=k;
    }
    cout<<ans;
//    fileclose
    return 0;
}

