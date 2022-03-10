///CUET_IRON_BAT
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,long long int> mp;
    map<long long int,string> mp1;
    pair<string,long long int> p;
    pair<long long int,string> p1;
    long long int n,k,m,num,index,i,j,sum=0,mn;
    cin>>n>>k>>m;
    string s[n], tem;
    long long int value[n];
    for(i=0; i<n; i++)
        cin>>s[i];
    for(i=0; i<n; i++)
    {
        cin>>value[i];
        p=make_pair(s[i],value[i]);
        p1=make_pair(value[i],s[i]);
        mp.insert(p);
        mp1.insert(p1);
    }
    for(i=0; i<k; i++)
    {
        cin>>num;
        long long int cmp[num];
        mn=pow(10,9)+7;
        for(j=0; j<num; j++)
        {
            cin>>cmp[j];
            mn=min( mn,value[ cmp[j]-1 ] );
        }
        for(j=0; j<num; j++)
        {
            mp[ mp1[value[ cmp[j]-1 ]] ] = mn;
        }
    }
    for(i=0; i<m; i++)
    {
        cin>>tem;
//        cout<<mp[tem]<<' ';
        sum = sum+mp[tem];
    }
    cout<<sum<<endl;
    return 0;
}

