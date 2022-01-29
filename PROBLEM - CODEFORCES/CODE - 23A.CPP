///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
vector<string> substring(string s)/// LENGTH^3
{
    vector<string> v;
    ll sze=s.length();
    for(ll i=0; i<sze; i++)
        for(ll j=0; j<sze-i; j++){
            string tem="";
            for(ll k=j; k<=j+i; k++)
                tem+=s[k];
            v.push_back(tem);
        }
    return v;
}
int main()
{
    string s;
    cin>>s;
    ll sze=s.size()-1, k=2, ans=0;
    for(ll i=sze; i>=1 && ans==0; i--){
        set<string> cat;
        set<string>::iterator it;
        for(ll j=0; j<k; j++){
            string tem=s.substr(j,i);
            it=find(cat.begin(),cat.end(),tem);
            if(it==cat.end())
                cat.insert(tem);
            else
                ans=i;
        }
        k++;
    }
    cout<<ans;
    return 0;
}
