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

bool check(string str) {
	bool is_full = true;
	for (int i=0;i<str.size();i++) {
		if (str[i] == '.') {
			is_full = false;
			break;
		}
	}
	if (is_full) {
		return true;
	}

	if (str[0] != '.' && str[0] == str[4] && str[4] == str[8]) {
		return true;
	} else if (str[2] != '.' && str[2] == str[4] && str[4] == str[6]) {
		return true;
	} else {
		for (int i=0;i<3;i++) {
			if (str[i*3 + 0] != '.' && str[i*3 + 0] == str[i*3 + 1] && str[i*3 + 1] == str[i*3 + 2]) {
				return true;
			}
		}
		for (int i=0;i<3;i++) {
			if (str[0*3 + i] != '.' && str[0*3 + i] == str[1*3 + i] && str[1*3 + i] == str[2*3 + i]) {
				return true;
			}
		}
	}
	return false;
}


void build(set<string> &valid){
    string start_grid = ".........";
    valid.insert(start_grid);
    queue<pair<string,int>> q;
    q.push(mp(start_grid, 1));
    while(!q.empty()){
        string cur = q.front().fi;
        int player = q.front().se;
        q.pop();
        if (check(cur)){
            continue;
        }
        for (int i = 0 ; i < 9 ;i++){
            if (cur[i] == '.'){
                string tmp = cur;
                if (player == 1){
                    tmp[i] = 'X';
                }
                else {
                    tmp[i] = 'O';
                }
                if (valid.find(tmp) == valid.end()){
                    valid.insert(tmp);
                    q.push(mp(tmp, 1^player));
                }
            }
        }
    }
}


void solve(){
    set<string> valid;
    build(valid);
    char str[10];
    string grid;
    while (1){
        scanf("%s", str);
        grid = str;
        if (grid == "end") {
            break;
        }
        if ((valid.find(grid) != valid.end() && check(grid))){
            cout << "valid\n";
        }
        else {
            cout << "invalid\n";
        }
    }
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
