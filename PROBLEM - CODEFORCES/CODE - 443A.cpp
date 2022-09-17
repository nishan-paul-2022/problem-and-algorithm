#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s ;
    getline(cin,s) ;
    set<char> some ;
    int i=0 ;
    while(s[i]!='\0')
    {
        if(s[i]>='a' && s[i]<='z')
            some.insert(s[i]) ;
        i++ ;
    }
    set<char>::iterator x ;
    for(x=some.begin(); x!=some.end(); x++)
        cout<<*x ;
    cout<<endl ;
    cout<<some.size() ;
    return 0 ;
}
