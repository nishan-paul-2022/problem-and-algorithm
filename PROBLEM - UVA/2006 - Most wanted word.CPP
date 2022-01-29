///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
ll mx;
void g(string s){
    mx=0;
    ll sze=s.length();
    string tem="",ans;
    map<string,ll> m;
    for(ll i=0; i<sze; i++){
        if((s[i]>=97 && s[i]<=122)||(s[i]>=65 && s[i]<=90)){
            if(s[i]>=65 && s[i]<=90)
                s[i]=s[i]+32;
            tem+=s[i];
        }
        else if(tem!=""){
            m[tem]++;
            if(m[tem]>mx){
                mx=max(mx,m[tem]);
                ans=tem;
            }
            tem="";
        }
    }
    if(mx!=0)
        cout<<setw(4)<<mx<<spc<<ans<<lne;
}
int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);
    do{
        string s;
        getline(cin,s,'#');
        g(s);
    }
    while(mx);
//    fclose(f);
//    system("output.txt");
    return 0;
}

