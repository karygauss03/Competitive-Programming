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

ll ans, a[N];
int n, m;
void upd(int i, int x){
    ll d1 = (x != a[i - 1]) - (a[i] != a[i - 1]);
    ll d2 = (x != a[i + 1]) - (a[i] != a[i + 1]);
    ans += d1 * (i - 1) + d2 * (n - i) + (d1 + d2) * (i - 1) * (n - i);
    a[i] = x;
}


void solve(){
    cin >> n >> m;
    ans = 1LL * n * (n + 1) >> 1;
    for (int i = 1; i <= n ; i++){
        int x;
        cin >> x;
        upd(i, x);
    }

    while (m--){
        int i, x;
        cin >> i >> x;
        upd(i, x);
        cout << ans << endl;
    }

}


int main(){
    fastio
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
