#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HighPrecisionDigital {
private:
  int reverse_int(std::string str) {
    int ans = 0;
    for (auto ch : str) {
      ans = ans * 10 + ch - '0';
    }
    return ans;
  }
  std::vector<int> vecs;
  static const int POWER = 4;
  static const int MODULUS = 10000;
  void constructor(std::string s) {
    std::reverse(s.begin(), s.end());
    std::string str = "";
    for (int i = 0; i < s.length(); i++) {
      str += s[i];
      if (str.length() == POWER) {
        std::reverse(str.begin(), str.end());
        vecs.push_back(reverse_int(str));
        str = "";
      }
    }
    if (str.length() != 0) {
      std::reverse(str.begin(), str.end());
      vecs.push_back(reverse_int(str));
    }
  }

public:
  HighPrecisionDigital(std::string s) { constructor(s); }
  HighPrecisionDigital() {}

  friend std::istream &operator>>(std::istream &o, HighPrecisionDigital &h) {
    std::string s;
    o >> s;
    h.constructor(s);
    return o;
  }

  friend std::ostream &operator<<(std::ostream &o,
                                  const HighPrecisionDigital &h) {
    if (h.vecs.size() == 0) {
      o << 0;
      return o;
    }
    o << h.vecs[h.vecs.size() - 1];
    for (int i = h.vecs.size() - 2; i >= 0; --i) {
      int modulus = MODULUS / 10;
      while (h.vecs[i] < modulus) {
        modulus /= 10;
        o << 0;
      }
      if (h.vecs[i]) {
        o << h.vecs[i];
      }
    }
    return o;
  }

  HighPrecisionDigital operator+(HighPrecisionDigital &h) {
    HighPrecisionDigital sum = HighPrecisionDigital();
    long long ans = 0;
    for (int i = 0; i < vecs.size() || i < h.vecs.size(); i++) {
      ans +=
          (i < vecs.size() ? vecs[i] : 0) + (i < h.vecs.size() ? h.vecs[i] : 0);
      sum.vecs.push_back(ans % MODULUS);
      // std::cout << ans << " " << ans/MODULUS <<  std::endl;
      ans /= MODULUS;
    }
    if (ans > 0 || sum.vecs.size() == 0) {
      sum.vecs.push_back(ans);
    }
    return sum;
  }
};

int main() {
  HighPrecisionDigital a, b;
  std::cin >> a >> b;
  // std::cout << a << " " << b << std::endl;
  std::cout << a + b << std::endl;
}