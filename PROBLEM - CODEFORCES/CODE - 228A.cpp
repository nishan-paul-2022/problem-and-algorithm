#include<bits/stdc++.h>
using namespace std ;
int main()
{
    set<int> some ;
    int a[4],i,sum=0,test=0 ;
    for(i=0; i<4; i++)
    {
        cin>>a[i] ;
        some.insert(a[i]) ;
    }
    set<int>::iterator x ;
    for(x=some.begin(); x!=some.end(); x++)
    {
        for(i=0; i<4; i++)
            if(a[i]==*x)
                sum++ ;
        test++ ;
    }
    cout<<sum-test ;
    return 0 ;
}
