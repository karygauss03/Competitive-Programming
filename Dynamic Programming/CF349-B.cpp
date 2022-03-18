//KARYGAUSS03

//------------------------------------------------------------------------------
             /////////        ./////          ((((((          ,#####
            ///////////  ******////////((,  ((((((((((      ##########
            ///////////********////////((( ((((((((((((    ############
           /////////////*****        //(( (((((((((#%%%    #############
          ///////////////**               ((((((((##%%%%  ##############
         ///////  ********               ((((((((###%%%%%################
        ///////  //********             (((((((( ###%%%%######### ########
       /////////////********           (((((((((  ###%%%########  #########
      ///////////////**********/  ,////((((((((    #%%%########    ########,
     ///////////       ********////////(((((##      %%########      ########
    ////////               ****////////((####       ,########        ########
//------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
const int N = 1e6 + 5;
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


int v, a[9];

int dp[N][10];
vector<int> res;

int sol(int rem, int idx){
    if (idx == 9) return 0;
    int &res = dp[rem][idx];
    if (res != -1) return res;

    res = 0;

    if (rem - a[idx] >= 0){
        res = max(res, 1 + sol(rem - a[idx], idx));
    }

    res = max(res, sol(rem, idx + 1));
    return res;
}

void sol2(int rem, int idx){
    if (idx == 9) return;
    if (rem - a[idx] >= 0){
        if (sol(rem, idx) == 1 + sol(rem - a[idx], idx)){
            res.pb(9 - idx);
            sol2(rem - a[idx], idx);
            return;
        }
    }
    if (sol(rem, idx) == sol(rem, idx + 1)){
        sol2(rem, idx + 1);
        return;
    }
}


void solve()
{
    cin >> v;
    for(int i = 0; i < 9; i++) cin >> a[8 - i];

    memset(dp, -1, sizeof dp);
    int ans = sol(v, 0);
    if (ans == 0){
        cout << -1 << endl;
        return;
    }
    sol2(v, 0);
    for (auto x : res){
        cout << x;
    }
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
