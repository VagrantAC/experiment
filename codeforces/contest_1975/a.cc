#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        bool flag = false;
        cin >> n;
        for (int i = 0; i < n; ++ i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 1; j < n; ++ j) {
                if (a[(i+j)%n] > a[(i+j+1)%n]) {
                    break;
                }
                if (j+1 == n) {
                    flag = true;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}