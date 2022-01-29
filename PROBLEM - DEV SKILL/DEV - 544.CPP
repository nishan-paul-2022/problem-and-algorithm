#define ONLINE_JUDGE 1
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll test;
    cin>>test;
    string s[4]={"I am going to ask you this one time, where is Gamora?","I will do you one better, who is Gamora?","I will do you one better, why is Gamora?","What is Gamora?"};
    string name[3]={"Quill","Stark","Drax"};
    while(test--)
    {
        string tem;
        cin>>tem;
        if(tem==name[0]) cout<<s[0]<<'\n';
        else if(tem==name[1]) cout<<s[1]<<'\n';
        else if(tem==name[2]) cout<<s[2 ]<<'\n';
        else cout<<s[3]<<'\n';
    }
    return 0;
}
