#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        double L, n, C;
        cin >> L >> n >> C;

        double L_prime = (1 + n * C) * L;

        double h = 0.0;
        if (n != 0) {
            double low = 0.0;
            double high = 1e18;

            for (int i = 0; i < 100; ++i) {
                double mid = (low + high) / 2.0;
                double r = L_prime / mid;
                double sin_theta_2 = L / (2 * r);

                if (abs(sin_theta_2) > 1) {
                    high = mid;
                    continue;
                }

                double theta_2 = asin(sin_theta_2);
                double arc_length = 2 * r * theta_2;

                if (arc_length > L_prime) {
                    high = mid;
                } else {
                    low = mid;
                }
            }

            double theta = low;
            double r = L_prime / theta;
            h = r - sqrt(r * r - (L / 2) * (L / 2));
        }

        cout << "Case " << t << ": " << fixed << setprecision(9) << h << endl;
    }

    return 0;
}
