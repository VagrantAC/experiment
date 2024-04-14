#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string str[2][12];
bool vis[2][12][12];

struct Pair3 {
    int x, y, i;
    int t;
    Pair3(int _x, int _y, int _i, int _t) {
        x = _x, y = _y, i = _i, t = _t;
    }
};
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool solve(int n, int m, int t) {
    queue<Pair3> que;
    for (int i = 0; i < 2; ++ i) {
        for (int j = 0; j < n; ++ j) {
            for (int k = 0; k < m; ++ k) {
                vis[i][j][k] = false;
                if (str[i][j][k] == 'S') {
                    que.push(Pair3(j, k, i, 0));
                    vis[i][j][k] = true;
                }
            }
        }
    }
    while (!que.empty()) {
        Pair3 p = que.front();
        que.pop();
        if (str[p.i][p.x][p.y] == 'P') return true;
        if (p.t == t) continue;
        for (int i = 0; i < 4; ++ i) {
            int dx = step[i][0] + p.x;
            int dy = step[i][1] + p.y;
            if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
            int di = p.i;
            if (str[di][dx][dy] == '#') {
                di = !di;
            }
            if (str[di][dx][dy] == '*' || str[di][dx][dy] == '#') continue;
            if (vis[di][dx][dy]) continue;
            // cout << str[di][dx][dy] << di << " " << dx << " " << dy << " " <<p.t +1 << endl;
            que.push(Pair3(dx, dy, di, p.t+1));
            vis[di][dx][dy] = true;
        }
    }
    return false;    
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < 2; ++ i) {
            for (int j = 0; j < n; ++ j) {
                cin >> str[i][j];
            }
        }
        cout << (solve(n, m, k) ? "YES" : "NO") << endl;
    }
    return 0;
}