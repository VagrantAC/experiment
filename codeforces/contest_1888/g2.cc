#include <algorithm>
#include <iostream>

const int maxn = 1e5 + 55;
int a[maxn], b[maxn];

bool check_1(int m, int pos, int n) {
  bool flag = false;
  for (int j = n - pos, i = 0; j < n; j++) {
    if (!flag && m < b[j]) {
      flag = true;
      continue;
    }
    if (i < n - 1 && a[i] < b[j]) {
      i++;
      continue;
    }
    return false;
  }
  return true;
}

// 返回结果为保留m的能产生的最大值
int check_2(int m, int n) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check_1(m, mid, n)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
      std::cin >> a[i];
    }
    std::sort(a, a + n - 1);
    for (int i = 0; i < n; i++) {
      std::cin >> b[i];
    }
    std::sort(b, b + n);
    int sum = check_2(1, n);
    int l = 1, r = m;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (check_2(mid, n) == sum) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }

    sum = n - sum;
    std::cout << 1ll * l * sum + 1ll * (m - l) * (sum + 1) << std::endl;
  }
  return 0;
}
