#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Function to compute part 2
ll countXMAS(int i, int j, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    ll result = 0;

    if (grid[i][j] == 'A') { // Center character must be 'A'
        // Get the characters around the current point
        if (isValid(i - 1, j - 1, n, m) && isValid(i - 1, j + 1, n, m) &&
            isValid(i + 1, j - 1, n, m) && isValid(i + 1, j + 1, n, m)) {
            
            char ul = grid[i - 1][j - 1]; // Upper-left
            char ur = grid[i - 1][j + 1]; // Upper-right
            char dl = grid[i + 1][j - 1]; // Down-left
            char dr = grid[i + 1][j + 1]; // Down-right

            // Horizontal condition
            bool horizontal = (ul == dl && ur == dr && abs(ul - ur) == 6);
            // Vertical condition
            bool vertical = (ul == ur && dl == dr && abs(ul - dl) == 6);

            result += (horizontal || vertical);
        }
    }

    return result;
}

void solve() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.pb(line);
    }

    int n = grid.size(), m = grid[0].size();
    ll ans = 0;

    // Traverse the grid
    for (int i = 1; i < n - 1; ++i) { // Avoid edges
        for (int j = 1; j < m - 1; ++j) {
            ans += countXMAS(i, j, grid);
        }
    }

    cout << ans << endl;
}

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

int main() {
    string filename = "in.txt";
    if (fileExists(filename)) {
        freopen(filename.c_str(), "r", stdin);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
