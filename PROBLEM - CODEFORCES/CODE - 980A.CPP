#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll i, cnto=0, cntd=0, lgt=s.length();
    for(i=0; i<lgt; i++)
    {
        if(s[i]=='o')
            cnto++;
        else
            cntd++;
    }
    if(cnto==0 || cnto==1)
        cout<<"YES";
    else if(cntd%cnto==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
