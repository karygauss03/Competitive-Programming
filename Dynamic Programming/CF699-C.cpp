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

int n, a[101];
int dp[102][4];

int solve2(int pos, int prev){
    if (pos == n)
        return 0;
    int &ret = dp[pos][prev];
    if (ret != -1)
        return ret;
    if (a[pos] == 0)
        ret = 1 + solve2(pos + 1, 0);
    else if (a[pos] == 1){
        if (prev == 1){
            ret = 1 + solve2(pos + 1, 0);
        }
        else {
            ret = min(solve2(pos + 1, 1), solve2(pos + 1, 0) + 1);
        }
    }
    else if (a[pos] == 2){
        if (prev == 2){
            ret = 1 + solve2(pos + 1, 0);
        }
        else {
            ret = min(solve2(pos + 1, 2), solve2(pos + 1, 0) + 1);
        }
    }
    else if (a[pos] == 3){
        if (prev == 1)
            ret = min(solve2(pos + 1, 2), solve2(pos + 1, 0) + 1);
        else if (prev == 2){
            ret = min(solve2(pos + 1, 1), 1 + solve2(pos + 1, 0));
        }
        else {
            ret = min((min(solve2(pos + 1, 1), solve2(pos + 1, 2))), solve2(pos + 1, 0) + 1);
        }
    }
    return ret;
}

void solve(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve2(0, 0);
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
