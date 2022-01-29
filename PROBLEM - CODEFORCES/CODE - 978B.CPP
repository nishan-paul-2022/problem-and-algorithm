#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,cnt=0, rmv=0;
    string s;
    cin>>n;
    cin>>s;
    for(ll i=0; i<n; i++)
    {
        if(s[i]=='x') cnt++;
        else if(s[i]!='x'){
            if(cnt>2) rmv+=cnt-2;
            cnt=0;
        }
    }
    if(cnt>2)
        rmv+=cnt-2;
    cout<<rmv;
    return 0;
}
