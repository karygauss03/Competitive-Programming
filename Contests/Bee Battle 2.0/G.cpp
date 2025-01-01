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

ll min_energy(int start, int end, const vector<int>& bees, ll A, ll B, map<pair<int, int>, ll>& memo) {
    if (start > end) return 0;
 
    auto it = lower_bound(bees.begin(), bees.end(), start);
    auto jt = upper_bound(bees.begin(), bees.end(), end);
 
    ll nb = jt - it; // Number of bees in the current segment
    ll length = end - start + 1;
 
    if (nb == 0) return A;
 
    if (memo.count({start, end})) return memo[{start, end}];
 
    ll burn_energy = B * nb * length;
 
    if (length == 1) {
        return memo[{start, end}] = burn_energy;
    }
 
    int mid = (start + end) / 2;
    ll split_energy = min_energy(start, mid, bees, A, B, memo) + min_energy(mid + 1, end, bees, A, B, memo);
 
    return memo[{start, end}] = min(burn_energy, split_energy);
}


void solve() {
    int n, k;
    ll A, B;
    cin >> n >> k >> A >> B;
    
    vector<int> bees(k);
    for (int i = 0; i < k; ++i) {
        cin >> bees[i];
    }
 
    sort(bees.begin(), bees.end());
 
    map<pair<int, int>, ll> memo;
    cout << min_energy(1, (1 << n), bees, A, B, memo) << endl;
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
