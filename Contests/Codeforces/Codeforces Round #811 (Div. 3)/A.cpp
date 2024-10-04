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
    int n, H, M;
    cin >> n >> H >> M;
    int h, m;
    int ans = INT_MAX;
    for (int i = 0 ; i < n ; i++){
        cin >> h >> m;
        int cur = 60 * (h - H) + m - M;
        if (cur < 0) cur += 24 * 60;
        ans = min(ans, cur);
    }
    cout << ans / 60 << ' ' << ans % 60 << endl;
}


int main(){
    fastio
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
