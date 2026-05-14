#include <array>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <queue>

#define MAX_LEN 50000

int l = 0, n = 0, m = 0;
std::array<int, MAX_LEN + 2> stones = {INT_MAX};
std::priority_queue<int> q;

int get_removed(long long x) {
    int res = 0, last = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (stones[i] - last < x) {
            ++res;
        } else {
            last = stones[i];
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> l >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> stones[i];
    }
    stones[0] = 0;
    stones[n + 1] = l;

    long long left = 1, right = l, middle = 0, removed = 0, ans = INT_MAX;
    while (left <= right) {
        middle = 1ll * left + (right - left) / 2;
        removed = get_removed(middle);

        if (removed <= m) {
            ans = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}