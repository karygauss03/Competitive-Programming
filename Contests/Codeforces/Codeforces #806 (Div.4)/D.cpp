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
    set<string> ss;
    for (int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        v.pb(s);
        ss.insert(s);
    }
    for (int i = 0 ; i < n ; i++){
        string cur = v[i];
        //show(cur);
        int j = 1;
        bool found = false;
        while (j < cur.size() && !found){
            //show(cur.substr(0, j));
            //show(cur.substr(j));
            if (ss.count(cur.substr(0, j)) && ss.count(cur.substr(j))){
                found = true;
            }
            j++;
        }
        if (found) cout << 1;
        else cout << 0;
    }

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
