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
#define f first
#define s second
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



void solve()
{
   int n, m;
   cin >> n >> m;
   vector<string> s;
   for (int i = 0 ; i < n ; i++){
    string ss;
    cin >> ss;
    s.pb(ss);
   }
    int ans = INT_MAX;
   for (int i  = 0 ; i < n ; i++){
    int diff;
    for (int j = i + 1 ; j < n ; j++){
        diff = 0;
        for (int k = 0 ; k < m ; k++){
            diff += abs(s[i][k] - s[j][k]);
        }
        ans = min(ans, diff);
    }
   }
   cout << ans << endl;
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
