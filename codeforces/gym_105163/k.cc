#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> num, opt;
char opts[3] = {'+', '-', '*'};
bool vis[4] = {false};
int a[4];
std::unordered_set<int> set;

int dfs() {
    if (opt.size() == 3) {
        std::queue<int> que, opr;
        int last = num[0];
        for (int i = 0; i < 3; ++ i) {
            if (opt[i] == '*') {
                last *= num[i+1];
            } else {
                que.push(last);
                last = num[i+1];
                opr.push(opt[i]);
            }
        }
        que.push(last);
        last = que.front();
        que.pop();
        while (!opr.empty()) {
            if (opr.front() == '-') {
                last -= que.front();
            } else {
                last += que.front();
            }
            que.pop();
            opr.pop();
        }
        set.insert(last);
        return last == 24;
    }
    int res = 0;
    for (int i = 0; i < 4; ++ i) {
        if (!vis[i]) {
            vis[i] = true;
            num.push_back(a[i]);
            if (num.size() != 1) {
                for (int j = 0; j < 3; ++ j) {
                    opt.push_back(opts[j]);
                    res += dfs();
                    opt.pop_back();
                }
            } else {
                res += dfs();
            }
            vis[i] = false;
            num.pop_back();
        }
    }
    return res;
}

int main() {
    for (int i = 0; i < 4; ++ i) {
        std::cin >> a[i];
    }
    dfs();
    std::cout << set.size() << std::endl;
    return 0;
}