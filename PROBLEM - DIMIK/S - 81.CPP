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
        string s,t;
        cin>>s;
        t=s;
        reverse(t.begin(),t.end());
        if(t==s)
            cout<<"Yes! It is palindrome"<<lne;
        else if(t!=s)
            cout<<"Sorry! It is not palindrome"<<lne;
    }
//    fileclose
    return 0;
}

