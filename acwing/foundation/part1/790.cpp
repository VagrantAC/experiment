#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double n;
    std::cin >> n;
    int coefficient = 1;
    if (n < 0) {
        coefficient = -1;
        n = -n;
    }
    double l = 0, r = 100000000;
    while (r - l >= 0.00000001) {
        double mid = (l + r) / 2.0;
        if (mid * mid * mid < n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.6f\n", coefficient * r);
}