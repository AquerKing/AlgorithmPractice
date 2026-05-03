#include <algorithm>
#include <array>
#include <iostream>

#define MAX_LEN 100000

std::array<int, MAX_LEN + 2> diff = {};
std::array<unsigned int, MAX_LEN + 1> a = {};
std::array<unsigned int, MAX_LEN + 1> b = {};
std::array<unsigned int, MAX_LEN + 1> non_equal_constrains = {};
int n, m;

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n >> m;

    int last;
    std::cin >> last;
    for (int i = 1, t; i < m; ++i) {
        std::cin >> t;
        diff[std::min(t, last)] += 1;
        diff[std::max(t, last)] -= 1;
        last = t;
    }

    unsigned long long ans = 0;
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i] >> b[i] >> non_equal_constrains[i];
        diff[i] += diff[i - 1];
        ans += std::min(static_cast<unsigned long long>(diff[i]) * a[i],
                        non_equal_constrains[i] + static_cast<unsigned long long>(diff[i]) * b[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}