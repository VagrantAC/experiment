#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 55;
struct Node {
  int l, r;
  int sum;
};
Node tree[MAXN << 2];

int Build(int step, int l, int r, string &str) {
  int mid = (l + r) >> 1;
  tree[step].l = l;
  tree[step].r = r;
  tree[step].sum = 0;
  if (l == r) {
    tree[step].sum = str[l - 1] - '0';
  } else {
    tree[step].sum =
        Build(step * 2, l, mid, str) + Build(step * 2 + 1, mid + 1, r, str);
  }
  return tree[step].sum;
}

int Query(int step, int ql, int qr) {
  if (tree[step].l > qr || tree[step].r < ql) {
    return 0;
  }

  if (tree[step].l >= ql && tree[step].r <= qr) {
    return tree[step].sum;
  }
  return Query(step * 2, ql, qr) + Query(step * 2 + 1, ql, qr);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string str;
    cin >> n >> m;
    cin >> str;
    Build(1, 1, n, str);
    map<pair<int, int>, bool> mp;
    int cnt = 0;
    bool flag = false;
    while (m--) {
      int l, r;
      cin >> l >> r;
      int ql = l, qr = r;
      while (ql < qr) {
        int mid = (ql + qr + 1) >> 1;
        if (Query(1, mid, r) == r - mid + 1) {
          qr = mid - 1;
        } else {
          ql = mid;
        }
      }
      r = qr;
      // cout << l << " " << r << endl;
      int sum = Query(1, l, r);
      if (sum && sum != r - l + 1) {
        if (!mp[make_pair(r - sum + 1, r)]) {
          cnt++;
        }
        mp[make_pair(r - sum + 1, r)] = true;
      } else {
        flag = true;
      }
    }
    if (flag) {
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
