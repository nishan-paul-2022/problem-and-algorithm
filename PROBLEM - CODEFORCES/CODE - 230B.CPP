#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;
int main()
{
    long long int n,x,root,i,j ;
    cin>>n ;
    vector<long long int> check(1000000,1) ;
    check[0]=check[1]=0 ;
    for(i=2; i<=1000; i++)
    {
        if(check[i]==1)
            for(j=2; j<=1000000/i; j++)
                check[i*j]=0 ;
    }
    while(n--)
    {
        cin>>x ;
        root = sqrt(x) ;
        if(root*root==x && check[root]==1)
            cout<<"YES"<<endl ;
        else
            cout<<"NO"<<endl ;
    }
    return 0 ;
}

