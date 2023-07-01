#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 55;
ll nums[MAXN];
int x[MAXN], c[MAXN], l[MAXN], r[MAXN];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> c[i];
    vec.push_back(x[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    vec.push_back(l[i]);
    vec.push_back(r[i]);
  }
  sort(vec.begin(), vec.end());

  map<int, int> idx;
  int cnt = 0;
  for (auto v : vec) {
    if (idx.count(v)) {
      continue;
    }
    idx[v] = cnt++;
  }

  for (int i = 0; i <= cnt; i++) {
    nums[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    nums[idx[x[i]]] += c[i];
  }
  for (int i = 1; i <= cnt; i++) {
    nums[i] += nums[i - 1];
  }

  for (int i = 0; i < m; i++) {
    cout << nums[idx[r[i]]] - nums[idx[l[i]]] << endl;
  }
  return 0;
}
