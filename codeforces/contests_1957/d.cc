#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100;
vector<int> vec[maxn];
int res[100000+55];
int getOne(int n) {
    int cnt = 0;
    while (n) {
        n /= 2;
        cnt ++;
    }
    return cnt;
}
int main() {
    int t, n, a;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < 80; ++ i) {
            vec[i].clear();
        }
        for (int i = 0; i < n; ++ i) {
            cin >> a;
            vec[getOne(a)].push_back(i);

        }
        ll ans = 0;
        for (int i = 0; i < 80; ++ i) {
            if (!vec[i].size()) continue;
            vector<int> v[2];
            for (int j = 0; j < vec[i].size(); ++ j) {
                v[0].push_back(0);
                v[1].push_back(0);
                if (j+1 == vec[i].size()) {
                    v[j&1][j] = n - vec[i][j] - 1;
                } else {
                    v[j&1][j] = vec[i][j+1] - vec[i][j]-1;
                }
                cout << v[0][j] << " " << v[1][j] << endl;
            }
            cout << "=======" << endl;
            for (int j = 1; j < vec[i].size(); ++ j) {
                v[0][j] += v[0][j-1];
                v[1][j] += v[1][j-1];
            }

            vector<int> w[2];
            for (int j = 0; j < vec[i].size(); ++ j) {
                w[0].push_back(0);
                w[1].push_back(0);
                if (j == 0) {
                    w[j&1][j] = vec[i][j];
                } else {
                    w[j&1][j] = vec[i][j] - vec[i][j-1]-1;
                }
                cout << w[0][j] << " " << w[1][j] << endl;
            }
            cout << "=======" << endl;
            for (int j = vec[i].size()-2; j >= 0; -- j) {
                w[0][j] += w[0][j+1];
                w[1][j] += w[1][j+1];
            }
            for (int j = 0; j < vec[i].size(); ++ j) {
                ans += v[!(j&1)][j] * w[(j&1)][j];
                ans += v[(j&1)][j] * w[!(j&1)][j];
                cout << ans << " " << v[0][j] << " " << v[1][j] << " " << w[0][j] << " " << w[0][j] << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}