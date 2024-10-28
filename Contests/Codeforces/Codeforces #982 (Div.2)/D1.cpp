#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl '\n';
#define sz(x) ((int)(x).size())
#define min(a, b) a < b ? a : b
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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(auto &x : a){
        cin >> x;
    }
    vector<ll> b(m);
    for(auto &x : b) {
        cin >> x;
    }
    vector<ll> prefix(n+1, 0);
    for(int i=0;i<n;i++) {
        prefix[i+1] = prefix[i] + a[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    dp[0][1] = 0;
    deque<pair<int, int>> dq;
    dq.emplace_back(0, 1);
    while(!dq.empty()){
        auto [i, k] = dq.front();
        dq.pop_front();

        ll cur = dp[i][k];
        if(k <m){
            if(dp[i][k+1] > cur){
                dp[i][k+1] = cur;
                dq.emplace_front(i, k+1);
            }
        }
        ll mx = prefix[i] + b[k-1];
        int j = upper_bound(prefix.begin(), prefix.end(), mx) - prefix.begin() -1;
        if(j > i){
            ll upd = cur + (m - k);
            if(dp[j][k] > upd){
                dp[j][k] = upd;
                dq.emplace_back(j, k);
            }
        }
    }
    ll ans = INF;
    for(int k=1; k<=m; k++) {
        ans = min(ans, dp[n][k]);
    }
    if(ans == INF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
