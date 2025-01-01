#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl '\n'
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define REPR(i, a, b) for (int i = (a); i >= (b); --i)
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORR(i, n) for (int i = (n)-1; i >= 0; --i)
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
char grid[1005][1005];
pair<int, int> parent[1005][1005];
bool vis[1005][1005];

vector<char> directions = {'L', 'R', 'U', 'D'};
vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool is_valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j] != '#';
}

void solve()
{
    cin >> n >> m;
    pair<int, int> start, end;
    FOR(i, n)
    {
        FOR(j, m)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur == end)
        {
            vector<char> path;
            while (cur != start)
            {
                pair<int, int> par = parent[cur.first][cur.second];
                for (int d = 0; d < 4; ++d)
                {
                    if (par.first + moves[d].fi == cur.first && par.second + moves[d].se == cur.second)
                    {
                        path.pb(directions[d]);
                        break;
                    }
                }
                cur.first = par.first;
                cur.second = par.second;
            }
            reverse(all(path));
            yes;
            cout << sz(path) << endl;
            for (auto &c : path)
                cout << c;
            cout << endl;
            return;
        }

        FOR(d, 4)
        {
            int nx = cur.first + moves[d].fi, ny = cur.second + moves[d].se;
            if (is_valid(nx, ny))
            {
                vis[nx][ny] = true;
                parent[nx][ny] = cur;
                q.push({nx, ny});
            }
        }
    }
    no;
}

bool fileExists(const string &filename)
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
