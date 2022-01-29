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
        ll r1,c1, r2,c2, x,y;
        cin>>r1>>c1>>r2>>c2;
        if( (r1%2==0 && c1%2==0)||(r1%2!=0 && c1%2!=0) ) x=1;
        else if( (r1%2==0 && c1%2!=0)||(r1%2!=0 && c1%2==0) ) x=2;

        if( (r2%2==0 && c2%2==0)||(r2%2!=0 && c2%2!=0) ) y=1;
        else if( (r2%2==0 && c2%2!=0)||(r2%2!=0 && c2%2==0) ) y=2;

        if(x==y){
            ll m = abs(r1-r2)==abs(c1-c2)? 1:2;
            cout<<"Case "<<i<<": "<<m<<lne;
        }
        else
            cout<<"Case "<<i<<": "<<"impossible"<<lne;
    }
//    fileclose
    return 0;
}
