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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<ll> ans(n, 0);
    ll p = k * b;
    if (p > s){
        cout << -1 << endl;
        return;
    }
    ans[0] = p;
    //show(ans[0]);
    s -= p;
    //show(s);
    for (int i = 1 ; i < n ; i++){
        if (s < k - 1){
            ans[i] = s;
            s = 0;
       //     cout << i << endl;
         //   show(ans[i]);
           // show(s);
        }
        else {
            ans[i] = k - 1;
            s -= k - 1;
            //show(ans[i]);
            //show(s);
        }
    }
    if (s != 0 && s <= k - 1){
        ans[0] += s;
        s = 0;
    }
    if (s != 0){
        cout << -1 << endl;
        return;
    }

    for (auto &x : ans) cout << x << ' ';
    cout << endl;
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
