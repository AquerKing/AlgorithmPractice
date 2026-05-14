#include <algorithm>
#include <array>
#include <iostream>

#define MAX_LEN 200000

int n = 0, c = 0;
std::array<long long, MAX_LEN + 1> nums = {};

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.begin() + n);

    long long ans = 0;
    for (int i = 0, count = 0; i < n; ++i) {
        if (i == n - 1) {
            break;
        }

        count = 1;
        while (i < n && nums[i + 1] == nums[i]) {
            ++i;
            ++count;
        }

        long long *l = std::lower_bound(nums.begin() + i + 1, nums.begin() + n,
                                        1ll * nums[i] + c);
        long long *r = std::upper_bound(nums.begin() + i + 1, nums.begin() + n,
                                        1ll * nums[i] + c);
        ans += (r - l) * count;
    }

    std::cout << ans << std::endl;

    return 0;
}

// Solved by unordered_map
//
// #include <iostream>
// #include <unordered_map>
// #include <utility>

// int n, c;
// std::unordered_map<int, int> counter = {};

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cout.tie(nullptr);

//     std::cin >> n >> c;
//     for (int i = 0, t = 0; i < n; ++i) {
//         std::cin >> t;
//         if (counter.count(t) > 0) {
//             ++counter[t];
//         } else {
//             counter[t] = 1;
//         }
//     }

//     long long ans = 0;
//     for (std::pair<const int, int> &p : counter) {
//         if (counter.count(p.first) && counter.count(p.first + c)) {
//             ans += 1ll * counter[p.first] * counter[p.first + c];
//         }
//     }

//     std::cout << ans << std::endl;

//     return 0;
// }