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
// const int N = 2e5 + 5;
const int MOD = 998244353;


void solve() {
    int n;
    cin >> n;
    int mh = 0, mw = 0;
    for (int i = 0; i < n; ++i) {
        int w, h;
        cin >> w >> h;
        mw = max(mw, w);
        mh = max(mh, h);
    }
    cout << 2 * (mw + mh) << endl;
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
