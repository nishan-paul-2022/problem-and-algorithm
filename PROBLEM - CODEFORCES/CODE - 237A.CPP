#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,i,hour,minute,tem,ans ;
    vector<int> v, v1 ;
    vector<int>::iterator it ;
    cin>>n ;
    for(i=0; i<n; i++)
    {
        cin>>hour>>minute ;
        minute = minute+(hour*60) ;
        v.push_back(minute) ;
    }
    v1 = v ;
    it = unique(v1.begin(),v1.end()) ;
    v1.erase(it,v1.end()) ;
    for(i=0; i<v1.size(); i++)
    {
        tem = count(v.begin(),v.end(),v1[i] ) ;
        if(i==0) ans=tem ;
        ans = max(tem,ans) ;
    }
    cout<<ans ;
    return 0 ;
}

