#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
int main()
{
    long long int n,d,i,result=0 ;
    vector<long long int> v ;
    cin>>n>>d ;
    for(i=0; i<n; i++)
    {
        long long int tem ;
        cin>>tem ;
        v.push_back(tem) ;
    }
    for(i=0; i<n-2; i++)
    {
        long long int tem,pos,carry ;
        vector<long long int>::iterator it ;
        tem=v[i]+d ;
        it=lower_bound(v.begin(),v.end(),tem) ;
        pos=it-v.begin() ;
        if(tem!=v[pos])
            pos-- ;
        pos=pos-i ;
        if(pos>1)
        {
            carry=pos*(pos-1)/2 ;
            result=result+carry ;
        }
    }
    cout<<result ;
    return 0 ;
}

