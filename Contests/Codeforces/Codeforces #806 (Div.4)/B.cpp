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
    string s;
    cin >> s;
    int freq[26];
    memset(freq, 0, sizeof freq);
    for (auto &c : s){
        freq[c - 'A']++;
    }

    int ans = 0;
    for (int i = 0 ; i < 26 ; i++){
        if (freq[i] != 0) ans += freq[i] + 1;

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
