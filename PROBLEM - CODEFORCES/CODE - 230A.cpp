#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int s,num,i,drO,drG,test=0 ;
    cin>>s>>num ;
    multiset< pair<int,int> > m ;
    multiset< pair<int,int> >::iterator it ;
    for(i=0; i<num; i++)
    {
        cin>>drO>>drG ;
        m.insert(make_pair(drO,drG)) ;
    }
    it = m.begin() ;
    while( s>it->first && test<num )
    {
        s+=it->second ;
        it++ ;
        test++ ;
    }
    if(test==num)
        cout<<"YES" ;
    else
        cout<<"NO" ;
    return 0 ;
}

