#include <vector>
#include <iostream>
#include <algorithm>

int quick_find_k(std::vector<int>& vecs, int l, int r, int k) {
    if (l == r) {
        return vecs[l];
    }
    int i = l-1;
    int j = r+1;
    int mid = (vecs[(l+r) >> 1]);
    while (i < j) {
        while (vecs[++i] < mid);
        while (vecs[--j] > mid);
        if (i < j) {
            std::swap(vecs[i], vecs[j]);
        }
    }
    if (j < k) {
        return quick_find_k(vecs, j+1, r, k);
    }
    return quick_find_k(vecs, l, j, k);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> vecs(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> vecs[i];
    }
    std::cout << quick_find_k(vecs, 0, n-1, k-1) << std::endl;
    return 0;
}