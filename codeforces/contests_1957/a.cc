#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t --) {
        unordered_map<int, int> mp;
        unordered_map<int, int> m;
        vector<int> vec;
        int n, a, cnt = 0, maxx = 0;
        cin >> n;
        for (int i = 0; i < n; ++ i) {
            cin >> a;
            if (mp[a] == 0) {
                vec.push_back(a);
            }
            mp[a] ++;
        }
        for (int i = 0; i < vec.size(); ++ i) {
            cnt += mp[vec[i]] / 3;
        }
        cout << cnt << endl;
    }
    return 0;
}