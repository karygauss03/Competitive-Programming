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
    int a[n];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    for (int i = 0 ; i < n ; i++){
        int m;
        cin >> m;
        string s;
        cin >> s;
        for (int j = 0 ; j < m ; j++){
            if (s[j] == 'D'){
                a[i] = (a[i] + 1)%10;
            }
            else {
                if (a[i] == 0){
                    a[i] = 9;
                }
                else {
                    a[i] = a[i] - 1;
                }
            }
        }
    }

    for (int i= 0; i   <n; i++) cout << a[i] << ' ';
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
