#include <iostream>

using namespace std;

const int maxn = 8;
string str[maxn];
bool vis[maxn] = {false};

int dfs(int step, int n, int k) {
  if (k == 0) {
    return 1;
  }
  if (n == step) {
    return 0;
  }
  int res = dfs(step + 1, n, k);
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && str[step][i] == '#') {
      vis[i] = true;
      res += dfs(step + 1, n, k - 1);
      vis[i] = false;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    if (n == -1 && k == -1) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      cin >> str[i];
    }
    cout << dfs(0, n, k) << endl;
  }
  return 0;
}
