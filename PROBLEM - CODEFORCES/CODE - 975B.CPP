#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll ans = 0;
    ll n = 14;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }

    for(ll i=0; i<n; i++){
        vector<ll> dup = arr;
        ll value = dup[i];
        dup[i] = 0;
        ll round = value / n;
        ll rem = value % n;
        for(ll j=0; j<n; j++) {
            dup[j] += round;
        }

        for (ll j=0; j<rem; j++) {
            ll idx = (i+j+1) % n;
            dup[idx]++;
        }

        ll sum = 0;
        for (ll j=0;j<n;j++){
            if (dup[j]%2 == 0){
                sum += dup[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
