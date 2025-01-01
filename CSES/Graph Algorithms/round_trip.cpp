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

vector<int> adj[100005];
vector<bool> vis(100005, false);
vector<int> parent(100005, -1);
int start = -1, endNode = -1;

void dfs(int node, int par) {
    vis[node] = true;
    for (auto& neighbor : adj[node]) {
        if (neighbor == par) continue;
        if (vis[neighbor]) {
            start = neighbor;
            endNode = node;
            return;
        }
        parent[neighbor] = node;
        dfs(neighbor, node);
        if (start != -1) return;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
            if (start != -1) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.pb(start);
        for (int v = endNode; v != start; v = parent[v]) {
            cycle.pb(v);
        }
        cycle.pb(start);

        cout << cycle.size() << endl;
        for (auto v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
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
