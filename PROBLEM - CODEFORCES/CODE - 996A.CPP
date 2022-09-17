#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n,sum=0;
    cin>>n;
    sum += n/100;
    n=n%100;
    sum += n/20;
    n=n%20;
    sum += n/10;
    n=n%10;
    sum += n/5;
    n=n%5;
    sum += n;
    cout<<sum;
    return 0;
}
