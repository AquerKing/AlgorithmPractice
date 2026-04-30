#include <array>
#include <climits>
#include <iostream>
#include <utility>

#define MAX_LEN 5000000

std::array<int, MAX_LEN + 2> diff;

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n, p, first;

    std::cin >> n >> p;
    std::cin >> first;
    diff[0] = first;
    for (int i = 1, cur, last = first; i < n; ++i) {
        std::cin >> cur;
        diff[i] = cur - last;
        std::swap(cur, last);
    }

    for (int i = 0, x, y, z; i < p; ++i) {
        std::cin >> x >> y >> z;
        diff[x - 1] += z;
        diff[y] -= z;
    }

    int ans = INT_MAX, temp_sum = 0;
    for (int i = 0; i < n; ++i) {
        temp_sum += diff[i];
        ans = std::min(ans, temp_sum);
    }

    std::cout << ans << std::endl;

    return 0;
}