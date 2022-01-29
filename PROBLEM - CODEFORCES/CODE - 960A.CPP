///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll ca,cb,cc,i,testa=0,testb=0,testc=0;
    string s;
    cin>>s;
    ca=count(s.begin(),s.end(),'a');
    cb=count(s.begin(),s.end(),'b');
    cc=count(s.begin(),s.end(),'c');
    for(i=0; i<s.size()-cc-cb; i++)
        if(s[i]=='a')
            testa++;
    for(i=ca; i<s.size()-cc; i++)
        if(s[i]=='b')
            testb++;
    for(i=cb; i<s.size(); i++)
        if(s[i]=='c')
            testc++;
    if( testa==ca && testb==cb && testc==cc && ca>0 && cb>0 && (cc==ca || cc==cb) )
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

