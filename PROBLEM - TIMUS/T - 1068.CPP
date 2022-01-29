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
    ll m=abs(n);
    ll ans=m*(m+1)/2;
    if(n<0){
        ans--;
        ans*=-1;
    }
    else if(n==0)
        ans=1;
    cout<<ans;
//    fileclose
    return 0;
}

