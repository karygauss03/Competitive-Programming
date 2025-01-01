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
int col[N];
vector<int> ans;

void addEdge(int u, int v) {
    --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
}

bool isBipartiteGraph() {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1) {
            ans[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (auto& v : adj[cur]) {
                    if (ans[v] == -1) {
                        ans[v] = (ans[cur] == 1) ? 2 : 1;
                        q.push(v);
                    }
                    else if (ans[v] == ans[cur]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    memset(col, 0, sizeof col);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    ans.resize(n, -1);
    if (!isBipartiteGraph()) {
        cout << "IMPOSSIBLE\n" << endl;
        return;
    }

    for (auto& x : ans) {
        cout << x << ' ';
    }
    cout << endl;
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
