#pragma GCC optimize(2)
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 10;
string str[maxn];
vector<char> vec;
char step[4] = {'A', 'C', 'G', 'T'};
int p[maxn];

inline bool push(int n, char ch) {
    bool flag = false;
    for (int i = 0; i < n; ++ i) {
        if (p[i] != str[i].length() && str[i][p[i]] == ch) {
            p[i] ++;
            flag = true;
        }
    }
    if (!flag) {
        return false;
    }
    vec.push_back(ch);
    return true;
}

inline int check(int n) {
    int maxx = 0;
    for (int i = 0; i < n; ++ i) {
        maxx = max(maxx, int(str[i].length() - p[i]));
    }
    return maxx;    
}

bool dfs(int n, int deep) {
    int c = check(n);
    if (c == 0) {
        return true;
    }
    if (c > deep) {
        return false;
    }
    if (deep == 0) {
        return false;
    }
    int tmp[maxn];
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < n; ++ j) {
            tmp[j] = p[j];
        }
        if (push(n, step[i])) {
            if (dfs(n, deep-1)) {
                return true;
            }
            vec.pop_back();
        }
        for (int j = 0; j < n; ++ j) {
            p[j] = tmp[j];
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++ i) {
            cin >> str[i];
        }
        for (int i = 0; ; ++ i) {
            vec.clear();
            for (int j = 0; j < n; ++ j) {
                p[j] = 0;
            }
            if (dfs(n, i)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}