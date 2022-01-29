#include<bits/stdc++.h>
#define ll long long int
#define line '\n'
using namespace std;
int main()
{
    ll val;
    cin>>val;
    val++;
    if(val==1)
        cout<<0;
    else if(val%2!=0)
        cout<<val;
    else
        cout<<val/2;
    return 0;
}

