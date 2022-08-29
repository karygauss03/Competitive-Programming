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
    ll a[n];
    int cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        if (a[i] % 10 == 0 || a[i] % 10 == 5){
            cnt++;
        }
    }
    //case 1: all the numbers in the array end with 0 or 5
    if (cnt == n){
        for (int i = 0 ; i < n ; i++){
            a[i] += (a[i] % 10);
        }
        sort(a, a + n);
        for (int i = 0 ; i < n - 1 ; i++){
            if (a[i] != a[i + 1]){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    else if (cnt > 0){
        cout << "NO\n";
        return;
    }
    //case 2: all the numbers in the array end with 1, 2, 3, 4, 6, 7, 8, 9
    for (int i = 0 ; i < n ; i++){
        if (a[i] % 10 == 1) a[i]++;//will end by 2
        if (a[i] % 10 == 7) a[i] += 7;//will end by 4
        if (a[i] % 10 == 9) a[i] += 9;//will end by 8
        if (a[i] % 10 == 3) a[i] += 3;//will end by 6
    }
    ll mx = INT_MIN;
    for (int i = 0 ; i < n ; i++){
        mx = max(a[i], mx);
    }
    for (int i = 0 ; i < n ; i++){
        ll diff = mx - a[i];
        diff /= 20;
        a[i] += (20 * diff);
    }

    set<ll> s2, s4, s6, s8;
    for (int i = 0; i < n; i++) {
        if (a[i] % 10 == 2) {
            s2.insert(a[i]);
        }
        if (a[i] % 10 == 4) {
            s4.insert(a[i]);
        }
        if (a[i] % 10 == 8) {
            s8.insert(a[i]);
        }
        if (a[i] % 10 == 6) {
            s6.insert(a[i]);
        }
    }

    if (s2.size() > 1 || s4.size() > 1 || s8.size() > 1 || s6.size() > 1) {
        cout << "NO\n";
        return;
    }

    ll val[4] = {-1, -1, -1, -1};
    if (s2.size() > 0) {
        val[0] = *s2.begin();
    }
    if (s4.size() > 0) {
        val[1] = *s4.begin();
    }
    if (s8.size() > 0) {
        val[2] = *s8.begin();
    }
    if (s6.size() > 0) {
        val[3] = *s6.begin();
    }

    ll dr[4] = {2, 4, 8, 6};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (val[i] == -1 || val[j] == -1) {
                continue;
            }

            ll k = i; ll c = 0;
            ll sum = val[i];
            ll goal = val[j];

            if (val[j] < val[i]) {
                k = j;
                sum = val[j];
                goal = val[i];
            }

            while (sum < goal && c < 4) {
                sum += dr[k];
                c++;
                k = (k+1)%4;
            }

            if (sum != goal) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";


    //the mix between case 2 and case 1 is obviously NO
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
