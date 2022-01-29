///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T1,typename T2>     ///BINARY_SEARCH_FOR_GIVEN_VALUE_IN_VECTOR
ll binary(T1 data,T2 value,ll &test) ///DATA:IN_VECTOR_FORMAT, VALUE:GIVEN_VALUE, TEST:CHECKING_IF_IN_THE_INDEX_or_LEVEL
{                                   ///RETURN:INDEX_NUMBER_or_LEVEL_NUMBER_IF_EXISTS / MINUS_ONE_IF_DOES_NOT_EXIST
    ll index, mid, start=0, close = data.size()-1;
    if(data[start]>value || data[close]<value)
        return -1;
    else
    {
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
}
class sieve
{
    public:
        vector<int> make_prime(int range)
        {
            vector<int> v(1+range/32,0);
            int sqrtR=sqrt(range)+1;
            for(int i=3; i<=sqrtR; i+=2)
                if( ( v[i>>5] & 1<<(i&31) )==0 )
                    for(int j=i*i; j<=range; j+=2*i)
                        v[j>>5] = ( v[j>>5] | 1<<(j&31) );
            return v;
        }
        void prnt_prime(vector<int> v,int range,int start=1)
        {
            if(start<3) printf("%d ",2);
            if(start==1) start+=2;
            if(start%2==0) start+=1;
            for(int i=start; i<=range; i+=2)
                if( ( v[i>>5] & 1<<(i&31) )==0 )
                    printf("%d ",i);
            printf("\n");
        }
        bool check_prime(vector<int> v,int i)
        {
            if( (i%2==0 && i!=2)||(v[i>>5] & 1<<(i&31))==1 )
                return false;
            else
                return true;
        }
        int cnt_prime(vector<int> v,int range,int start=1)
        {
            int cnt=0;
            if(start<3) cnt++;
            if(start==1) start+=2;
            if(start%2==0) start+=1;
            for(int i=start; i<=range; i+=2)
                if( ( v[i>>5] & 1<<(1&31) )==0 )
                    cnt++;
            return cnt;
        }
        void make_factor(vector<int> &v1,vector<int> &v2,int value)
        {
            int i,j,tem,index,cnt;
            index=ceil(value/2);
            vector<int> v=make_prime(index);
            for(i=1; i<=index; i++)
            {
                if(i==1) tem=2;
                else tem=i;
                if( ( v[tem>>5] & 1<<(tem&31) )==0 )
                {
                    for(j=0; value%tem==0; j++)
                        value/=tem;
                    if(j>0)
                    {
                        v1.push_back(tem);
                        v2.push_back(j);
                    }
                }
            }
        }
        void prnt_factor(vector<int> v1,vector<int> v2,int value)
        {
            int length=v1.size();
            if(length==0)
                printf("%d(%d)",value,1);
            else
            {
                for(int i=0; i<length; i++)
                    printf("%d(%d) ",v1[i],v2[i]);
                printf("\n");
            }
        }
};

int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);

    ll virus, day=1, m;
    scanf("%lld",&virus);
    while(virus>1)
    {
        m=1;
        while(2*m<=virus)
            m=2*m;
        virus-=m;
        day+=1;
    }
    if(virus==0) day-=1;
    printf("%lld",day);
//    fclose(f);
//    system("output.txt");
    return 0;
}
