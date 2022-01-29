#include<bits/stdc++.h>
using namespace std ;
int main()
{
    long long int price,extra,i,sum ;
    cin>>price>>extra ;
    sum = price ;
    for(i=1; !(sum%10==0 || sum%10==extra); i++)
        sum=sum+price ;
    cout<<i ;
    return 0 ;
}
