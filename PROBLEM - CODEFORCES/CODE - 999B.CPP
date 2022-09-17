#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
set<ll> single_divisor(ll n)/// SQRT(N)
{
    set<ll> v;
    ll range=1+sqrt(n);
    for(ll i=1; i<=range; i++)
        if(n%i==0){
            v.insert(i);
            v.insert(n/i);
        }
    return v;
}
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    set<ll> v=single_divisor(n);
    for(auto i:v)
        reverse(s.begin(),s.begin()+i);
    cout<<s;
    return 0;
}
