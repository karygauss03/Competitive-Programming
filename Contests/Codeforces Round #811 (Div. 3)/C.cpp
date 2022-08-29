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
    int s;
    cin >> s;
    vector<int> ans;
    int cur = 9;
    while (s > 0){
        if (s >= cur){
            ans.pb(cur);
            s -= cur;
            cur--;
        }
        else {
            cur--;
        }
    }
    reverse(rall(ans));
    for (auto &x: ans) cout << x;
    cout << endl;
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
