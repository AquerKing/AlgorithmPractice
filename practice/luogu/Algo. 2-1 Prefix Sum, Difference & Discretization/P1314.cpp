#include <array>
#include <cstdlib>
#include <iostream>

#define MAX_SCALE 200000

struct Ore {
    int w, v;
};

struct Range {
    int l, r;
};

long long n, m, s;
std::array<Ore, MAX_SCALE + 1> ores;
std::array<Range, MAX_SCALE + 1> ranges;
std::array<int, MAX_SCALE + 1> presum_cnt;
std::array<long long, MAX_SCALE + 1> presum_val;

inline int indicator_func(int j, int W) { return ores[j].w >= W ? 1 : 0; }

long long calc_index(int W) {
    presum_cnt[0] = 0;
    presum_val[0] = 0;

    for (int i = 1; i <= n; ++i) {
        presum_cnt[i] = presum_cnt[i - 1] + indicator_func(i, W);
        presum_val[i] = presum_val[i - 1] + indicator_func(i, W) * ores[i].v;
    }

    long long y = 0;

    for (int i = 1; i <= m; ++i) {
        y += (presum_cnt[ranges[i].r] - presum_cnt[ranges[i].l - 1]) *
             (presum_val[ranges[i].r] - presum_val[ranges[i].l - 1]);
    }

    return y;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int left = 1, right = 0, middle;
    long long ans = LONG_LONG_MAX, temp_index;

    std::cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) {
        std::cin >> ores[i].w >> ores[i].v;
        right = std::max(right, ores[i].w);
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> ranges[i].l >> ranges[i].r;
    }

    while (left <= right) {
        middle = left + (right - left) / 2;
        temp_index = calc_index(middle);

        ans = std::min(ans, std::abs(temp_index - s));

        if (ans == 0) {
            break;
        }

        if (temp_index < s) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}