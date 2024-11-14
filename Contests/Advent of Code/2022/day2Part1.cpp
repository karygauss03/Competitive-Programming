#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	int ans = 0;
	while (getline(cin, line)) {
        char p1 = line[0], p2 = line[2];
        // Draw
        if (p1 == 'A' && p2 == 'X') {
            ans += 1 + 3;
        }
        if (p1 == 'B' && p2 == 'Y') {
            ans += 2 + 3;
        }
        if (p1 == 'C' && p2 == 'Z') {
            ans += 3 + 3;
        }
        // Win
        // P1: A & P2:Y
        if (p1 == 'A' && p2 == 'Y') {
            ans += 2 + 6;
        }
        // P1: B & P2: Z
        if (p1 == 'B' && p2 == 'Z') {
            ans += 3 + 6;
        }
        // P1: C & P2: X
        if (p1 == 'C' && p2 == 'X') {
            ans += 1 + 6;
        }

        // Loss
        // P1: A & P2: Z
        if (p1 == 'A' && p2 == 'Z') {
            ans += 3;
        }
        // P1: B & P2: X
        if (p1 == 'B' && p2 == 'X') {
            ans += 1;
        }
        // P1: C & P2: Y
        if (p1 == 'C' && p2 == 'Y') {
            ans += 2;
        }
	}
	cout << ans << endl;
	return 0;
}
