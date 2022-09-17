#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i;
    cin>>T;
    for(i=0; i<T; i++)
    {
        int n;
        cin>>n;
        if(n<=10)
            cout<<n<<' '<<0<<'\n';
        else
            cout<<10<<' '<<(n-10)<<'\n';
    }
    return 0;
}
