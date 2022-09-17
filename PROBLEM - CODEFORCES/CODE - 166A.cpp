#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
using namespace std ;
bool compare(pair<int,int> x,pair<int,int> y)
{
    bool i ;
    i = (x.first>y.first) || (x.first==y.first && x.second<y.second) ;
    return i ;
}
int main()
{
    vector< pair<int,int> > v ;
    int n,p,x,y,i,result=0 ;
    cin>>n>>p ;
    for(i=0; i<n; i++)
    {
        cin>>x>>y ;
        v.push_back(make_pair(x,y)) ;
    }
    sort(v.begin(),v.end(),compare) ;
    p-- ;
    x=p-1 ;
    y=p+1 ;
    while (x>=0 && v[x].first==v[p].first && v[x].second==v[p].second)
        x-- ;
    while (y<n && v[y].first==v[p].first && v[y].second==v[p].second)
        y++ ;
    x++ ; y-- ;
    cout<<(y-x+1) ;
    return 0 ;
}

