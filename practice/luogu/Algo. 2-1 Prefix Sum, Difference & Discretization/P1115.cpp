#include <algorithm>
#include <array>
#include <climits>
#include <iostream>

#define MAX_LEN 200000

std::array<int, MAX_LEN + 1> pre_sum;

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n;
    int ans = INT_MIN, temp_sum = 0;

    std::cin >> n;
    for (int i = 0, t; i < n; ++i) {
        std::cin >> t;

        if (temp_sum < 0) {
            temp_sum = t;
        } else {
            temp_sum += t;
        }

        ans = std::max(ans, temp_sum);
    }

    std::cout << ans << std::endl;

    return 0;
}