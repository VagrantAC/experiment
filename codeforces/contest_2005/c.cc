#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e3+55;

const string temp = "narek";
const int INF = 0x3f3f3f;
int dp[maxn][5];
bool checkCH(char ch) {
    for (int i = 0; i < temp.length(); ++ i) {
        if (temp[i] == ch) {
            return true;
        }
    }
    return false;
}

std::pair<int, int> val(int j, string& str) {
    int score = 0;
    for (int i = 0; i < str.length(); ++ i) {
        if (!checkCH(str[i])) continue;
        if (str[i] == temp[j]) {
            j ++;
        } else {
            score --;
        }
        if (j == temp.length()) {
            j = 0;
            score += 5;
        }
    }
    return make_pair(j, score);
}

int main() {
    int t;
    string str;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; ++ i) {
            for (int j = 0; j < temp.length(); ++ j) {
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++ i) {
            cin >> str;
            for (int j = 0; j < temp.length(); ++ j) {
                dp[i][j] = dp[i-1][j];
            }
            for (int j = 0; j < temp.length(); ++ j) {
                if (dp[i-1][j] == -INF) continue;
                std::pair<int, int> res = val(j, str);
                int k = res.first;
                int score = res.second + dp[i-1][j];
                dp[i][k] = max(dp[i][k], score);
            }
        }

        int maxx = 0;
        for (int i = 0; i < temp.length(); ++ i) {
            maxx = max(dp[n][i] - i, maxx);
        }
        cout << maxx << endl;
    }
    return 0;
}