#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std ;
int main()
{
    long long int n,i,tem,sum=0 ;
    cin>>n ;
    vector<int> v, vp ;
    for(i=0; i<n; i++)
    {
        cin>>tem ;
        v.push_back(tem) ;
        vp.push_back(i+1) ;
    }
    sort(v.begin(),v.end()) ;
    for(i=0; i<n; i++)
        sum=sum+fabs(v[i]-vp[i]) ;
    cout<<sum ;
    return 0 ;
}

