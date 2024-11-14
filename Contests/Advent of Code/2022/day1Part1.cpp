#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	int ans = 0, cur = 0;
	while (getline(cin, line)) {
        if (line.size() == 0) {
            ans = max(ans, cur);
            cur = 0;
        }
        else {
            cur += (int)stoi(line);
        }
	}
	ans = max(ans, cur);
	cout << ans << endl;
	return 0;
}
