#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n;
    cin>>n;
    queue<ll> q;
    string s;
    cin>>s;
    list<char> l;
    for(ll i=0; i<n; i++){
        if( (n%2==1 && i%2==0) || (n%2==0 && i%2==1) )
            l.push_back(s[i]);
        else if( (n%2==1 && i%2==1) || (n%2==0 && i%2==0) )
            l.push_front(s[i]);
    }
    while(l.size()>0){
        cout<<l.front();
        l.pop_front();
    }
    return 0;
}
