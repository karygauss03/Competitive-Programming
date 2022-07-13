#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define rep1(i, x) for (int i = 1; i <= (int)(x); i++)
#define show(x) cout << #x << " = " << x << endl
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

const int N = 200005;

int a[N], tr[N];
int n;

int update(int i) {
    for(; i <= n; i += (i & (-i)))
        tr[i]++;
}

int add(int i) {
    int res = 0;
    for(; i >= 1; i -= (i & (-i)))
        res += tr[i];
    return res;
}

void solve(){

    cin >> n;


    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tr[i] = 0;
    }
    ll ans = 0;


    for(int i = 1; i <= n; i++) {
        if(a[i] < i) {
            ans += add(a[i] - 1);
            update(i);
        }
    }

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
