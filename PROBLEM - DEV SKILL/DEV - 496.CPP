#define ONLINE_JUDGE 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,i,sum,cnt;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>s;
		sum=0,cnt=0;
		for(i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
                cnt++;
            else if(s[i]=='0')
            {
                sum+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        sum+=cnt*(cnt+1)/2;
        cout<<sum<<endl;
	}
	return 0;
}
