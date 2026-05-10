#include <array>
#include <iostream>

#define MAX_LEN 100000

int l = 0, n = 0, k = 0;
std::array<int, MAX_LEN + 1> road_signs = {};

int calc(int x) {
    int total = 0;
    for (int i = 2; i <= n; ++i) {
        if (road_signs[i] - road_signs[i - 1] <= x) {
            continue;
        }

        int distance = road_signs[i] - road_signs[i - 1];
        total += distance / x + (distance % x == 0 ? 0 : 1) - 1;
    }

    return total;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> l >> n >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> road_signs[i];
    }

    int left = 1, right = l, middle = 0, ans = l, temp = l;
    while (left <= right) {
        middle = left + (right - left) / 2;

        if (calc(middle) <= k) {
            ans = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}