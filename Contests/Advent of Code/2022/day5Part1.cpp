#include <bits/stdc++.h>
using namespace std;

void initStacks(vector<stack<char>> &stacks) {
    string line;
    vector<string> inputLines;
    
    while (getline(cin, line) && line[1] != '1') {
        inputLines.push_back(line);
    }

    if (!inputLines.empty()) {
        stacks.resize(line.size() / 4 + 1);
    }

    for (int i = inputLines.size() - 1; i >= 0; i--) {
        for (int j = 0; j < stacks.size(); j++) {
            int k = j * 4 + 1; // Position in the line to check
            if (k < inputLines[i].size() && inputLines[i][k] != ' ') {
                stacks[j].push(inputLines[i][k]);
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    vector<stack<char>> stacks;

    initStacks(stacks);

    getline(cin, line);

    const regex pattern(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))");
    while (getline(cin, line)) {
        if (line.empty()) continue;

        smatch match;
        regex_match(line, match, pattern);

        int numCrates = stoi(match[1]);
        int fromStack = stoi(match[2]) - 1;
        int toStack = stoi(match[3]) - 1;

        for (int i = 0; i < numCrates; i++) {
            if (!stacks[fromStack].empty()) {
                char crate = stacks[fromStack].top();
                stacks[fromStack].pop();
                stacks[toStack].push(crate);
            }
        }
    }

    for (const auto& stack : stacks) {
        if (!stack.empty()) {
            cout << stack.top();
        } else {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}
