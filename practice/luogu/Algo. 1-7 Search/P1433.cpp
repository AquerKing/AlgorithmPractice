// Unsolved: 90 pts
// TODO: Cut branches
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>

#define MAX_LEN 15

std::array<std::array<double, MAX_LEN + 1>, MAX_LEN + 1> distances = {};

struct Position {
    double x = 0.0, y = 0.0;

    double distance_from(const Position &other) const {
        return std::sqrt((x - other.x) * (x - other.x) +
                         (y - other.y) * (y - other.y));
    }
};

int n = 0;
std::array<Position, MAX_LEN + 1> cheeses = {};
std::array<bool, MAX_LEN + 1> eaten = {};
double ans = 1e10;

inline double get_distance(int a, int b) {
    if (distances[a][b] == 0.0) {
        distances[a][b] = distances[b][a] =
            cheeses[a].distance_from(cheeses[b]);
    }
    return distances[a][b];
}

void dfs(int last, int ate, double moved) {
    if (moved > ans) {
        return;
    }

    if (ate >= n) {
        ans = moved;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (eaten[i]) {
            continue;
        }

        eaten[i] = true;
        dfs(i, ate + 1, moved + get_distance(i, last));
        eaten[i] = false;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    cheeses[0].x = 0.0;
    cheeses[0].y = 0.0;

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> cheeses[i].x >> cheeses[i].y;
    }

    dfs(0, 0, 0.0f);

    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;

    return 0;
}