#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t --) {
        ll n;
        cin >> n;
        ll r = sqrt(n);
        if (r * r < n) {
            r ++;
        }
        cout << r-1 << endl;
    }
    return 0;
}