///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T1,typename T2>     ///BINARY_SEARCH_FOR_GIVEN_VALUE_IN_VECTOR
ll binary(T1 data,T2 value,ll &test) ///DATA:IN_VECTOR_FORMAT, VALUE:GIVEN_VALUE, TEST:CHECKING_EXISTENCE
{                                   ///LL:RETURN INDEX_NUMBER_IF_EXISTS OR LEVEL_NUMBER_IF_DOES_NOT_EXIST
    ll index, mid, start=0, close = data.size()-1;
    test=0;
    while(start<=close && test==0)
    {
        mid=(start+close)/2;
        if(data[mid]==value)
        {
            index=mid;
            test=1;
        }
        else if(data[mid]<value)
            start=mid+1;
        else if(data[mid]>value)
            close=mid-1;
    }
    if(test==0) index=start;
    return index;
}
int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);

    ll n,m,tem,sum=0,i,index,test;
    scanf("%lld",&n);
    vector<ll> v;
    for(i=0; i<n; i++)
    {
        scanf("%lld",&tem);
        sum+=tem;
        v.push_back(sum);
    }
    scanf("%lld",&m);
    for(i=0; i<m; i++)
    {
        scanf("%lld",&tem);
///        index= binary(v,tem,test); ///TIME_LIMIT_WHY_?
        index = distance( lower_bound(v.begin(),v.end(),tem) , v.begin() );
        printf("%lld\n",abs(index)+1);
    }

//    fclose(f);
//    system("output.txt");
    return 0;
}


