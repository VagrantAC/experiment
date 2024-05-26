#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
const int maxn = 1e5+55;
int a[maxn];
int b[maxn];
unordered_map<int, int> mp;

bool check(int val, int n) {
    for (int i = 1; i < n; ++ i) {
        if (a[i] >= val && ((i >= 2 && a[i-2] >= val) || a[i-1] >= val)) {
            return true;
        }
    }
    return false;
    // mp.clear();
    // for (int i = 0; i < n; ++ i) {
    //     if (val > a[i]) b[i] = -1;
    //     else b[i] = 1;
    // }
    // mp[0] = true;
    // for (int i = 0; i < n; ++ i) {
    //     if (i) {
    //         b[i] += b[i-1];
    //     }
    //     if (mp[b[i]]) {
    //         return true;
    //     }
    //     mp[b[i]] = true;
    // }
    // return false;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++ i) {
            cin >> a[i];
        }
        int l = 0, r = 1000000000;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, n)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}