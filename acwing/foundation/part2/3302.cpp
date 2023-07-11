#include <iostream>
#include <vector>

using namespace std;

int solve(string &str, int l, int r) {
  vector<int> num;
  vector<char> oper;
  vector<int> simnum;
  vector<char> simoper;

  for (int i = l; i < r; i++) {
    if (str[i] == '+' || str[i] == '-') {
      int res = num[0];
      for (int j = 0; j < oper.size(); j++) {
        if (oper[j] == '*') {
          res *= num[j + 1];
        } else {
          res /= num[j + 1];
        }
      }
      simnum.push_back(res);
      simoper.push_back(str[i]);
      oper.clear();
      num.clear();
    } else if (str[i] == '*' || str[i] == '/') {
      oper.push_back(str[i]);
    } else if (str[i] == '(') {
      int expressionl = i;
      int ans = 1;
      for (i++;; i++) {
        if (str[i] == '(') {
          ans++;
        } else if (str[i] == ')') {
          ans--;
        }
        if (ans == 0) {
          num.push_back(solve(str, expressionl + 1, i));
          break;
        }
      }
    } else {
      int res = 0;
      for (; i < r; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
          res = res * 10 + str[i] - '0';
        } else {
          i--;
          break;
        }
      }
      num.push_back(res);
    }
  }

  int res = num[0];
  for (int j = 0; j < oper.size(); j++) {
    if (oper[j] == '*') {
      res *= num[j + 1];
    } else {
      res /= num[j + 1];
    }
  }
  simnum.push_back(res);
  int sum = simnum[0];
  for (int i = 0; i < simoper.size(); i++) {
    if (simoper[i] == '+') {
      sum += simnum[i + 1];
    } else {
      sum -= simnum[i + 1];
    }
  }
  return sum;
}

int main() {
  string str;
  cin >> str;
  cout << solve(str, 0, str.length()) << endl;
  return 0;
}
