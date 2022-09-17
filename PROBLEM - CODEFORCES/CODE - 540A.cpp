#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,sum=0,v1,v2;
    cin>>n;
    string first,second;
    cin>>first;
    cin>>second;
    for(i=0; i<n; i++)
    {
        v1 = abs(first[i]-second[i]);
        v2 = 10-v1;
        sum=sum+min(v1,v2);
    }
    cout<<sum<<endl;
    return 0;
}
