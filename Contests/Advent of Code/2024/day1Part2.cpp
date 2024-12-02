#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	long long ans = 0;
	vector<int> left;
    map<int, int> count;
    while (getline(cin, line)) {
        int spaceIndex = line.find(' ');
        left.push_back(stoi(line.substr(0,spaceIndex)));
        count[stoi(line.substr(spaceIndex + 3))]++;
	}
    for (int i = 0; i < left.size(); ++i) {
        ans += abs(left[i] * count[left[i]]);
    }
	cout << ans << endl;
	return 0;
}
