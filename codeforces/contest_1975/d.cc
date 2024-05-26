#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

const int MAXN = 2e5+55;
vector<int> edge[MAXN];
int dis[MAXN];

void push(int u, int v) {
    edge[u].push_back(v);
    edge[v].push_back(u);
}

void init(int n) {
    for (int i = 0; i <= n; ++ i) {
        edge[i].clear();
    }
}
int Maxdeep = 0;
int dfs(int root, int fa, int deep) {
    Maxdeep = max(Maxdeep, deep);
    dis[root] = edge[root].size();
    for (int i = 0; i < edge[root].size(); ++ i) {
        int p = edge[root][i];
        if (p == fa) continue;
        dis[root] += dfs(p, root, deep+1);
    }
    return dis[root];
}

int R = 0;
int dfsAB(int a, int b, int root, int fa, int dep) {
    // cout << "root: " << root << " " << edge[root].size() << endl;
    if (root == b) {
        return dep;
    }
    for (int i = 0; i < edge[root].size(); i ++) {
        int p = edge[root][i];
        // cout << p << " " <<  root << " " << b << endl;
        if (fa == p) continue;
        int res = dfsAB(a, b, p, root, dep+1);
        // cout << res << endl;
        if (res != 0) {
            if (res/2 == dep+1) {
                R = p;
            }
            return res;
        }
    }
    return 0;
}


int main() {
    int t;
    cin >> t;
    while (t --) {
        R = 0;
        Maxdeep = 0;
        int n, a, b, u, v;
        cin >> n;
        init(n);
        cin >> a >> b;
        for (int i = 1; i < n; ++ i) {
            cin >> u >> v;
            push(u, v);
        }
        int distAB = (dfsAB(a, b, a, -1, 0) + 1) / 2;
        int res = dfs(R == 0 ? a : R, -1, 0) - Maxdeep;
        cout << distAB + res << endl;
    }
    return 0;
}