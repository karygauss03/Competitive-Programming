#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define show(x) cout << #x << " = " << x << endl
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
const int N = 2e5 + 3;


void solve(){
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (n == 1 && m == 1){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    ans++;
    ans += n - 1;
    ans++;
    ans++;
    ans += (m - 2) * 2;
    cout << ans << endl;
}


int main(){
    fastio
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
