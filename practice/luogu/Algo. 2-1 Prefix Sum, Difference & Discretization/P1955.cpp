#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_map>

#define MAX_LEN 100000

struct Constrain {
    int i, j, e;

    bool operator<(const Constrain &other) const { return e > other.e; }
};

int n;
std::unordered_map<int, int> disjoint_set;
std::array<Constrain, MAX_LEN> constrains;

int get_root(int i) {
    if (i == disjoint_set[i]) {
        return i;
    }
    disjoint_set[i] = get_root(disjoint_set[i]);
    return disjoint_set[i];
}

inline bool check_family(int i, int j) { return get_root(i) == get_root(j); }

inline void add_var(int i) {
    if (disjoint_set.count(i) == 0) {
        disjoint_set[i] = i;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        disjoint_set.clear();
        int n = 0, non_equal_count = 0;
        std::cin >> n;
        for (int i = 0, a, b, e; i < n; ++i) {
            std::cin >> a >> b >> e;

            add_var(a);
            add_var(b);

            constrains[i] = {a, b, e};
        }

        std::sort(constrains.begin(), constrains.begin() + n);

        bool is_conflict = false;
        for (int i = 0; i < n; ++i) {
            if (constrains[i].e == 1) {
                disjoint_set[get_root(constrains[i].i)] = get_root(constrains[i].j);
            } else {
                if (check_family(constrains[i].i, constrains[i].j)) {
                    is_conflict = true;
                    break;
                }
            }
        }

        if (is_conflict) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}