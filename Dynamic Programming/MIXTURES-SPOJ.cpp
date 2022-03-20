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




void solve()
{
    int n;
    while(cin >> n){
        int colors[n + 5];
        for (int i = 1 ; i <= n ; i++){
            cin >> colors[i];
        }
        int dp[n + 5][n + 5];
        memset(dp, INT_MAX, sizeof dp);
        int tmp[n + 5][n + 5];
        memset(tmp, 0, sizeof tmp);
        for (int i = 1 ; i <= n ;i++){
            dp[i][i] = 0;
            tmp[i][i] = colors[i];
        }


        for (int k = 2 ; k <= n ; k++){
            for (int i = 1, j = k ; i <=n , j<=n; i++,j++){
                dp[i][j] = INT_MAX;

                for (int p = i ; p <j ; p++){
                    if ((tmp[i][p] * tmp[p + 1][j]) + dp[i][p] + dp[p+1][j] <dp[i][j]){
                        dp[i][j] = (tmp[i][p] * tmp[p+1][j]) + dp[i][p] + dp[p + 1][j];
                        tmp[i][j] = (tmp[i][p] + tmp[p + 1][j]) % 100;
                    }
                }
            }
        }

        cout << dp[1][n] << endl;

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
