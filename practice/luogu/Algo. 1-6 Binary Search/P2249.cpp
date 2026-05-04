#include <array>
#include <iostream>

#define MAX_LEN 1000000
#define MAX_QUERY_COUNT 100000

struct Number {
    int v, s;

    bool operator<(const Number &other) const { return v < other.v; }
};

int final_count = 0;
std::array<Number, MAX_LEN + 1> nums;
std::array<int, MAX_QUERY_COUNT + 1> queries;

int binary_search(int num) {
    int left = 1, right = final_count, middle = 0, final_index = 0;
    while (left <= right) {
        middle = (left + right) / 2;

        if (num <= nums[middle].v) {
            final_index = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    if (nums[final_index].v == num) {
        return nums[final_index].s;
    } else {
        return -1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1, t, last = -1; i <= n; ++i) {
        std::cin >> t;
        if (t != last) {
            nums[++final_count] = {t, i};
            last = t;
        }
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> queries[i];
    }

    std::cout << binary_search(queries[1]);
    for (int i = 2; i <= m; ++i) {
        std::cout << ' ' << binary_search(queries[i]);
    }
    std::cout << std::endl;

    return 0;
}