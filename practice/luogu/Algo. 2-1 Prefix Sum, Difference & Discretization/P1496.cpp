#include <algorithm>
#include <array>
#include <iostream>

#define MAX_LEN 20000

struct Range {
    int l, r;

    bool operator<(const Range &other) const { return l < other.l; }

    bool operator==(const Range &other) const {
        return l == other.l && r == other.r;
    }
};

int n;
std::array<Range, MAX_LEN> ranges;

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> ranges[i].l >> ranges[i].r;
    }

    std::sort(ranges.begin(), ranges.begin() + n);

    auto end = std::unique(ranges.begin(), ranges.begin() + n);

    long long ans = 0;
    for (auto it = ranges.begin(), last = static_cast<Range *>(nullptr);
         it != end; ++it) {
        if (last != nullptr) {
            if (last->r <= it->l) {
                ans += it->r - it->l;
                last = it;
            } else if (it->l < last->r && last->r < it->r) {
                ans += it->r - last->r;
                last = it;
            }
        } else if (last == nullptr) {
            ans += it->r - it->l;
            last = it;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}