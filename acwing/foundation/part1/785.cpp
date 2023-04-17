#include <iostream>

const int maxn = 1e5+55;
int nums[maxn];

void merge_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = nums[(l + r) >> 1];
    int i = l-1;
    int j = r+1;
    while (i < j) {
        while (nums[++i] < mid);
        while (nums[--j] > mid);
        if (i < j) {
            std::swap(nums[i], nums[j]);
        }
    }
    std::cout << i << " " << j << std::endl;
    merge_sort(l, j);
    merge_sort(j+1, r);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i ++) {
        std::cin >> nums[i];
    }

    merge_sort(0, n-1);
    for (int i = 0; i < n; i ++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}