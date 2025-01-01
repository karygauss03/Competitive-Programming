#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define show(x) cout << #x << " = " << x << endl
#define yes cout << "YES\n"
#define no cout << "NO\n"
void dbg_out()
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
typedef long long ll;
const int N = 2e5 + 5;
const int MOD = (1e9) + 7;
const ll INF = 1e18;

char xmas[4] = {'X', 'M', 'A', 'S'};

ll leftCount(int i, int j, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    for (int c = j; c < j + 4 && c < m; ++c) {
        if (grid[i][c] == xmas[c - j]) ++cnt;
        else break;
    }
    if (cnt == 4) return 1LL;
    else return 0LL;
}

ll rightCount(int i, int j, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    for (int c = j; c > j - 4 && c >= 0; --c) {
        if (grid[i][c] == xmas[j - c]) ++cnt;
        else break;
    }
    if (cnt == 4) return 1LL;
    else return 0LL;
}

ll upCount(int i, int j, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    for (int r = i, k = 0; r > i - 4 && r >= 0; --r, ++k) {
        if (grid[r][j] == xmas[k]) ++cnt;
        else break;
    }
    if (cnt == 4) return 1LL;
    else return 0LL;
}

ll downCount(int i, int j, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    for (int r = i, k = 0; r < i + 4 && r < n; ++r, ++k) {
        if (grid[r][j] == xmas[k]) ++cnt;
        else break;
    }
    if (cnt == 4) return 1LL;
    else return 0LL;
}

ll diagCount(int i, int j, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    ll count = 0;

    // Top-left to bottom-right
    int cnt = 0;
    for (int r = i, c = j, k = 0; r < n && c < m && k < 4; ++r, ++c, ++k) {
        if (grid[r][c] == xmas[k]) ++cnt;
        else break;
    }
    if (cnt == 4) count++;

    // Top-right to bottom-left
    cnt = 0;
    for (int r = i, c = j, k = 0; r < n && c >= 0 && k < 4; ++r, --c, ++k) {
        if (grid[r][c] == xmas[k]) ++cnt;
        else break;
    }
    if (cnt == 4) count++;

    // Bottom-left to top-right
    cnt = 0;
    for (int r = i, c = j, k = 0; r >= 0 && c < m && k < 4; --r, ++c, ++k) {
        if (grid[r][c] == xmas[k]) ++cnt;
        else break;
    }
    if (cnt == 4) count++;

    // Bottom-right to top-left
    cnt = 0;
    for (int r = i, c = j, k = 0; r >= 0 && c >= 0 && k < 4; --r, --c, ++k) {
        if (grid[r][c] == xmas[k]) ++cnt;
        else break;
    }
    if (cnt == 4) count++;

    return count;
}

void solve()
{
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.pb(line);
    }

    int n = grid.size(), m = grid[0].size();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X'){
                ans += leftCount(i, j, grid);
                ans += rightCount(i, j, grid);
                ans += upCount(i, j, grid);
                ans += downCount(i, j, grid);
                ans += diagCount(i, j, grid);
            }
        }
    }

    cout << ans << endl;
}

bool fileExists(const string& filename)
{
    ifstream file(filename);
    return file.good();
}

int main()
{
    string filename = "in.txt";
    if (fileExists(filename))
    {
        freopen(filename.c_str(), "r", stdin);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}

