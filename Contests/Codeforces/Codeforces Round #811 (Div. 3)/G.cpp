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


void dfs(vector<vector<int>>& child, vector<ll>& cost, vector<ll>& pref, vector<int>& a, vector<int>& b, vector<int>& ans, vector<ll>& curPath, int u = 0) {
    for (int v : child[u]) {
        cost[v] = cost[u] + a[v];
        pref[v] = pref[u] + b[v];
        curPath.pb(pref[v]);
        ans[v] = upper_bound(curPath.begin(), curPath.end(), cost[v]) - curPath.begin();
        dfs(child, cost, pref, a, b, ans, curPath, v);
        curPath.pop_back();
    }
}


void solve(){
    int n;
    cin>>n;
    int par[n];
    vector<int> a(n), b(n);
    vector<vector<int>> child(n, vector<int>());
    for (int i = 1; i < n; ++i) {
        cin>>par[i]>>a[i]>>b[i];
        par[i]--;
        child[par[i]].pb(i);
    }

    vector<ll> cost(n, 0), pref(n, 0);
    vector<int> ans(n, 0);
    vector<ll> curPath;
    dfs(child, cost, pref, a, b, ans, curPath);
    for (int i = 1; i < n; ++i) {
        cout<<ans[i]<<" ";
    } cout<<endl;
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
