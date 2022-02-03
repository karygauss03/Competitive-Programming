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

const int MOD = 1000000007;
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

string s;
ll dp[1<<20];
int n;
int student [20][20];

int cnt (int i){
    int num = 0;
    while (i > 0){
        num += (i & 1);
        i >>= 1;
    }
    return num;
}


void solve()
{
    cin >> n;
    memset(dp, 0, sizeof dp);
    memset(student, 0, sizeof student);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> student[i][j];
        }
    }

    dp[(1<<n) - 1] = 1;
    for (int i = (1<<n) - 1 ; i >= 0 ; i--){
        int index = cnt(i);
        for (int j = 0 ; j < n ; j++){
            if (student[index][j] == 0 || (i & (1<<j))) continue;
            dp[i] += dp[i|(1<<j)];
        }
    }
    cout << dp[0] << endl;

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
