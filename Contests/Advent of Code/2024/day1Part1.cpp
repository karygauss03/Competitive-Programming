#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	long long ans = 0;
	vector<int> left, right;
    while (getline(cin, line)) {
        int spaceIndex = line.find(' ');
        left.push_back(stoi(line.substr(0,spaceIndex)));
        right.push_back(stoi(line.substr(spaceIndex + 3)));
	}
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i = 0; i < left.size(); ++i) {
        ans += abs(left[i] - right[i]);
    }
	cout << ans << endl;
	return 0;
}
