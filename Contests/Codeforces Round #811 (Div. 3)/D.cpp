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

struct Str{
    ll p1; ll p2; ll amountnew;
};

bool comp(Str st1, Str st2) {
    return st1.amountnew > st2.amountnew;
}


void solve(){
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    bool colored[t.size()];
    memset(colored, false, sizeof colored);

    int ans = 0;
    int last_colored = 0;
    vector<pair<int, int> > index_ans;

    while (1){
        if (last_colored == t.size()){
            break;
        }
        vector<Str> v;
        for (int i = last_colored; i >= 0 ; i--){
            for (int j = 0 ; j < n ; j++){
                if (i + s[j].size() > t.size()){
                    continue;
                }
                string tmp = "";
                for (int k = i ; k < (i + s[j].size()) ; k++){
                    tmp += t[k];
                }
                int cnt = 0;
                if (tmp == s[j]){
                    for (int k = i ; k < (i + s[j].size()) ; k++){
                        if (!colored[k]){
                            cnt++;
                        }
                    }
                    if (cnt > 0){
                        v.pb({i, j, cnt});
                    }
                }
            }
        }
        if (v.size() == 0){
            cout << -1 << endl;
            return;
        }
        sort(all(v), comp);
        for (int j = v[0].p1; j < (v[0].p1 + s[v[0].p2].size()); j++) {
            colored[j] = true;
        }
        ans++;
        index_ans.pb({v[0].p2 + 1, v[0].p1 + 1});

        last_colored = v[0].p1 + s[v[0].p2].size();
    }
    cout << ans << endl;
    for (auto el: index_ans) {
        cout << el.first << " " << el.second << endl;
    }
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
