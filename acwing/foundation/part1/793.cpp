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
  bool sign = false;
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
    if (h.sign) {
      o << "-";
    }
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

  bool operator>(const HighPrecisionDigital &h) const {
    if (vecs.size() != h.vecs.size()) {
      return vecs.size() > h.vecs.size();
    }

    for (int i = vecs.size() - 1; i >= 0; i--) {
      if (vecs[i] != h.vecs[i]) {
        return vecs[i] > h.vecs[i];
      }
    }
    return true;
  }

  bool operator<(const HighPrecisionDigital &h) const { return h > *this; }

  HighPrecisionDigital clone() {
    HighPrecisionDigital h;
    h.vecs = std::vector<int>(vecs);
    h.sign = sign;
    return h;
  }

  HighPrecisionDigital operator+(HighPrecisionDigital &h) {
    HighPrecisionDigital sum = HighPrecisionDigital();
    long long ans = 0;
    for (int i = 0; i < vecs.size() || i < h.vecs.size(); i++) {
      ans +=
          (i < vecs.size() ? vecs[i] : 0) + (i < h.vecs.size() ? h.vecs[i] : 0);
      sum.vecs.push_back(ans % MODULUS);
      ans /= MODULUS;
    }
    if (ans > 0 || sum.vecs.size() == 0) {
      sum.vecs.push_back(ans);
    }
    return sum;
  }

  HighPrecisionDigital operator-(HighPrecisionDigital &h) {
    HighPrecisionDigital maxx = *this > h ? this->clone() : h.clone();
    HighPrecisionDigital &minn = *this < h ? *this : h;

    for (int i = 0; i < minn.vecs.size(); i++) {
      maxx.vecs[i] -= minn.vecs[i];
    }

    bool carry = false;
    for (auto &num : maxx.vecs) {
      if (carry) {
        num--;
        carry = false;
      }
      if (num < 0) {
        carry = true;
        num += MODULUS;
      }
    }
    while (maxx.vecs.size() && maxx.vecs[maxx.vecs.size() - 1] == 0) {
      maxx.vecs.pop_back();
    }
    if (*this < h && maxx.vecs.size() != 0) {
      maxx.sign = true;
    }
    return maxx;
  }

  HighPrecisionDigital operator*(int num) {
    for (int i = 0; i < this->vecs.size(); i++) {
      this->vecs[i] *= num;
    }
    int ans = 0;
    for (int i = 0; i < this->vecs.size(); i++) {
      this->vecs[i] += ans;
      ans = this->vecs[i] / this->MODULUS;
      this->vecs[i] %= this->MODULUS;
    }

    while (ans) {
      this->vecs.push_back(ans % this->MODULUS);
      ans /= this->MODULUS;
    }
    while (this->vecs.size() && !this->vecs[this->vecs.size() - 1]) {
      this->vecs.pop_back();
    }
    return *this;
  }
};

int main() {
  HighPrecisionDigital a;
  int b;
  std::cin >> a >> b;
  std::cout << a * b << std::endl;
}