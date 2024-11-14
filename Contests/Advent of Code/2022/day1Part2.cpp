#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	vector<int> ans;
	int cur = 0;
	while (getline(cin, line)) {
        if (line.size() == 0) {
            ans.push_back(cur);
            cur = 0;
        }
        else {
            cur += (int)stoi(line);
        }
	}
	ans.push_back(cur);
	sort(ans.rbegin(), ans.rend());
	cout << ans[0] + ans[1] + ans[2] << endl;
	return 0;
}
