#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, sum = 0;
    cin>>n;
    for(int i=0; i<n; i++) {
        int opinion;
        cin>>opinion;
        sum += opinion;
    }
    if(sum)
        cout<<"HARD";
    else
        cout<<"EASY";
    return 0;
}