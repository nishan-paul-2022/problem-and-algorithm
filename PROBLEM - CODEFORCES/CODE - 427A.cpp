#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,sum=0,num=0;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>0)
            sum+=a[i];
        else if(sum>0)
            sum--;
        else
            num++;
    }
    cout<<num;
    return 0;
}
