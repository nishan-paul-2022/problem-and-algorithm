///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    bool a[1001],tst=true;
    ll b[1001], val;
    memset(a,false,sizeof(a));
    memset(b,0,sizeof(b));
    char c=',';
    while(c==','){
        scanf("%ld%c",&val,&c);
        a[val]=true;
    }
    for(ll i=1; i<=1000; i++){
        if(a[i]==true){
            b[i]=i;
            for(ll j=i+1; a[j]==true; j++){
                b[i]=j;
                a[j]=false;
            }
        }
    }
    for(ll i=1; i<=1000; i++){
        if(a[i]==true){
            if(tst==false) cout<<",";
            else tst=false;
            if(b[i]==i) cout<<i;
            else if(b[i]>i) cout<<i<<"-"<<b[i];
        }
    }
    return 0;
}
