#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,value;
    string s;
    cin>>n;
    value=n;
    cin>>s;
    for(i=1; i<n; i++)
    {
        if(s[i-1]!='D')
        {
            if(s[i]!=s[i-1])
            {
                value--;
                s[i]='D';
            }
        }
    }
    cout<<value<<endl;
    return 0;
}
