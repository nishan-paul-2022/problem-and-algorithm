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
    inout
    //fileopen
    ll n,hole,inter,ans;
    cin>>n>>hole>>inter;
    vector<bool> v(1+n,false);
    for(ll i=0; i<hole; i++){
        ll tem;
        cin>>tem;
        v[tem]=true;
    }
    ll h=1;
    vector<ll> ctch;
    ctch.push_back(h);
    for(ll i=0; i<inter; i++){
        ll a,b;
        cin>>a>>b;
        if(a==h || b==h){
            h = a==h? b:a;
            ctch.push_back(h);
        }
    }
    ll sze=ctch.size();
    ans=ctch[sze-1];
    for(ll i=0; i<sze; i++){
        if( v[ ctch[i] ] ){
            ans=ctch[i];
            break;
        }
    }
    cout<<ans;
    //fileclose
    return 0;
}
