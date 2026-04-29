#include <array>
#include <iostream>

#define MAX_LEN 100001

typedef unsigned int u32;
typedef unsigned long long u64;

std::array<u32, MAX_LEN> a;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    u32 n, x;
    std::cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    u64 total = 0;
    for (u32 i = 1, temp_sum, eaten; i < n; ++i) {
        temp_sum = a[i] + a[i - 1];
        eaten = temp_sum > x ? temp_sum - x : 0;
        total += eaten;
        a[i - 1] -= eaten > a[i] ? eaten - a[i] : 0;
        a[i] -= eaten > a[i] ? a[i] : eaten;
    }

    std::cout << total << std::endl;

    return 0;
}