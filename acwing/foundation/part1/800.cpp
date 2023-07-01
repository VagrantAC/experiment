#include <iostream>

const int MAXN = 1e5 + 55;
int a[MAXN], b[MAXN];

int main() {
  int n, m, x;
  std::cin >> n >> m >> x;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  int r = m - 1;
  for (int i = 0; i < n; i++) {
    while (r >= 0 && a[i] + b[r] > x) {
      r--;
    }

    if (r >= 0 && a[i] + b[r] == x) {
      std::cout << i << " " << r << std::endl;
      return 0;
    }
  }
  return 0;
}
