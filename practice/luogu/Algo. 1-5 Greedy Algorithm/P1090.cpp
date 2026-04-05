#include <iostream>
#include <queue>
#include <vector>

typedef unsigned int u32;
typedef unsigned long long u64;

struct Comparator {
    bool operator()(u32 a, u32 b) { return a > b; };
};

int main() {
    std::cout.sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::priority_queue<u32, std::vector<u32>, Comparator> pile;
    int n;

    std::cin >> n;
    for (int i = 0, t; i < n; ++i) {
        std::cin >> t;
        pile.push(t);
    }

    u64 total = 0;
    while (pile.size() > 1) {
        const u32 first = pile.top();
        pile.pop();
        const u32 second = pile.top();
        pile.pop();
        const u32 merged = first + second;
        pile.push(merged);
        total += merged;
    }

    std::cout << total << std::endl;

    return 0;
}
