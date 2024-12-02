#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& report) {
    if (report.size() < 2) return true;

    int prevDifference = report[1] - report[0];
    if (abs(prevDifference) > 3) return false;

    for (int i = 2; i < report.size(); ++i) {
        int curDifference = report[i] - report[i - 1];
        if (curDifference * prevDifference <= 0 || abs(curDifference) > 3) {
            return false;
        }
        prevDifference = curDifference;
    }
    return true;
}

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    long long ans = 0;
    vector<int> report;

    while (getline(cin, line)) {
        report.clear();
        string cur = "";
        cur += line[0];
        for (int i = 1; i < line.size(); ++i) {
            if (line[i] == ' ') {
                report.push_back(stoi(cur));
                cur = "";
            } else {
                cur += line[i];
            }
        }
        report.push_back(stoi(cur));

        if (isSafe(report)) {
            ++ans;
            continue;
        }

        bool madeSafe = false;
        for (int i = 0; i < report.size(); ++i) {
            vector<int> temp = report;
            temp.erase(temp.begin() + i);
            if (isSafe(temp)) {
                madeSafe = true;
                break;
            }
        }

        if (madeSafe) ++ans;
    }

    cout << ans << endl;
    return 0;
}
