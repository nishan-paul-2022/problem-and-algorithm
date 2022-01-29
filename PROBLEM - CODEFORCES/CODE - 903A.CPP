#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll tst;
    cin>>tst;
    while(tst--){
        bool chk=false;
        ll num;
        cin>>num;
        ll thr=num/3;
        for(ll i=0; i<=thr; i++){
            ll b=(num-3*i)/7;
            if(num==7*b+3*i){
//                cout<<i<<spc<<b<<lne;
                chk=true;
            }
        }
        if(chk==true)
            cout<<"YES"<<lne;
        else if(chk==false)
            cout<<"NO"<<lne;
    }
    return 0;
}
