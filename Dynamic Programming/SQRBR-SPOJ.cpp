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


const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

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

int n, k;
int dp[40][40];
set<int> s;



void solve()
{
    cin >> n >> k;
    s.clear();
    for (int i = 0 ; i < k ; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    memset(dp, 0, sizeof dp);

    for (int i = 1 ; i <= 2*n ; i++){
        for (int j = 0 ; j <= i ; j++){
            if (i == 1){
                if (j == 1){
                    dp[i][j] = 1;
                }
                else dp[i][j] = 0;
            }
            else {
                if (s.find(i) != s.end()){
                    dp[i][j] = (j == 0) ? 0 : dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = (j == 0) ? dp[i - 1][1] : (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
                }
            }
        }
    }

    cout << dp[2*n][0] << endl;

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
