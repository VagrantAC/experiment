#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5+55;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++ i) {
            cin >> a[i];
        }
        sort(a, a+n);
        int a1 = a[0];
        int a2 = -1;
        for (int i = 0; i < n; ++ i) {
            if (a[i] % a1 != 0) {
                a2 = a[i];
                break;
            }
        }
        if (a2 == -1) {
            cout << "YES" << endl;
            continue;
        }
        bool flag = true;
        for (int i = 0; i < n; ++ i) {
            if (a[i] % a1 != 0 && a[i] % a2 != 0) {
                flag = false;
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