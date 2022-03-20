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

string s;
int n;
int dp[30][1500];



int sol(int pos, int prevSum){
    if (pos == n) return 1;

    if (dp[pos][prevSum] != -1) return dp[pos][prevSum];

    dp[pos][prevSum] = 0;
    int cum = 0;
    for (int i = pos, sum = 0 ; i < n ; i++){
        sum += s[i] - '0';
        if (sum >= prevSum){
            cum += sol(i + 1, sum);
        }
    }
    return dp[pos][prevSum] = cum;
}


void solve()
{
    int k = 1;
    while (cin >> s && s != "bye"){
        n = s.size();
        memset(dp, -1, sizeof dp);

        cout << k << ". " << sol(0,0) << endl;
        k++;
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
