#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n--) {
        int value;
        cin >> value;
        if(value==1 || value==2)
            cout << 2 << endl;
        else if(value%2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}