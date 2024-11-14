#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	int ans = 0;
	while (getline(cin, line)) {
        char p1 = line[0], p2 = line[2];
        if (p1 == 'A') {
            if (p2 == 'Y') {
                ans += 1 + 3;
            }
            if (p2 == 'X') {
                ans += 3;
            }
            if (p2 == 'Z') {
                ans += 6 + 2;
            }
        }
        if (p1 == 'B') {
            if (p2 == 'Y') {
                ans += 2 + 3;
            }
            if (p2 == 'X') {
                ans += 1;
            }
            if (p2 == 'Z') {
                ans += 6 + 3;
            }
        }
        if (p1 == 'C') {
            if (p2 == 'Y') {
                ans += 3 + 3;
            }
            if (p2 == 'X') {
                ans += 2;
            }
            if (p2 == 'Z') {
                ans += 6 + 1;
            }
        }
	}
	cout << ans << endl;
	return 0;
}
