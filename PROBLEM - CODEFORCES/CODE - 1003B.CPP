#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,x,mx,a1,b1;
    cin>>a>>b>>x;
    a1=a; b1=b;
    mx=max(a,b);
    string s="";
    for(ll i=0; i<x; i++){
        if(mx==a1){
            if(i%2==0){
                s+="0";
                a--;
            }
            else{
                s+="1";
                b--;
            }
        }
        else if(mx==b1){
            if(i%2==0){
                s+="1";
                b--;
            }
            else{
                s+="0";
                a--;
            }
        }
    }
    if(s[x-1]=='0'){
        for(ll i=0; i<a; i++){
            s+="0";
        }
        for(ll i=0; i<b; i++){
            s+="1";
        }
    }
    else if(s[x-1]=='1'){
        for(ll i=0; i<b; i++){
            s+="1";
        }
        for(ll i=0; i<a; i++){
            s+="0";
        }

    }
    cout<<s;
    return 0;
}
