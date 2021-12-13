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


char grid[14][14];
int n;
bitset<30> row, diag_left, diag_right;
int ans;

void solve(int c)
{
   if (c == n){
    ans++;
    return;
   }
   for (int r = 0 ; r < n ; r++){
    if (grid[r][c] != '*' && !row[r] && !diag_left[r - c + n - 1] && !diag_right[r + c]){
        row[r] = diag_left[r - c + n - 1] = diag_right[r + c] = true; // do
        solve(c + 1); // rec
        row[r] = diag_left[r - c + n - 1] = diag_right[r + c] = false; // undo
    }
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
        int tc = 0;
        while(cin >> n && n != 0){
            tc++;
            ans = 0;
            memset(grid, '.', sizeof(grid));
            for (int i = 0 ; i < n ; i++){
                for (int j = 0 ; j < n ; j++){
                    cin >> grid[i][j];
                }
            }
            solve(0);
            cout << "Case "<< tc << ": " << ans << endl;
        }
    }
    return 0;
}
