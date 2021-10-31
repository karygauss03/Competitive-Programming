//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl ;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
const int N = 2e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
const int M=(1e9)+7;
const ll inf = (1LL << 61) - 1;
const int INF = 10000;
void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}

bool check(string grid) {

	bool rows =
		(grid[0] != '.' && grid[0] == grid[1] && grid[1] == grid[2]) ||
		(grid[3] != '.' && grid[3] == grid[4] && grid[4] == grid[5]) ||
		(grid[6] != '.' && grid[6] == grid[7] && grid[7] == grid[8]);

	bool columns =
		(grid[0] != '.' && grid[0] == grid[3] && grid[3] == grid[6]) ||
		(grid[1] != '.' && grid[1] == grid[4] && grid[4] == grid[7]) ||
		(grid[2] != '.' && grid[2] == grid[5] && grid[5] == grid[8]);

	bool diagonals =
		(grid[0] != '.' && grid[0] == grid[4] && grid[4] == grid[8]) ||
		(grid[2] != '.' && grid[2] == grid[4] && grid[4] == grid[6]);

	return rows || columns || diagonals;
}

void solve(){
    string grid = "";
    for (int i = 0 ; i < 3 ; i++){
        string x;
        cin >> x;
        grid += x;
    }
    string start_grid = ".........";

    queue<pair<string,bool>> q;
    q.push(mp(start_grid,1));
    string ans = "no";
    while (!q.empty()){
       string cur = q.front().fi;
       bool player = q.front().se;
       q.pop();
       if (cur == grid){
            ans = "yes";
            break;
       }
       if (check(cur)){
            continue;
       }
       for (int i = 0 ; i < 9 ; i++){
            if (cur[i] == '.'){
                cur[i] = (player ? 'X' : 'O');
                if (cur[i] == grid[i]){
                    q.push(mp(cur, 1 ^ player));
                }
                cur[i] = '.';
            }
       }
    }
    cout << ans << endl;
}



int main()
{
    fastio;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
