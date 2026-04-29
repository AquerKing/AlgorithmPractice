#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::string s;
    std::cin >> s;
    std::cin >> k;

    for (int i = 0, cur_len; i < k; ++i) {
        cur_len = s.size();
        for (int j = 1; j < s.size(); ++j) {
            if (s[j - 1] > s[j]) {
                s.erase(j - 1, 1);
                break;
            }
        }
        if (cur_len == s.size()) {
            s.erase(cur_len - 1, 1);
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0' && i < s.size() - 1) {
            continue;
        }
        s.erase(0, i);
        break;
    }
    std::cout << s << std::endl;

    return 0;
}