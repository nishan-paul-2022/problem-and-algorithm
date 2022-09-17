#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int T,i,j,arr[10001],n;
    cin>>T;
    for(j=1; j<=T; j++)
    {
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>n;
        for(i=6; i<=n; i++)
        {
            arr[i]=(arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6])%10000007;
        }
        cout<<"Case "<<j<<": "<<(arr[n]%10000007)<<'\n';
    }
    return 0;
}

