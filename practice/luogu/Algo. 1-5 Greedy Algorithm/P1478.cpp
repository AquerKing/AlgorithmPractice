#include <algorithm>
#include <array>
#include <iostream>

#define MAX_LEN 5001

std::array<int, MAX_LEN> y;

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n, s, a, b;
    int r = 0, max_height;

    std::cin >> n >> s;
    std::cin >> a >> b;

    max_height = a + b;
    for (int i = 0, p, q; i < n; ++i) {
        std::cin >> p >> q;
        if (p > max_height) {
            continue;
        }
        y[r++] = q;
    }

    std::sort(y.begin(), y.begin() + r);

    int res = 0, cost = 0;
    ;
    for (int i = 0; i < r; ++i) {
        cost += y[i];
        if (cost <= s) {
            ++res;
        } else {
            break;
        }
    }

    std::cout << res << std::endl;

    return 0;
}