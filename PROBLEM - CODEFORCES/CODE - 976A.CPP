#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,cnt=0;
    cin>>n;
    string s,t;
    cin>>s;
    for(ll i=0; i<n; i++)
        if(s[i]=='1') cnt++;
    n=n-cnt;
    if(cnt==0) t="0";
    else if(cnt==1) t=s;
    else
    {
        t="1";
        for(ll i=0; i<n; i++)
            t+="0";
    }
    cout<<t<<endl;
    return 0;
}
