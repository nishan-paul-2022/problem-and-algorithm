#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s,t ;
    int i,j,k,sum=0 ;
    cin>>s ;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='Q')
        {
            for(j=i+1; s[j]!='\0'; j++)
            {
                if(s[j]=='A')
                {
                    for(k=j+1; s[k]!='\0'; k++)
                    {
                        if(s[k]=='Q') sum++ ;
                    }
                }
            }

        }
    }
    cout<<sum ;
}
