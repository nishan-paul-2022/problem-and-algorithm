#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std ;
int main()
{
    int i,sum=0 ;
    string s,backup ;
    string::iterator it ;
    cin>>s ;
    sort(s.begin(),s.end()) ;
    backup=s ;
    it=unique(backup.begin(),backup.end()) ;
    backup.erase(it,backup.end()) ;
    for(i=0; i<backup.length(); i++)
    {
        int tem = count(s.begin(),s.end(),backup[i]) ;
        if( tem%2 != 0 )
            sum++ ;
    }
    if( sum==0 || sum%2 != 0)
        cout<<"First" ;
    else
        cout<<"Second" ;
    return 0 ;
}

