#include <array>
#include <iostream>

#define MAX_LEN 1000

std::array<std::array<int, MAX_LEN + 2>, MAX_LEN + 2> diff = {};

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0, x1, x2, y1, y2; i < m; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1] += 1;
        diff[x1][y2 + 1] -= 1;
        diff[x2 + 1][y1] -= 1;
        diff[x2 + 1][y2 + 1] += 1;
    }

    for (int i = 1; i <= n; ++i) {
        diff[i][1] += diff[i][0] + diff[i - 1][1] - diff[i - 1][0];
        std::cout << diff[i][1];
        for (int j = 2; j <= n; ++j) {
            diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
            std::cout << ' ' << diff[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}