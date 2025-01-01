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

int n, m;
vector<int> adj[N];
bool vis[N];

void solve() {
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> par(n, -1);
    queue<int> q;
    q.push(0);
    par[0] = -1;
    vis[0] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n - 1) {
            vector<int> path;
            for (int u = cur; u != -1; u = par[u]) {
                path.pb(u + 1);
            }
            reverse(all(path));
            cout << path.size() << endl;
            for (auto& node: path) {
                cout << node << ' ';
            }
            cout << endl;
            return;
        }

        for (auto& v : adj[cur]) {
            if (!vis[v]) {
                vis[v] = true;
                par[v] = cur;
                q.push(v);
            }
        }

    }

    cout << "IMPOSSIBLE\n";
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