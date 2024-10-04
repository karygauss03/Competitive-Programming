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
vector<ll> cur_path, vis;
set<int> block, friends;

void dfs(int v){
    cur_path.pb(v);
    if (friends.count(v)){
        // cout << "Test ";
        /* for (auto i : cur_path) cout << i << ' ';
        cout << endl;*/
        block.insert(cur_path[(cur_path.size()) / 2]);
    }
    vis[v] = 1;
    for (auto u : adj[v]){
        if (!vis[u]){
            //cout << v << '-' << u << endl;
            dfs(u);
        }
    }
    cur_path.pop_back();
}

bool flag = false;

void dfs2(int v){
    if (block.count(v)) return;
    vis[v] = 1;
    if (v != 0 && adj[v].size() == 1){
        flag = true;
    }
    for (auto u : adj[v]){
        if (!vis[u])
            dfs2(u);
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
    dfs(0);
    flag = false;
    /*for (auto u : block) cout << u << ' ';
    cout << endl;*/
    vis = vector<ll> (n, 0);
    dfs2(0);
    if (flag) yes();
    else no();
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
