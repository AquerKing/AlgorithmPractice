#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <queue>

#define MAX_LEN 10000001
#define MAX_RANGE 100000

typedef unsigned int u32;
typedef unsigned long long u64;

struct Comparator {
    bool operator()(u64 a, u64 b) { return a > b; };
};

std::array<u64, MAX_LEN> piles;
std::array<u32, MAX_RANGE + 1> counts;

inline u64 pick_out_min_from_two_queues(std::queue<u64> &q1,
                                        std::queue<u64> &q2) {
    u64 res;

    if (q1.empty()) {
        res = q2.front();
        q2.pop();
    } else if (q2.empty()) {
        res = q1.front();
        q1.pop();
    } else if (q1.front() < q2.front()) {
        res = q1.front();
        q1.pop();
    } else {
        res = q2.front();
        q2.pop();
    }

    return res;
}

inline bool is_number(char ch) { return ch >= '0' && ch <= '9'; }

u64 read() {
    char ch = '\0';
    while (!is_number(ch)) {
        ch = getchar();
    }
    u64 res = 0;
    while (is_number(ch)) {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}

int main() {
    std::queue<u64> raw, intermediate;
    int n;

    n = read();
    for (u32 i = 0, t; i < n; ++i) {
        t = read();
        ++counts[t];
    }

    for (u32 i = 1; i <= MAX_RANGE; ++i) {
        if (counts[i]) {
            for (u32 j = counts[i]; j > 0; --j) {
                raw.push(i);
            }
        }
    }

    u64 total = 0;
    u64 first, second, merged;
    while (raw.size() + intermediate.size() >= 2) {
        first = pick_out_min_from_two_queues(raw, intermediate);
        second = pick_out_min_from_two_queues(raw, intermediate);
        merged = first + second;
        total += merged;
        intermediate.push(merged);
    }

    std::cout << total << std::endl;

    return 0;
}
