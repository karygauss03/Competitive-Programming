#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        int n = line.size();
        vector<int> freq(52, 0), freq2(52, 0);

        for (int i = 0; i < n / 2; ++i) {
            if (isupper(line[i])) {
                freq[line[i] - 'A' + 26]++;
            } else {
                freq[line[i] - 'a']++;
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (isupper(line[i])) {
                freq2[line[i] - 'A' + 26]++;
            } else {
                freq2[line[i] - 'a']++;
            }
        }

        for (int i = 0; i < 52; ++i) {
            if (freq[i] > 0 && freq2[i] > 0) {
                ans += i + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
