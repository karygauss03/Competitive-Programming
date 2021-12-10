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

int dp[5003];

void solve()
{
    string s;
    while(cin >> s && s != "0"){
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1 ; i <= n ; i++){
            int prev = (s[i - 1] - '0') * 10;
            int cur = s[i] - '0';
            if (cur > 0){
                dp[i] += dp[i - 1];
            }
            if (prev >= 10 && prev <= 26){
                dp[i] += dp[i - 2 < 0 ? 0 : i - 2];
            }
        }
        cout << dp[n - 1] << endl;
    }
}



int main()
{
    fastio;
    freopen("input.txt","r", stdin);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
