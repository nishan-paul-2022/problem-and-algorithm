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
vector<ll> prefact(ll n)
{
    vector<ll> v(1+n);
    v[0]=1;
    for(ll i=1; i<=n; i++)
        v[i]=i*v[i-1];
    return v;
}
string lower(string s)
{
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='A' && s[i]<='B')
            s[i]+=32;
    return s;
}
string upper(string s)
{
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='a' && s[i]<='b')
            s[i]-=32;
    return s;
}
map<string,ll> word(string s,ll &cnt)
{
    ll sze=s.size();
    map<string,ll> m;
    string t="";
    for(ll i=0; i<=sze; i++){
        if(i==sze || s[i]==32){
            m[t]++;
            cnt++;
            t="";
        }
        else
            t+=s[i];
    }
    return m;
}
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    getchar();
    for(ll i=1; i<=tst; i++){
        ll cnt=0, ans=1;
        string s;
        getline(cin,s,lne);
        s=lower(s);
        map<string,ll> m=word(s,cnt);
        vector<ll> v=prefact(cnt);
        map<string,ll>::iterator it;
        for(it=m.begin(); it!=m.end(); it++){
            if(it->second>1)
                for(ll j=1; j<=it->second; j++){
                    ans=(ans*cnt)/j;
                    cnt--;
                }
        }
        while(cnt){
            ans*=cnt;
            cnt--;
        }
        cout<<1<<'/'<<ans<<lne;
    }
//    fileclose
    return 0;
}
