#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll i=1; i<=t; i++){
        ll r,c,cross;
        cin>>r>>c;
        cross=r*c;
        if(r==1 || c==1);
        else if(r==2 || c==2){
            cross=cross/2;
            ll rem=cross%4;
            if(rem==0 || rem==1 || rem==2) cross+=rem;
            else if(rem==3) cross+=1;
        }
        else if(cross%2==0) cross=cross/2;
        else if(cross%2==1) cross=(1+cross)/2;
        cout<<"Case "<<i<<": "<<cross<<lne;
    }
    return 0;
}
