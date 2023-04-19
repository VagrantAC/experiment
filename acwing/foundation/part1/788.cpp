#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

ll merge_sort(std::vector<int>& vecs, int l, int r) {
    if (l >=  r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    ll count = 0;
    count += merge_sort(vecs, l, mid);
    count += merge_sort(vecs, mid+1, r);
    
    
    std::vector<int> v;
    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (vecs[i] <= vecs[j]) {
            count += abs(v.size() - i + l);
            v.push_back(vecs[i++]);
        } else {
            count += abs(v.size() - j + l);
            v.push_back(vecs[j++]);
        }
    }

    while (i <= mid) {
        count += abs(v.size() - i + l);
        v.push_back(vecs[i++]);
    }
    while (j <= r) {
        count += abs(v.size() - j + l);
        v.push_back(vecs[j++]);
    }

    for (int i = 0; i < v.size(); i ++) {
        vecs[l+i] = v[i];
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vecs(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> vecs[i];
    }
    std::cout << merge_sort(vecs, 0, n-1) / 2 << std::endl;
    return 0;
}