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
ll f(ll n)
{
    ll range=sqrt(n), cnt=1;
    for(ll i=2; i<=range; i++)
        if(n%i==0){
            if(cnt+i>0) cnt+=i;
            if(i!=n/i && cnt+n/i>0) cnt+=n/i;
        }
    return cnt;
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
        ll val=f(n);
        if(val==1 || val!=n)
            cout<<"NO, "<<n<<" is not a perfect number"<<lne;
        else
            cout<<"YES, "<<n<<" is a perfect number"<<lne;
    }
//    fileclose
    return 0;
}
