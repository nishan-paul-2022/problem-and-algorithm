#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i;
    cin>>n;
    map<string,string> m;
    map<string,string>::iterator it;
    m["purple"]="Power";
    m["green"]="Time";
    m["blue"]="Space";
    m["orange"]="Soul";
    m["red"]="Reality";
    m["yellow"]="Mind";
    for(i=0; i<n; i++)
    {
        string s;
        cin>>s;
        m[s]="X";
    }
    cout<<6-n<<'\n';
    for(it=m.begin(); it!=m.end(); it++)
        if(it->second!="X")
            cout<<it->second<<'\n';
    return 0;
}
