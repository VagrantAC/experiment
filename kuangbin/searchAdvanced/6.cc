#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 805;
string str[maxn];
struct Pair2 {
    int type;
    int x, y;
    int v, t;
    Pair2() {}
    Pair2(int _type, int _x, int _y, int _v, int _t) {
        type = _type; x = _x, y = _y; v = _v; t = _t;
    }
};
Pair2 M, G;
vector<Pair2> Z;
bool vis[2][maxn][maxn];
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool check(int type, int dx, int dy, int n, int m, int t) {
    if (dx < 0 || dy < 0 || dx >= n || dy >= m) return false;
    // cout << dx << " " << dy << endl;
    if (str[dx][dy] == 'X') return false;
    if (vis[type][dx][dy]) return false;
    // cout << "t" << t << endl;
    for (int i = 0; i < Z.size(); ++ i) {
        if (abs(Z[i].x-dx) + abs(Z[i].y-dy) <= 2 * t) {
            return false;
        }
    }
    return true;
}
bool checkZ(int type, int dx, int dy, int n, int m, int t) {
    for (int i = 0; i < Z.size(); ++ i) {
        if (abs(Z[i].x-dx) + abs(Z[i].y-dy) <= 2 * t) {
            // cout << Z[i].x << " " << Z[i].y << " --> " << dx << " " << dy << " " << 2*t << endl;
            return false;
        }
    }
    return true;
}
bool processBFS(int n, int m, int t, queue<Pair2>& in) {
    // cout << " in: " << in.empty() << endl;
    while (!in.empty() && in.front().v * t > in.front().t) {
        Pair2 p = in.front();
        in.pop();
        if (!checkZ(p.type, p.x, p.y, n, m, t)) continue;
        // cout << "p.v" << p.v << " " << p.x << " " << p.y << " " << p.t << endl;
        for (int j = 0; j < p.v; ++ j) {
            for (int i = 0; i < 4; ++ i) {
                int dx = step[i][0] + p.x;
                int dy = step[i][1] + p.y;
                if (check(p.type, dx, dy, n, m, t)) {
                    // cout << "out" << dx << " " << dy << endl;
                    in.push(Pair2(p.type, dx, dy, p.v, p.t+1));
                    if (vis[!p.type][dx][dy]) {
                        return true;
                    }
                    vis[p.type][dx][dy] = true;
                }
            }
        }
    }
    return false;
}

int bfs(int n, int m) {
    queue<Pair2> q1, q0;
    q1.push(M);
    vis[M.type][M.x][M.y] = true;
    q0.push(G);
    vis[G.type][G.x][G.y] = true;
    int res = 0;
    while (!q1.empty() || !q0.empty()) {
        res ++;
        // cout << res << endl;
        // cout << (res&1) << endl;
        if (processBFS(n, m, res, q0)) {
            return res;
        }
        if (processBFS(n, m, res, q1)) {
            return res;
        }
    }
    return -1;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t --) {
        Z.clear();
        cin >> n >> m;
        for (int i = 0; i < n; ++ i) {
            cin >> str[i];
            for (int j = 0; j < m; ++ j) {
                vis[0][i][j] = false;
                vis[1][i][j] = false;
                if (str[i][j] == 'M') {
                    M = Pair2(0, i, j, 3, 0);
                }
                if (str[i][j] == 'G') {
                    G = Pair2(1, i, j, 1, 0);
                }
                if (str[i][j] == 'Z') {
                    Z.push_back(Pair2(0, i, j, 0, 0));
                }
            }
        }
        cout << bfs(n, m) << endl;
    }
    return 0;
}