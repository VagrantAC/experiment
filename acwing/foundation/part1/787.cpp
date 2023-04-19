#include <vector>
#include <iostream>
#include <algorithm>

void merge_sort(std::vector<int>& vecs, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(vecs, l, mid);
    merge_sort(vecs, mid+1, r);
    int i = l;
    int j = mid + 1;
    std::vector<int> v;
    while (i <= mid && j <= r) {
        if (vecs[i] < vecs[j]) {
            v.push_back(vecs[i]);
            i++;
        } else {
            v.push_back(vecs[j]);
            j++;
        }
    }

    while (i <= mid) {
        v.push_back(vecs[i++]);
    }
    while (j <= r) {
        v.push_back(vecs[j++]);
    }

    for (int i = 0; i < v.size(); i ++) {
        vecs[i+l] = v[i];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vecs(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> vecs[i];
    }
    merge_sort(vecs, 0, n-1);
    for (auto pos: vecs) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    return 0;
}