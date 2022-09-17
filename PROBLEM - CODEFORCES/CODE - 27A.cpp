#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,tem,a[3001];
    cin>>n;
    memset(a,0,sizeof(a));
    for(i=0; i<n; i++)
    {
        cin>>tem;
        a[tem]++;
    }
    for(i=1; i<3001; i++)
    {
        if(a[i]==0)
            break;
    }
    cout<<i<<endl;
    return 0;
}
