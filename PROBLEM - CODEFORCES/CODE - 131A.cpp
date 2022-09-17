#include<iostream>
#include<cstring>
using namespace std ;
int main()
{
    char s[100] ;
    cin>>s ;
    int i, uper=0, length ;
    length = strlen(s) ;
    for(i=1; i<length; i++)
    {
        if(s[i]>='a' && s[i]<='z')
            uper++ ;
    }
    if(uper==0)
    {
        if(s[0]>='a' && s[0]<='z')
            s[0] = s[0]-32 ;
        else if(s[0]>='A' && s[0]<='Z')
            s[0] = s[0]+32 ;
        for(i=1; i<length; i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                s[i] = s[i]+32 ;
        }
    }
    cout<<s ;
    return 0 ;
}
