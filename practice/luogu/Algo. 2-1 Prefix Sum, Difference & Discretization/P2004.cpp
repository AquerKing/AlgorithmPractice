#include <array>
#include <climits>
#include <iostream>

#define MAX_LEN 1000

std::array<std::array<short, MAX_LEN + 1>, MAX_LEN + 1> map = {};
std::array<int, MAX_LEN + 1> col_sum = {};
int n, m, c;

int kanade(int& col) {
    int res = INT_MIN, temp_sum = 0;
    for (int i = 1; i < c; ++i) {
        temp_sum += col_sum[i];
    }

    for (int i = c; i <= m; ++i) {
        temp_sum += col_sum[i] - col_sum[i - c];
        if (temp_sum > res) {
            res = temp_sum;
            col = i - c + 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i < c; ++i) {
        for (int j = 1; j <= m; ++j) {
            col_sum[j] += map[i][j];
        }
    }

    int ans = INT_MIN, temp, x = 1, y = 1, ty;
    for (int i = 1; i <= n - c + 1; ++i) {
        for (int j = 1; j <= m; ++j) {
            col_sum[j] += map[i + c - 1][j] - map[i - 1][j];
        }
        temp = kanade(ty);
        if (temp > ans) {
            ans = temp;
            x = i;
            y = ty;
        }
    }

    std::cout << x << ' ' << y << std::endl;

    return 0;
}