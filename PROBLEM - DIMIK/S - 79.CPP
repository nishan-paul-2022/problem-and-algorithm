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
void bubble(ll n,vector<string> &v)///N^2
{
    for(ll i=0; i<n-1; i++)
        for(ll j=i+1; j<n; j++){
            string x=v[i], y=v[j];
            ll k, lx=x.size(), ly=y.size();
            ll sze=min(lx,ly);
            for(k=0; k<sze && x[k]==y[k]; k++);
            if(k!=sze){
                if(x[k]>y[k])
                    swap(v[i],v[j]);
            }
            else if(lx!=ly){
                if(lx>ly)
                    swap(v[i],v[j]);
            }
        }
}
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    for(ll i=1; i<=tst; i++){
        ll n;
        cin>>n;
        vector<string> v;
        for(ll j=0; j<n; j++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        bubble(n,v);
        for(ll j=0; j<n; j++)
            cout<<v[j]<<lne;
    }
//    fileclose
    return 0;
}

