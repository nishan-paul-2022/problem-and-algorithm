#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    int i = 1;

    while(i <= n+1)
    {
        if(i==n+1)
        {
            //cout<<endl;
            i = 1;
            continue;
        }

        if(a[i]<i || a[i]== 0)
        {
            cout<<i<<endl;
            return 0;
        }

        if(a[i]-n<0)
            a[i] = 0;
        else
            a[i] = a[i] - n;
            //cout<<a[i] <<" ";
        i++;
    }
}
