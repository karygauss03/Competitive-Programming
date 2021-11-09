//KARYGAUSS03
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

const int MOD = (1e9)+7 ;
const int N = 1e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const ll inf = (1LL << 61) - 1;
void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}

const int MAX = 100005;

int n, m, x, y, white[1001];
char grid[1001][1001];
int dp[1001][1001][3];


int solve2(int c, int w, int last){
    if (c == m){
        if (w < x || w > y){
            return 100000000;
        }
        return 0;
    }
    int &ret = dp[c][w][last];
    if (ret != -1){
        return ret;
    }
    int mxWhite = 100000000;
    if (c == 0 || (last == 0 && w + 1 <= y) || (last == 1 && w >= x)){
        mxWhite = n - white[c] + solve2(c + 1, (last == 0) ? w + 1 : 1, 0);
    }
    int mxBlack = 100000000;
    if (c == 0 || (last == 1 && w + 1 <= y) || (last == 0 && w >= x)){
        mxBlack = white[c] + solve2(c + 1, (last == 1) ? w + 1 : 1,  1);
    }
    ret = min(mxBlack, mxWhite);
    return ret;
}


void solve(){
    cin >> n >> m >> x >> y;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
            // . --> White
            // # --> Black
            if (grid[i][j] == '.')
                white[j]++;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << solve2(0, 0, 2);
}


int main()
{
    fastio;
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
