#include <algorithm>
#include <array>
#include <iostream>

#define MAX_LEN 1000001

typedef unsigned int u32;

struct Competition {
    u32 start, end, duration;

    void calculate() { duration = end - start; };

    static bool Compare(const Competition& a, const Competition& b) {
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
};

std::array<Competition, MAX_LEN> competitions;

int main() {
    std::cout.sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> competitions[i].start >> competitions[i].end;
        competitions[i].calculate();
    }

    std::sort(competitions.begin(), competitions.begin() + n,
              &Competition::Compare);

    u32 total = 0, last_start = MAX_LEN;
    for (int i = n - 1; i >= 0; --i) {
        if (competitions[i].end <= last_start) {
            ++total;
            last_start = competitions[i].start;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
