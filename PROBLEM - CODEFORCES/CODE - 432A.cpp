#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,test=0;
    cin>>n>>k;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]<=5-k)
            test++;
    }
    cout<<test/3;
    return 0;
}
