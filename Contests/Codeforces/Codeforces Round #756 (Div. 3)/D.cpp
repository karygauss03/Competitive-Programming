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
void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}


void solve()
{
    int n;
    cin >> n;
    vector<ll> tree(n);
    int root = -1;
    for (int i = 0 ; i < n ; i++){
        cin >> tree[i];
        tree[i]--;
        if (tree[i] == i)
            root = i;
    }
    vector<ll> used (n + 1000, 0);
    used[root] = 1;
    ll first;
    cin >> first;
    first--;
    vector<ll> values(n - 1);

    for (int i = 0 ; i < n - 1 ; i++){
        cin >> values[i];
        values[i]--;
    }
    ll cur_dist = 0;
    vector<ll> dist(n, 0);
    for (auto cur : values){
        if (!used[tree[cur]]){
            cout << -1 << endl;
            return;
        }
        cur_dist += 1;
        used[cur] = 1;
        dist[cur] = cur_dist;
    }
    if (first != root){
        cout << -1 << endl;
        return;
    }
    for (int i = 0 ; i < n ; i++){
        cout << dist[i] - dist[tree[i]] << ' ';
    }
    cout << endl;
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
