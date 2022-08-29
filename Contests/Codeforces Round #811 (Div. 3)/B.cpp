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
    int n;
    cin >> n;
    int a[n];
    map<int, int> ma;
    int duplicated = 0;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
        ma[a[i]]++;
        if (ma[a[i]] > 1){
            duplicated++;
        }
    }
    int ans = 0;
    int i = 0;
    while (i < n && duplicated > 0){
        if (ma[a[i]] > 1){
            ma[a[i]]--;
            duplicated--;
        }
        ans++;
        i++;
    }
    cout << ans << endl;
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
