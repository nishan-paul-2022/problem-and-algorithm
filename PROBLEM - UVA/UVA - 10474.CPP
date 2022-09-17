///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vul vector<unsigned long long>
#define vulit vector<unsigned long long>::iterator
#define vbol vector<bool>
#define vbolit vector<bool>::iterator
#define vstr vector<string>
#define vstrit vector<string>::iterator
#define mll map<long long,long long>
#define mllit map<long long,long long>::iterator
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define PI 3.141592653589793
#define pos 9223372036854775807
#define neg -9223372036854775808
#define inf 18446744073709551615
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
int main()
{
    inout
//    fileopen
    ll i=1, b[10001], n,q;
    cin>>n>>q;
    while(n!=0 && q!=0){
        mem(b,0);
        ll c[n], tem;
        for(ll j=0; j<n; j++)
            cin>>c[j];
        sort(c,c+n);
        for(ll j=0; j<n; j++)
            if(b[ c[j] ]==0)
                b[ c[j] ]=j+1;
        cout<<"CASE# "<<i<<":"<<lne;
        for(ll j=0; j<q; j++){
            cin>>tem;
            ll idx=b[tem];
            if(idx)
                cout<<tem<<" found at "<<idx<<lne;
            else
                cout<<tem<<" not found"<<lne;
        }
        i++;
        cin>>n>>q;
    }
//    fileclose
    return 0;
}
