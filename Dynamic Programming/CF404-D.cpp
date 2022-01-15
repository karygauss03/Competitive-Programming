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

const int MOD = 1000000007 ;
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


string s, ans;


ll dp[1000042][5] = {0};

void upd(ll &a, ll &b){
    a = (a + b) % MOD;
}

void solve()
{
    string s;
    cin >> s;
    if(s[0] == '0') dp[0][0] = 1;
      else if(s[0] == '1') dp[0][2] = 1;
      else if(s[0] == '*') dp[0][4] = 1;
      else if(s[0] == '?') { dp[0][0] = dp[0][2] = dp[0][4] = 1; }

      int n = s.size();

      for(int i = 1; i < n; i++) {
        if(s[i] == '0' || s[i] == '?') {
          upd(dp[i][0], dp[i - 1][0]);
          upd(dp[i][0], dp[i - 1][1]);
        }
        if(s[i] == '1' || s[i] == '?') {
          upd(dp[i][2], dp[i - 1][0]);
          upd(dp[i][2], dp[i - 1][1]);
          upd(dp[i][1], dp[i - 1][4]);
        }
        if(s[i] == '2' || s[i] == '?') {
          upd(dp[i][3], dp[i - 1][4]);
        }
        if(s[i] == '*' || s[i] == '?') {
          upd(dp[i][4], dp[i - 1][2]);
          upd(dp[i][4], dp[i - 1][3]);
          upd(dp[i][4], dp[i - 1][4]);
        }
      }

      cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][4]) % MOD;

}



int main()
{
    fastio;
    //freopen("input.txt","r", stdin);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}