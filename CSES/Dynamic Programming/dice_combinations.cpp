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

ll work(ll i, vector<ll>& dp) {
    if (i == 0) return 1;
    if (dp[i] != -1) return dp[i]; 

    ll cur = 0;
    for (int j = 1; j <= 6; ++j) {
        // dbg(i, j);
        if (i - j >= 0)
            cur = (cur + work(i - j, dp)) % MOD;
    }
    return dp[i] = cur;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll>dp(n + 1, -1);
    cout << work(n, dp) % MOD << endl;
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
