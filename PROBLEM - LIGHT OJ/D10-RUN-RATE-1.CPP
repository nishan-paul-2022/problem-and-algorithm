#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    float r1, r2, b, crr, rrr;
    cin >> t;
    
    while(t--) {
        cin >> r1 >> r2 >> b;
        crr = r2 / ((300 - b)/6);
        
        if(r2 > r1) {
            rrr = 0.00;
        }
        else {
           rrr = (r1 - r2 + 1) / (b/6);
        }

        printf("%.2f %.2f\n", crr, rrr);
    }
}