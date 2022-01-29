#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,cnt=0;
    cin>>n>>m;
    if(n>=m)
        cout<<n-m;
    else
    {
        while(n<m)
        {
            if(m%2==0)
                m/=2;
            else
                m++;
            cnt++;
        }
        cout<<cnt+n-m;
    }
    return 0;
}
