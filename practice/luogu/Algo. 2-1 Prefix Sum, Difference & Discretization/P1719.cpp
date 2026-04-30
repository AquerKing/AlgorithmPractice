#include <algorithm>
#include <array>
#include <climits>
#include <iostream>

#define MAX_LEN 120

std::array<std::array<short, MAX_LEN + 1>, MAX_LEN + 1> a;
std::array<int, MAX_LEN + 1> col_sum;
int n;

int kanade() {
    int res = INT_MIN, temp_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (temp_sum < 0) {
            temp_sum = col_sum[i];
        } else {
            temp_sum += col_sum[i];
        }

        res = std::max(res, temp_sum);
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    int ans = INT_MIN;
    for (int top = 0; top < n; ++top) {
        col_sum.fill(0);

        for (int bottom = top; bottom < n; ++bottom) {
            for (int column = 0; column < n; ++column) {
                col_sum[column] += a[bottom][column];
            }
            
            ans = std::max(ans, kanade());
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// Brute Force:
// Enumerate every possible matrix
//
// #include <array>
// #include <climits>
// #include <iostream>

// #define MAX_LEN 120

// std::array<std::array<short, MAX_LEN + 1>, MAX_LEN + 1> pre_sum = {};

// inline int calc_rect(int top, int left, int bottom, int right) {
//     return pre_sum[bottom][right] - pre_sum[bottom][left - 1] -
//            pre_sum[top - 1][right] + pre_sum[top - 1][left - 1];
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cout.tie(nullptr);

//     int n;
//     std::cin >> n;
//     for (int i = 0, t; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             std::cin >> t;
//             pre_sum[i + 1][j + 1] =
//                 pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j] + t;
//         }
//     }

//     int ans = INT_MIN;
//     for (int top = 1; top <= n; ++top) {
//         for (int left = 1; left <= n; ++left) {
//             for (int bottom = top; bottom <= n; ++bottom) {
//                 for (int right = left; right <= n; ++right) {
//                     ans = std::max(ans, calc_rect(top, left, bottom, right));
//                 }
//             }
//         }
//     }

//     std::cout << ans << std::endl;

//     return 0;
// }