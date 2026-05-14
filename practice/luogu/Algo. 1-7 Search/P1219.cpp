#include <array>
#include <iostream>

#define MAX_LEN 13

int n = 0;
std::array<bool, MAX_LEN + 1> row = {false};
std::array<bool, MAX_LEN + 1> column = {false};
std::array<bool, MAX_LEN * 2> diagonal = {false};
std::array<bool, MAX_LEN * 2> counter_diagonal = {false};
std::array<int, MAX_LEN + 1> cache = {0};

int printed_count = 0, ans_count = 0;

void dfs(int col) {
    if (col > n) {
        if (printed_count < 3) {
            std::cout << cache[1];
            for (int i = 2; i <= n; ++i) {
                std::cout << ' ' << cache[i];
            }
            std::cout << std::endl;
            ++printed_count;
        }
        ++ans_count;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!row[i] && !column[i] && !diagonal[col + i - 1] &&
            !counter_diagonal[n + col - i]) {
            cache[col] = i;

            row[i] = true;
            column[i] = true;
            diagonal[col + i - 1] = true;
            counter_diagonal[n + col - i] = true;
            dfs(col + 1);
            row[i] = false;
            column[i] = false;
            diagonal[col + i - 1] = false;
            counter_diagonal[n + col - i] = false;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    std::cin >> n;
    dfs(1);
    std::cout << ans_count << std::endl;

    return 0;
}