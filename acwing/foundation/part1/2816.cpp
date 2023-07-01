#include <iostream>

const int MAXN = 1e5 + 55;
int a[MAXN], b[MAXN];

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  int l = 0;
  for (int i = 0; i < m; i++) {
    if (l == n) {
      break;
    }
    if (a[l] == b[i]) {
      l++;
    }
  }

  std::cout << (l == n ? "Yes" : "No") << std::endl;
  return 0;
}
