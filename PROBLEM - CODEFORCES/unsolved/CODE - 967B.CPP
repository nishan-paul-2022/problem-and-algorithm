#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,a,b,i,tem,sum=0,mul,cnt=0;
    cin>>n>>a>>b;
    vector<ll> v;
    for(i=0; i<n; i++)
    {
        cin>>tem;
        v.push_back(tem);
        sum+=tem;
    }
    mul=a*v[0];
    sort(v.begin()+1,v.end(),greater_equal<ll>());
    for(i=1; i<n; i++)
    {
        ll cmp=sum*b;
        if(cmp>mul)
        {
            cnt++;
            sum=sum-v[i];
        }
    }
    cout<<cnt;
}

