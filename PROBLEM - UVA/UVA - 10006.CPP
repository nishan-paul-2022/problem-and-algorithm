#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
bool prime[65001];
void f(){
    ll sze=sizeof(prime)/sizeof(prime[0]);
    memset(prime,true,sze);
    for(ll i=3; i*i<=65000; i+=2)
        if(prime[i]==true)
            for(ll j=i*i; j<=65000; j+=2*i)
                prime[j]=false;
}
ll mod(ll base,ll pwr,ll rem){
    if(pwr==0) return 1;
    ll val = mod(base,pwr/2,rem);
    val = (val*val)%rem;
    if(pwr%2==1) val = (val*(base%rem))%rem;
    return val;
}
bool carma(ll num){
    for(ll i=2; i<=num-1; i++)
        if(mod(i,num,num)!=i)
            return false;
    return true;
}
int main()
{
    f();
    ll num;
    cin>>num;
    while(num!=0){
        bool chk=false, car=true;
        if(num%2==0 || prime[num]==false){
            chk=true;
            car=carma(num);
        }
        if(chk==true && car==true)
            cout<<"The number "<<num<<" is a Carmichael number."<<lne;
        else
            cout<<num<<" is normal."<<lne;
        cin>>num;
    }
    return 0;
}
