#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
using namespace std;
int main()
{
	ll n,eve=0,odd=0,j=1;
	cin>>n;
	ll a[n];
	n=n/2;
	for(ll i=0; i<n; i++){
        cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=0; i<n; i++){
        eve+=abs(a[i]-j);
        odd+=abs(a[i]-j-1);
        j+=2;
	}
	cout<<min(eve,odd);
}
