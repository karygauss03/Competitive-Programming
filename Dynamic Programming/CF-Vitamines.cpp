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
void yes(){
    cout<<"YES\n";
}
void no(){
    cout<<"NO\n";
}



void solve (){
    int n;
    cin >> n;
    int c[n];
    vector<string> s(n);
    ll dp[n + 2][8];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < 8 ; j++){
            dp[i][j] = oo;
        }
    }
    dp[0][0] = 0;
    // dp[i][mask] - is the lowest cost to satisfy the mask using the first i strings
    for (int i = 0 ; i < n ; i++){
        ll c;
        string s;
        cin >> c >> s;
        int string_mask = 0;
        for (int pos = 0 ;pos < 3 ; pos++){
            char cc = 'C' - pos;
            bool have = false;
            for (char x : s){
                if (cc == x){
                    have = true;
                }
            }
            if (have){
                string_mask += (1<<pos); // 2^pos
            }
        }
        for (int mask = 0 ; mask < 8 ; mask++){
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            dp[i + 1][mask | string_mask] = min(dp[i + 1][mask | string_mask], dp[i][mask] + c);
        }
    }

    ll ans = dp[n][7];
    if (ans == oo)
        ans = -1;
    cout << ans << endl;

}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    fastio;
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
