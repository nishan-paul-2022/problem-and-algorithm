#include<bits/stdc++.h>
using namespace std;
int main()
{
    int qry;
    string num;
    cin>>num>>qry;
    while(qry--)
    {
        int i;
        if(num[num.length()-1]=='0')
            i=stoi(num)/10;
        else
            i=stoi(num)-1;
        num=to_string(i);
    }
    cout<<num;
    return 0;
}
