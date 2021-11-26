//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<pair<int,int>> vp;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int)(x).size())
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define endl '\n'

const int MOD = (1e9)+7 ;
const int N = 1e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const ll inf = (1LL << 61) - 1;

/*ll get_rand(ll l, ll r) {
    ll first_rand_value = (rand() * rand()) % MOD + MOD;
    ll second_rand_value = (rand() * rand()) % MOD + MOD;
    return (first_rand_value * second_rand_value) % (r - l + 1) + l;
}*/

void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}

vector<vector<ll>> adj;
vector<ll> cur_path, vis, parent, dist;
set<int> block, friends, leafs;

void dfs(int v, int par = -1){
    cur_path.pb(v);
    if (friends.count(v)){
        block.insert(cur_path[(cur_path.size()) / 2]);
    }
    if (par != -1){
        dist[v] = dist[par] + 1;
        parent[v] = par;
    }
    vis[v] = 1;
    for (auto u : adj[v]){
        if (!vis[u]){
            //cout << v << '-' << u << endl;
            dfs(u, v);
        }
    }
    cur_path.pop_back();
    if (adj[v].size() == 1 && v != 0)
        leafs.insert(v);
}


void dfs2(int v){
    vis[v] = 1;
    for (auto u : adj[v]){
        if (!vis[u] && u != parent[v]) dfs2(u);
    }
    if (leafs.count(v)){
        leafs.erase(v);
    }
}


void solve()
{
    int n, k;
    cin >> n >> k;
    friends.clear();
    for (int i = 0 ; i < k ; i++){
        int u;
        cin >> u;
        u--;
        friends.insert(u);
    }
    adj.clear();
    adj.resize(n);
    for (int i = 0 ; i < n - 1 ; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis = vector<ll> (n,0);
    block.clear();
    cur_path.clear();
    dist = vector<ll> (n, 0);
    parent = vector<ll> (n, 0);
    leafs.clear();
    dfs(0);
    vector<pair<ll, ll>> values;
    for (auto b : block){
        values.pb(mp(dist[b], b));
    }
    sort(all(values));
    vis = vector<ll> (n, 0);
    int cnt = 0;
    for (auto v : values){
        if (!vis[v.se]){
            cnt++;
            dfs2(v.se);
            if (leafs.empty()) break;
        }
    }
    if (leafs.empty()) cout << cnt << endl;
    else cout << -1 << endl;
}



int main()
{
    fastio;
    //freopen("input.txt","r", stdin);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
