///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vbool vector<bool>
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
vbool sieve(ll range)
{
    ll lmt=1+sqrt(range);
    vbool v(1+range,true);
    v[0]=v[1]=false;
    for(ll i=4; i<=range; i+=2)
        v[i]=false;
    for(ll i=3; i<=lmt; i+=2)
        if(v[i]==true)
            for(ll j=i*i; j<=range; j+=2*i)
                v[j]=false;
    return v;
}
int main()
{
//    inout
//    fileopen
    ll n=100000000;
    vbool v=sieve(n);
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll val;
        cin>>val;
        if(val<=n){
            if(v[val])
                cout<<val<<" is a prime"<<lne;
            else
                cout<<val<<" is not a prime"<<lne;
        }
        else{
            ll m=sqrt(val), j;
            for(j=5; j<=m && val%j && val%(j+2); j+=6);
            if(val%2==0 || val%3==0 || j!=m+1)
                cout<<val<<" is a prime"<<lne;
            else
                cout<<val<<" is not a prime"<<lne;
        }
    }
//    fileclose
    return 0;
}

