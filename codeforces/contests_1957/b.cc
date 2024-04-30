#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll getSum(ll n) {
    int ans = 1;
    while (n) {
        n /= 2;
        ans <<= 1;
    }
    return (ans / 2) - 1;
}
int main() {
    int t, n, k;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        if (n == 1) {
            cout << k << endl;
            continue;
        }
        cout << getSum(k) << " " << k - getSum(k) << " ";
        for (int i = 0; i < n-2; ++ i) {
            cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}