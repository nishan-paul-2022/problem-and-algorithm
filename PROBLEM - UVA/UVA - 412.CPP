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
ll** allo(ll n,ll r)
{
    ll** dp = new ll*[n+1];
    for(ll i=0; i<=n; i++)
        *(dp+i)=new ll[r+1];
    for(ll i=0; i<=n; i++)
        for(ll j=0; j<=r; j++)
            dp[i][j]=0;
    return dp;
}
ll nCr(ll n,ll r,ll **dp)
{
    if(n==r) return dp[n][r]=1;
    else if(r==1) return dp[n][r]=n;
    else{
        if(dp[n][r]==0){
            ll x=dp[n-1][r]?dp[n-1][r]:nCr(n-1,r,dp);
            ll y=dp[n-1][r-1]?dp[n-1][r-1]:nCr(n-1,r-1,dp);
            dp[n][r]=x+y;
        }
        return dp[n][r];
    }
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
//    inout
//    fileopen
    ll** dp=allo(50,2);
    nCr(50,2,dp);

    ll n;
    cin>>n;
    while(n){
        ll a[n], b=6*dp[n][2], cnt=0;
        for(ll i=0; i<n; i++)
            cin>>a[i];
        for(ll i=0; i<n-1; i++)
            for(ll j=i+1; j<n; j++)
                if( gcd(a[i],a[j])==1 )
                    cnt++;
        if(cnt==0)
            cout<<"No estimate for this data set."<<lne;
        else
            cout<<fixed<<setprecision(6)<<sqrt( (double)b/cnt )<<lne;
        cin>>n;
    }
//    fileclose
    return 0;
}
