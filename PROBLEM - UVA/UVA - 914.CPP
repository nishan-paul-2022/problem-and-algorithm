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
void sieve(ll range,vector<bool> &all)///N.LOG(LOG(N))
{
    ll lmt=1+sqrt(range);
    vector<bool> v(1+range,false);
    v[0]=v[1]=true;
    for(ll i=4; i<=range; i+=2)
        v[i]=true;
    for(ll i=3; i<=lmt; i+=2)
        if(v[i]==false)
            for(ll j=i*i; j<=range; j+=2*i)
                v[j]=true;
    all=v;
}
int main()
{
    inout
//    fileopen
    vector<bool> all;
    sieve(1000000,all);

    ll tst;
    cin>>tst;
    while(tst--){
        ll a,b,mx=1,ans=0,chk=-1;
        cin>>a>>b;
        vll v, cnt(b-a+1,0);
        for(ll i=a; i<=b; i++)
            if(all[i]==false)
                v.push_back(i);
        ll sze=v.size();
        if(sze==2){
            ans=v[1]-v[0];
            chk=v[1]-v[0];
        }
        else if(sze>2)
            for(ll i=1; i<sze; i++){
                cout<<v[i]-v[i-1]<<spc;
                cnt[ v[i]-v[i-1] ]++;
                if(cnt[ v[i]-v[i-1] ]>mx){
                    ans=v[i]-v[i-1];
                    mx=cnt[ v[i]-v[i-1] ];
                }
                if(cnt[ v[i]-v[i-1] ]>=mx)
                    chk=v[i]-v[i-1];
            }
        if(ans!=chk)
            cout<<"No jumping champion"<<lne;
        else
            cout<<"The jumping champion is "<<ans<<lne;
    }
//    fileclose
    return 0;
}
