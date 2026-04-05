#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>

#define MAX_LEN 1001

struct Person {
    int t, id;

    static bool compare(const Person& a, const Person& b) { return a.t < b.t; }
};

std::array<Person, MAX_LEN> people;

int main() {
    std::cout.sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> people[i].t;
        people[i].id = i + 1;
    }

    std::sort(people.begin(), people.begin() + n, &Person::compare);

    unsigned long long total = 0;
    std::cout << people[0].id;
    for (int i = 1; i < n; ++i) {
        total += (n - i) * people[i - 1].t;
        std::cout << ' ' << people[i].id;
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2) << 1.0 * total / n
              << std::endl;

    return 0;
}
