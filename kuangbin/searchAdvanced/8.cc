#pragma GCC optimize(2)

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 15;
const int maxxn = 6e5+55;
const int inf = 0x3f3f3f3f;

struct Pair2 {
    int v, w;
    Pair2(int _v, int _w) {
        v = _v, w = _w;
    }
    Pair2(){}
};
int status[maxn];

bool initStatus(int n, int state) {
    bool flag = true;
    for (int i = 0; i < n; ++ i) {
        status[i] = state % 3;
        state /= 3;
        if (!status[i]) {
            flag = false;
        }
    }
    return flag;
}

int dp[maxn][maxxn];
int three[maxn];
Pair2 edges[maxxn];
int nex[maxxn], cur[maxn];
int total;

inline void init(int n) {
    total = 0;
    three[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        three[i] = three[i-1] * 3;
    }
    for (int i = 0; i <= n; ++ i) {
        cur[i] = -1;
        for (int j = 0; j <= three[n]; ++ j) {
            dp[i][j] = inf;
        }
        dp[i][0] = 0;
    }
}
// 60000 * 10 * 100
// 6e4 * 1e3
// 1e7

inline int dfs(int pos, int state) {
    if (dp[pos][state] != inf) {
        return dp[pos][state];
    }
    int res = inf;
    for (int i = cur[pos]; i != -1; i = nex[i]) {
        Pair2& p = edges[i];
        // cout << pos << " --> " << p.v << endl;
        if (!status[p.v]) {
            continue;
        }
        status[p.v] --;
        int ans = dp[p.v][state - three[p.v]];
        status[p.v] ++;
        // cout << pos << " state:" << state << " --> " << p.v << " " << ans << endl;
        // if (ans == inf) continue;
        res = min(res, ans + p.w);
    }
    dp[pos][state] = res;
    return res;
}

void add(int a, int b, int c) {
    nex[total] = cur[a];
    cur[a] = total;
    // cout << nex[total] << " ---> " << total << endl;
    edges[total].v = b;
    edges[total].w = c;
    total ++;
}
int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) {
        init(n);
        int a, b, c;
        for (int i = 0; i < m; ++ i) {
            cin >> a >> b >> c;
            a --, b --;
            add(a, b, c);
            add(b, a, c);
        }
        // for (int i = 0; i < 2*m; ++ i) {
        //     cout << nex[i] << " " << i << endl;
        // }
        int res = inf;
        for (int i = 0; i < three[n]; ++ i) {
            bool flag = initStatus(n, i);
            // if (!flag) continue;
            for (int j = 0; j < n; ++ j) {
                if (!status[j]) continue;
                status[j] --;
                int ans = dfs(j, i-three[j]);
                status[j] ++;
                // cout << j << " state???:" << i << ":" << ans << " " << flag << endl;
                // for (int k = 0; k < n; ++ k) {
                //     cout << status[k] << " ";
                // }
                // cout << endl;
                if (flag) {
                    res = min(res, ans);
                }
            }
        }
        if (res == inf) {
            res = -1;
        }
        cout << res << endl;
    }
    return 0;
}