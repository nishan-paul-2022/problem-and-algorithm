///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n=500,x,y,k;
    ll arr[]={1,2,4,10,20,25,50,125,250,500};
    for(ll i=0; i<9; i++){
        for(ll j=i+1; j<10; j++){
            if(arr[i]<arr[j] && arr[j]<2*arr[i]){
                x=arr[i];
                y=arr[j]-arr[i];
                k=500/(arr[i]*arr[j]);
            }
        }
    }
    ll a,b,c;
    a=(x*x-y*y)*k;
    b=2*x*y*k;
    c=(x*x+y*y)*k;
    cout<<a<<spc<<b<<spc<<c<<lne<<(a*b*c);
    return 0;
}

