#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,val=0;
    string s,res;
    cin>>n;
    map<string,int> m;
    cin>>s;
    for(int i=1; i<s.length(); i++)
    {
        string tem="  ";
        tem[0]=s[i-1];
        tem[1]=s[i];
        m[tem]++;
        if(m[tem]>=val)
        {
            res=tem;
            val=m[tem];
        }
    }
    cout<<res;
    return 0;
}
