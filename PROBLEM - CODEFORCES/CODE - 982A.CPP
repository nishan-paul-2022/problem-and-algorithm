#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,cnt=0,blk;
    cin>>n;
    string s;
    cin>>s;
    if(n==1)
        if(s[0]=='0') cout<<"NO";
        else cout<<"YES";
    else if(n==2)
        if( (s[0]=='0' && s[1]=='0') || (s[0]=='1' && s[1]=='1') )
           cout<<"NO";
        else cout<<"YES";
    else
    {
        for(ll i=0; i<n-1; i++){
            if(s[i]=='1' && s[i+1]=='1')
                cnt++;
        }
        if(cnt!=0)
            cout<<"NO";
        else
        {
            blk=0;
            if((s[0]=='0' && s[1]=='0') || (s[n-1]=='0' && s[n-2]=='0'))
                blk++;
            if(blk) cout<<"NO";
            else{
                blk=0;
                for(ll i=0; i<n-2; i++)
                    if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0')
                        blk++;
                if(blk) cout<<"NO";
                else cout<<"YES";
            }
        }
    }
    return 0;
}
