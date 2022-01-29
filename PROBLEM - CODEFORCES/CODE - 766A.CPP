#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a==b)
        cout<<-1;
    else
        cout<<max(a.size(),b.size());
    return 0;
}
