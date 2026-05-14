#include <array>
#include <climits>
#include <iostream>

#define MAX_LEN 200

int n = 0, a = 0, b = 0;
std::array<int, MAX_LEN + 1> move = {};
std::array<int, MAX_LEN + 1> least_operation = {};
std::array<bool, MAX_LEN + 1> visited = {false};

void dfs(int current, int pressed, int visited_count) {
    if (pressed >= least_operation[current] || current < 1 || current > n ||
        visited[current]) {
        return;
    }

    least_operation[current] = pressed;

    visited[current] = true;
    dfs(current + move[current], pressed + 1, visited_count + 1);
    dfs(current - move[current], pressed + 1, visited_count + 1);
    visited[current] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    least_operation.fill(INT_MAX);

    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        std::cin >> move[i];
    }

    dfs(a, 0, 0);

    std::cout << (least_operation[b] == INT_MAX ? -1 : least_operation[b]) << std::endl;

    return 0;
}