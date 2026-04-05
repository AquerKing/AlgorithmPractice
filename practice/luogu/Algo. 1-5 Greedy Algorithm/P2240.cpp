#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>

#define MAX_SIZE 101

struct CoinPile {
    int m, v;
    float vpu;

    void calculate() { vpu = 1.0f * v / m; }

    static bool compare_value(const CoinPile& a, const CoinPile& b) {
        return a.v > b.v;
    }

    static bool compare_vpu(const CoinPile& a, const CoinPile& b) {
        return a.vpu > b.vpu;
    }
};

std::array<CoinPile, MAX_SIZE> piles;

int main() {
    std::cout.sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n, t;
    float taken = 0.0f;

    std::cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        std::cin >> piles[i].m >> piles[i].v;
        piles[i].calculate();
    }

    std::sort(piles.begin(), piles.begin() + n, &CoinPile::compare_vpu);

    for (int i = 0; i < n; ++i) {
        if (t >= piles[i].m) {
            t -= piles[i].m;
            taken += piles[i].v;
        } else if (t > 0) {
            taken += t * piles[i].vpu;
            t = 0;
        } else {
            break;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << taken << std::endl;

    return 0;
}
