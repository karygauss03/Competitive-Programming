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


void solve(){
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0 ; i <n ; i++){
        string s;
        cin >> s;
        v.pb(s);
    }

    int l = 0, r = n - 1;
    int x = 0, y = n - 1;
    int ans = 0;
    while (x <= y && l <= r){
        int tmp = r;
        for (int j = l ; j < r  ;j ++){
            int cur = v[x][j] - '0' + v[j][r] - '0' + v[y][tmp] - 48 + v[tmp][l] - 48;
            int d = 4 - cur;
            int e = min(d, cur);
            ans = ans + e;
            tmp--;
        }
        x++, y--, l++, r--;
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
