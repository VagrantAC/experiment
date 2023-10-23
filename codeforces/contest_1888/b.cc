#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int t;
  string s;
  map<char, int> mp;
  cin >> t;
  while (t--) {
    mp.clear();
    int n, k;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      mp[s[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += (mp['a' + i] % 2);
    }
    if (ans) {
      ans --;
    }
    // std::cout << ans << endl;
    if (ans > k) {
      std::cout << "No" << std::endl;
    } else {
      std::cout << "Yes" << std::endl;
    }
  }
  return 0;
}
