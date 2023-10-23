#include <algorithm>
#include <iostream>
#include <map>

int main() {
  int t;
  std::map<int, int> mp;
  std::cin >> t;
  while (t--) {
    mp.clear();
    int n, k, a;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
      std::cin >> a;
      a %= k;
      mp[a]++;
    }

    if (mp[0]) {
      std::cout << 0 << std::endl;
      continue;
    }

    if (k != 4) {
      for (int i = k - 1; i >= 0; i--) {
        if (mp[i]) {
          std::cout << k - i << std::endl;
          break;
        }
      }
      continue;
    }
    if (mp[2] > 1) {
      std::cout << 0 << std::endl;
    } else if (mp[3]) {
      std::cout << 1 << std::endl;
    } else if (mp[2] && mp[1]) {
      std::cout << 1 << std::endl;
    } else if (mp[1] > 1) {
      std::cout << 2 << std::endl;
    } else {
      for (int i = k - 1; i >= 0; i--) {
        if (mp[i]) {
          std::cout << k - i << std::endl;
          break;
        }
      }
    }
  }
  return 0;
}
