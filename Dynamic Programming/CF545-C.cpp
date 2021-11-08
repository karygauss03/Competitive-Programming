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
const int N = 1e5 + 5;
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

const int MAX = 100005;

int n,x[MAX], h[MAX], dp[MAX];

void solve(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> x[i] >> h[i];
        dp[i] = x[i];
    }
    int ans = 2;
    for (int i = 1 ; i < n - 1 ; i++) {
        if (dp[i - 1] < x[i] - h[i]){
            ans++;
        }
        else if (dp[i + 1] > x[i] + h[i]){
            ans++;
            dp[i] += h[i];
        }
    }
    if (n == 1) cout <<1;
    else cout << ans;
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
