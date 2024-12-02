#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	string line;
	long long ans = 0;
    vector<int> report;
    while (getline(cin, line)) {
        report.clear();
        string cur ="";
        cur += line[0];
        for (int i = 1; i < line.size(); ++i) {
            if (line[i] == ' ') {
                report.push_back(stoi(cur));
                cur = "";
            }
            else {
                cur += line[i];
            }
        }
        report.push_back(stoi(cur));
        int prevDifference = report[1] - report[0];
        bool isNotSafe = false;
        if (abs(prevDifference > 3)) continue;
        for (int i = 1; i < report.size(); ++i) {
            int curDifference = report[i] - report[i - 1];
            if (curDifference * prevDifference <= 0) {
                isNotSafe = true;
                break;
            }
            if (abs(curDifference) > 3) {
                isNotSafe = true;
                break;
            }
        }
        if (!isNotSafe) ++ans;
	}
	cout << ans << endl;
	return 0;
}
