#define ONLINE_JUDGE 1
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll test;
	cin>>test;
	while(test--){
		ll tem;
		cin>>tem;
		tem=tem%3;
		ll val=pow(2,tem);
		cout<<val<<'\n';
	}
	return 0;
}