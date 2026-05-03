#include <array>
#include <iostream>

#define MAX_LEN 1000000

typedef unsigned int uint;

struct Order {
    uint d, s, t;
};

int n, m;
std::array<Order, MAX_LEN + 1> orders = {};
std::array<long long, MAX_LEN + 1> rooms = {};
std::array<long long, MAX_LEN + 2> diff = {};

bool is_order_practical(int p) {
    diff.fill(0);

    for (int i = 1; i <= p; ++i) {
        diff[orders[i].s] += orders[i].d;
        diff[orders[i].t + 1] -= orders[i].d;
    }

    for (int i = 1; i <= n; ++i) {
        diff[i + 1] += diff[i];
        if (diff[i] > rooms[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> rooms[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> orders[i].d >> orders[i].s >> orders[i].t;
    }

    int left = 1, right = m, middle = (left + right) / 2;
    while (left < right) {
        if (!is_order_practical(middle)) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }

        middle = (left + right) / 2;
    }

    bool is_practical = is_order_practical(middle);
    if (is_practical && middle == m) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << -1 << std::endl;
        if (is_practical) {
            std::cout << middle + 1 << std::endl;
        } else {
            std::cout << middle << std::endl;
        }
    }

    return 0;
}