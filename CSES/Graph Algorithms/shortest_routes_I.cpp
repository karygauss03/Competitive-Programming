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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 5];
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].push_back({v, c});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, INF);
    pq.push({0, 0});
    dist[0] = 0;
    vector<bool> vis(n, false); //tle test18 reason
    while(!pq.empty()) {
        pair<ll, int> cur = pq.top();
        pq.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = true;
        for (auto& v: adj[cur.second]) {
            if (dist[v.first] > dist[cur.second] + v.second) {
                dist[v.first] = dist[cur.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dist[i] << ' ';
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

