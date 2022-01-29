#define ONLINE_JUDGE 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    char c[100];
    while(T--)
    {
        cin>>c;
        int val=0;
        for(int i=0; c[i]!='\0'; i++)
            val+=c[i];
        if(val%20==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
	return 0;
}
