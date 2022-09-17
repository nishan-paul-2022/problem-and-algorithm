#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
int main()
{
    long long int n,i,tem,s1,s2 ;
    cin>>n ;
    vector<int> v ;
    vector<int>::iterator mx,mn ;
    for(i=0; i<n; i++)
    {
        cin>>tem ;
        v.push_back(tem) ;
    }
    mx=max_element(v.begin(),v.end()) ;
    mn=min_element(v.begin(),v.end()) ;
    s1=count(v.begin(),v.end(),*mx) ;
    s2=count(v.begin(),v.end(),*mn) ;
    if(*mx==*mn)
        tem = n*(n-1)/2 ;
    else
        tem=s1*s2 ;
    cout<<(*mx-*mn)<<" "<<tem ;
    return 0;
}



