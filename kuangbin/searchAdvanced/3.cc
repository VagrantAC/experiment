#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 23;
vector<int> edges[maxn];
vector<int> res;
int cas = 1;
void dfs(int pos, int vis, int m) {
  if (res.size() == 21) {
    cout << cas++ << ": ";
    for (auto p : res) {
      cout << " " << p;
    }
    cout << endl;
    return;
  }
  for (auto p : edges[pos]) {
    if (p == m && res.size() != 20)
      continue;
    if (!((vis >> p) & 1)) {
      res.push_back(p);
      dfs(p, vis + (1 << p), m);
      res.pop_back();
    }
  }
}

int main() {
  int v;
  for (int i = 1; i <= 20; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> v;
      edges[i].push_back(v);
    }
    sort(edges[i].begin(), edges[i].end());
  }
  int m;
  while (cin >> m && m) {
    cas = 1;
    res.clear();
    res.push_back(m);
    dfs(m, 0, m);
  }
  return 0;
}
