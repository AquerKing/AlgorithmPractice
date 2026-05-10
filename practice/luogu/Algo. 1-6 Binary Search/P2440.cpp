#include <array>
#include <iostream>

#define MAX_LEN 100000

int n = 0, k = 0;
std::array<int, MAX_LEN + 1> logs = {};

bool check(int l) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += logs[i] / l;
    }
    return total >= k;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    long long total_len = 0;
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> logs[i];
        total_len += logs[i];
    }

    int left = 1, right = total_len / k, middle = 0, ans = 0;
    while (left <= right) {
        middle = left + (right - left) / 2;

        if (check(middle)) {
            ans = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}