#include <bits/stdc++.h>
using namespace std;
int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    int n = text.size();
    int m = pattern.size();
    int base = 31;
    int mod = 1000003;
    long long patternHash = 0, currentHash = 0, power = 1;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        currentHash = (currentHash * base + text[i]) % mod;
        if (i < m - 1) power = (power * base) % mod;
    }
    vector<int> pos;
  for (int i = 0; i <= n - m; i++) {
      if (patternHash == currentHash) {
            if (text.substr(i, m) == pattern)
                pos.push_back(i);
        }

        if (i < n - m) {
            currentHash = (currentHash - text[i] * power) % mod;
            currentHash = (currentHash * base + text[i + m]) % mod;

            if (currentHash < 0) currentHash += mod;
        }
    }
    if (pos.empty()) {
        cout << "Pattern not found\n";
    } else {
        cout << "Pattern found at positions: ";
        for (int i : pos) cout << i << " ";
        cout << endl;
    }

    return 0;
}
