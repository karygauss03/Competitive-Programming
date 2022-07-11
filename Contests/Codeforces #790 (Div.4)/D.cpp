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
int n, m;

bool valid(int r, int c){
    return (r >= 0 && r < n && c >= 0 && c < m);
}


void solve(){
    cin >> n >> m;
    int grid[n][m];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }
    int ans = INT_MIN;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            int cur = grid[i][j];
            int r = i, c = j;
            while (valid(r - 1, c - 1)){
                r--, c--;
                cur += grid[r][c];
            }
            r = i, c = j;
            while (valid(r + 1, c + 1)){
                r++, c++;cur += grid[r][c];

            }
            r = i, c = j;
            while (valid(r - 1, c + 1)){
               r--, c++; cur += grid[r][c];

            }
            r = i, c = j;
            while (valid(r + 1, c - 1)){
               r++, c--; cur += grid[r][c];

            }
            ans = max(cur, ans);
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
