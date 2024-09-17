#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5+55;
int a[maxn];

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 0; i < m; ++ i) {
            cin >> a[i];
        }
        sort(a, a+m);
        while (q --) {
            int i, l = 0, r = m-1;
            cin >> i;
            if (i <= a[0]) {
                cout << a[0] - 1 << endl;
                continue;
            }
            if (i >= a[m-1]) {
                cout << n - a[m-1] << endl;
                continue;
            }
            while (l < r) {
                int mid = (l+r) >> 1;
                if (a[mid] >= i) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
            cout << (a[r] - a[r-1]) / 2 << endl;
        }
    }
    return 0;
}