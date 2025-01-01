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
const int mod = 998244353;
int n, m;

ll work(int i, int j, vector<vector<char>>& grid, vector<vector<long long>>& dp) {
    if (i >= n || j >= m) {
        return 0;
    }
    if (grid[i][j] == '*') return 0;
    if (i == n - 1 && j == m - 1) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    ll right = work(i, j + 1, grid, dp);
    ll down = work(i + 1, j, grid, dp);
    return dp[i][j] = (right + down) % mod;
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    cout << work(0, 0, grid, dp) << endl;
}

int main()
{
    // freopen("in.txt", "r", stdin);
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