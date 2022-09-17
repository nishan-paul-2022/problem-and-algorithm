#define ONLINE_JUDGE 1
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    ll T;
    cin>>T;
    while(T--){
        ll a,b;
        cin>>a>>b;
        if(a>b){
            cout<<"Argentina "<<a<<" - "<<b<<" Brazil"<<lne;
        }
        else if(a<b){
            cout<<"Brazil "<<b<<" - "<<a<<" Argentina"<<lne;
        }
    }
    return 0;
}
