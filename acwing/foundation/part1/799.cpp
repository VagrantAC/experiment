#include <algorithm>
#include <iostream>
#include <unordered_map>

const int MAXN = 1e5 + 55;
int a[MAXN];

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, bool> mp;
  int l = 0, maxx = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    while (mp[a[i]]) {
      mp[a[l]] = false;
      l++;
    }
    mp[a[i]] = true;
    maxx = std::max(maxx, i - l + 1);
  }

  std::cout << maxx << std::endl;
  return 0;
}
