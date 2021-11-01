//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl ;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
const int N = 2e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
const int M=(1e9)+7;
const ll inf = (1LL << 61) - 1;
const int INF = 10000;
void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}

vector<int> adj[2001];
vector<int> root;
bool vis[2001];
int ans = 0;
int lvl[2001];


void bfs(int src){
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (auto u : adj[x]){
            if (!vis[u]){
                lvl[u] = lvl[x] + 1;
                ans = max(ans, lvl[u]);
                vis[u] = true;
                q.push(u);
            }
        }
    }
    return;
}

void solve(){
    int n;
    memset(vis, false, sizeof(vis));
    memset(lvl, 0, sizeof(lvl));
    cin >> n;
    int src ;
    for (int i = 0 ; i < n ;i++) {
        int x;
        cin >> x;
        if (x!=-1){
            x--;
            adj[x].pb(i);
        }
        else{
            root.pb(i);
        }
    }
    for (auto u : root){
        lvl[u] = 1;
        bfs(u);
    }

    cout << max(ans,1);

}



int main()
{
    fastio;
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
