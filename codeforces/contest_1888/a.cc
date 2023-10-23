#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  int t;
  std::string str;
  std::cin >> t;
  while (t--) {
    std::cin >> str;
    int res = str.length();
    for (int i = 0; i < str.length(); i++) {
      int a = i == 0 ? '1' : (str[i - 1] == '0' ? str[i - 1] + 10 : str[i - 1]);
      int b = str[i] == '0' ? str[i] + 10 : str[i];
      res += abs(a - b);
    }
    std::cout << res << std::endl;
  }
  return 0;
}
