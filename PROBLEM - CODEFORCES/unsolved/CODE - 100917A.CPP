#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll n;
    cin>>n;
    char a[n][n];
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
            cin>>a[i][j];
    vector<ll> row,col;
    vector< pair< pair<char,ll>,char > > v, v1;
    for(ll i=0; i<n; i++){
        set<char> s;
        for(ll j=0; j<n; j++)
            if(a[i][j]!='?') s.insert(a[i][j]);
        if(s.size()==1){
            row.push_back(i);
            v.push_back( make_pair( make_pair('h',i),*(s.begin()) ) );
        }
    }
    for(ll j=0; j<n; j++){
        set<char> s;
        for(ll i=0; i<n; i++)
            if(a[i][j]!='?') s.insert(a[i][j]);
        if(s.size()==1){
            col.push_back(j);
            v.push_back( make_pair( make_pair('v',j),*(s.begin()) ) );
        }
    }
    map<pair<ll,ll>,ll> m;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
            m[make_pair(i,j)]=1;
    for(auto i:row)
        for(ll j=0; j<n; j++)
            m[make_pair(i,j)]=-1;
    for(auto j:col)
        for(ll i=0; i<n; i++)
            m[make_pair(i,j)]=-1;
    for(ll j=0; j<n; j++){
        ll tst=0;
        char colr;
        if(m[make_pair(0,j)]==1)
            for(ll i=0; i<n; i++){
                if(m[make_pair(i,j)]==1 && a[i][j]!='?' && tst==0){
//                    cout<<'v'<<spc<<j<<spc<<a[i][j]<<lne;
                    v1.push_back( make_pair( make_pair('v',j),a[i][j] ) );
                    colr=a[i][j];
                    tst++;
                }
                if(m[make_pair(i,j)]==1 && a[i][j]!='?' && tst==1 && a[i][j]!=colr){
//                    cout<<'h'<<spc<<i<<spc<<a[i][j]<<lne;
                    v1.push_back( make_pair( make_pair('h',i),a[i][j] ) );
                    tst++;
                }
            }
    }
    map< pair<char,ll>,char > m1;
    for(ll i=0; i<2*n; i++){
        if(i<n) m1[make_pair('h',i)]='1';
        else if(i>=n) m1[make_pair('v',i-n)]='1';
    }
    for(auto i:v1)
        m1[make_pair(i.first.first,i.first.second)]=i.second;
    for(auto i:v)
        m1[make_pair(i.first.first,i.first.second)]=i.second;
    for(auto i:m1)
        if(m1[make_pair(i.first.first,i.first.second)]=='1')
            cout<<i.first.first<<spc<<i.first.second+1<<spc<<'a'<<lne;
    for(auto i:v1)
        cout<<i.first.first<<spc<<i.first.second+1<<spc<<i.second<<lne;
    for(auto i:v)
        cout<<i.first.first<<spc<<i.first.second+1<<spc<<i.second<<lne;
    return 0;
}
