#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,test=0,value=0;
    cin>>n;
    string s;
    cin>>s;
    for(i=0; i<n; i++)
    {
        if(s[i]=='?')
            test++;
    }
    if(test==0)
        cout<<"No"<<endl;
    else
    {
        for(i=1,j=2; j<n-1; i++,j++)
        {
            if(s[i]=='?' && s[j]=='?')
            {
                if(s[i-1]!='?' && s[j+1]!='?')
                    if(s[i-1]!=s[j+1])
                        value++;
            }
        }
        if(value==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

